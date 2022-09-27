#include <string>
#include <vector>
#include <map>

using namespace std;

int answer = 0;
map<string, int> mymap;

// map에 존재여부 확인
bool isInMap(string s){
    for(auto e:mymap){
        if(e.first == s){
            return true;
        }
    }
    return false;
}

// map의 시간 증가
void addTime(){
    for(auto e:mymap){
        mymap[e.first]++;
    }
}

// map의 가장 오래된 것 삭제
void delMap(){
    int maxNum = -1;
    string s = "";
    
    for(auto& e:mymap){
        if(maxNum < e.second){
            maxNum = e.second;
            s = e.first;
        }        
    }
    
    if(maxNum != -1){
        mymap.erase(s);
    }
}

int solution(int cacheSize, vector<string> cities) {
    
    if(cacheSize == 0){
        // 캐시가 0인 경우 
        answer = cities.size()*5;
    }else{
        for(auto e:cities){
            // 소문자로 일괄 변환
            string curString = "";
            for(int i=0; i<e.length(); i++){
                curString += tolower(e[i]);
            }
            
            // hit
            if(isInMap(curString)){
                addTime();
                mymap[curString] = 0; // 없으면 추가, 있으면 0으로 초기화
                answer++;
            }
            // miss
            else{
                if(mymap.size() < cacheSize){
                    addTime();
                    mymap.insert({curString,0});
                    answer += 5;
                }else{
                    delMap();
                    addTime();
                    mymap.insert({curString,0});
                    answer += 5;
                }
            }
        }
    }
    return answer;
}
