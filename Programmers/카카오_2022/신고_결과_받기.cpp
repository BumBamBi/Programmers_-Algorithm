#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <set>

using namespace std;

int findIdx(vector<string> id_list, string s){
    
    for(int i=0; i<id_list.size(); i++){
        if(s == id_list[i]){
            return i;
        }
    }
    cout << "error";
    return -1;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    vector<int> answer(id_list.size());
    
    // 신고받은 사람 set에, 신고한 사람의 이름을 추가할 set생성
    vector<set<string>> sets(id_list.size());
    
    // 신고받은 사람 set에, 신고한 사람의 이름을 추가
    for(auto e:report){
        vector<string> v(2);
        stringstream ss(e);
        string a, b;
        ss >> a >> b;
        v[0] = a; v[1] = b;
        sets[findIdx(id_list, v[1])].insert(v[0]);
    }
    
    // set의 크기가 k이상인 것의 원소들을 빼내면서 카운트
    for(int i=0; i<sets.size(); i++){
        if(sets[i].size() >= k){
            // 신고시킨 사람 알람
            for(auto e:sets[i]){
                answer[findIdx(id_list, e)]++;
            }
        }
    }
    return answer;
}