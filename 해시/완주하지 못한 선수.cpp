#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // unordered map 생성
    // <이름, 횟수> - 횟수는 동명이인 처리를 위함
    unordered_map<string, int> mymap;
    
    // 완주한 사람을 모두 map에 추가
    for(auto& e : completion){
        auto iter = mymap.find(e);
        if(iter == mymap.end()){
            // map에 처음 들어오는 경우, value를 1로 하고 추가
            mymap.insert(make_pair(e,1));
        }else{
            // map에 이미 있는경우, value + 1
            mymap[e] += 1;
        }
    }
    
    string answer = "";
    
    // 모든 참가자의 이름을 확인
    for(auto& e:participant){
        // 해당 참가자 이름의 key값이 가지는 value를 -1
        mymap[e] -= 1;
        
        // 그러다가 완주하지 못한사람(completion에 있으나, participant에 없는 사람) 이 발견되면 종료
        if(mymap[e] < 0){
            answer = e;
            break;
        }
    }
    
    return answer;
}