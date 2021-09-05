#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> my_split(string _s, char _n){
    stringstream ss(_s);
    string temp;

    int flag = 0;
    vector<string> result;
    while(getline(ss, temp, _n)){
        result.push_back(temp);
    }
    return result;
}

vector<string> solution(vector<string> record) {

    // 1. 문자열 잘라서 이차원 벡터에 대입
    vector<vector<string>> vv;
    
    for(int i=0; i<record.size(); i++){
        vv.push_back(my_split(record[i], ' '));
    }
    
    // 2. unorderd_map을 이용하여 Enter, Change 시 변경
    unordered_map<string, string> umap;
    
    for(auto e:vv){
        if(e[0] == "Enter"){
            auto iter = umap.find(e[1]);
            if(iter == umap.end()){
                // uid가 없으면(처음입장) map에 추가
                umap.insert(make_pair(e[1], e[2]));
            }else{
                // uid가 있으면(아이디 바꿔서 들어올 수도 있음) map의 value 변경
                iter->second = e[2];
            }
        }else if (e[0] == "Change"){
            // map에 있을테니 value 변경
            auto iter = umap.find(e[1]);
            iter->second = e[2];
        }
    }
    
    // 3. 출력
    vector<string> v;
    for(auto e:vv){
        string temp = "";
        
        if(e[0] == "Enter"){
            auto iter = umap.find(e[1]);
            temp = iter->second + "님이 들어왔습니다.";
            v.push_back(temp);
        }else if(e[0] == "Leave"){
            auto iter = umap.find(e[1]);
            temp = iter->second + "님이 나갔습니다.";
            v.push_back(temp);
        }
    }
    return v;
}