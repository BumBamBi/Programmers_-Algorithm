#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <math.h>

using namespace std;

int calcTime(string h1, string m1, string h2, string m2){
    int ih1 = stoi(h1);
    int im1 = stoi(m1);
    int ih2 = stoi(h2);
    int im2 = stoi(m2);
    
    return (ih2-ih1)*60 + (im2-im1);
}

int calcFee(int t, vector<int> fees){
    float time = t;
    if(time < fees[0]){
        return fees[1];
    }else{
        return ceil((time-fees[0])/fees[2]) * fees[3] + fees[1];
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    
    // 차번호, 차 데이터
    map<string, vector<string>> park;
    // 차번호, 시간
    map<string, int> carTimeTable;
    
    for(auto e:records){
        stringstream ss(e);
        string time[2];
        string carNum;
        string INOUT;
        vector<string> datas;
        getline(ss, time[0], ':');
        getline(ss, time[1], ' ');
        getline(ss, carNum, ' ');
        getline(ss, INOUT, ' ');
        datas.push_back(time[0]);
        datas.push_back(time[1]);
        datas.push_back(carNum);
        datas.push_back(INOUT);
        
        auto iter = park.find(carNum);
        // 주차장에 이미 있으면
        if(iter != park.end()){
            // 시간 계산
            int time = calcTime(iter->second[0],iter->second[1], datas[0], datas[1]);

            // 시간 저장
            auto iter2 = carTimeTable.find(carNum);
            // 차량의 시간 기록이 이미 있다면 더하기
            if(iter2 != carTimeTable.end()){
                iter2->second += time;
            }
            // 차량의 시간 기록이 없으면 추가하기
            else{
                carTimeTable.insert({carNum, time});
            }        
            // 주차장에서 출차시키기
            park.erase(carNum);
        }
        // 주차장에 없으면 추가
        else{
            park.insert({carNum, datas});
        }
    }
    
    // 시간 끝났는데 남아있는 차들
    for(auto e:park){
        // 시간 계산
        int time = calcTime(e.second[0],e.second[1], "23", "59");
        
        // 시간 저장
        auto iter = carTimeTable.find(e.first);
        // 차량의 시간 기록이 이미 있다면 더하기
        if(iter != carTimeTable.end()){
            iter->second += time;
        }
        // 차량의 시간 기록이 없으면 추가하기
        else{
            carTimeTable.insert({e.first, time});
        }
    }
    
    vector<int> answer;
    
    for(auto e:carTimeTable){
        answer.push_back(calcFee(e.second, fees));
    }
    
    return answer;
}