#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> mymap;
    
    for(auto& e : completion){
        if(mymap.find(e) == mymap.end()){
            mymap.insert(make_pair(e, 1));
        }else{
            mymap[e] += 1;
        }
    }
    
    string answer = "";
    
    for(auto& e:participant){
        
        mymap[e] -= 1;
        
        if(mymap[e] < 0){
            answer = e;
            break;
        }
    }
    
    return answer;
}