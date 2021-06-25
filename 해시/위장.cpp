#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string, int> mymap;
    
    for(int i = 0; i < clothes.size(); i++){
        // <부위, 개수>로 구성.
        mymap[clothes[i][1]] += 1;
    }
    
    int answer = 1;
    
    for(int i = 0; i < clothes.size(); i++){
        // 
        if(mymap.find(clothes[i][1]) != mymap.end()){
            answer *= mymap[clothes[i][1]]+1;
            mymap.erase(clothes[i][1]);
        }
    }
    answer -= 1;
    return answer;
}