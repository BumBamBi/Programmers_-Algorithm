#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<string> my_split(string _s, char _n){
    stringstream ss(_s);
    string temp;
    
    vector<string> result(2);
    
    getline(ss, result[0], _n);
    getline(ss, result[1], _n);
    
    return result;
}

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
    
    vector<set<string>> sets(id_list.size());
    
    for(auto e:report){
        vector<string> v = my_split(e, ' ');
        sets[findIdx(id_list, v[1])].insert(v[0]);
    }
    
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