#include <string>
#include <vector>
#include <map>

using namespace std;

int answer = 0;
map<string, int> mymap;

bool isInMap(string s){
    for(auto e:mymap){
        if(e.first == s){
            return true;
        }
    }
    return false;
}

void addWegiht(){
    for(auto e:mymap){
        mymap[e.first]++;
    }
}

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
        answer = cities.size()*5;
    }else{
        for(auto e:cities){
            addWegiht();
            if(mymap.size() < cacheSize){
                if(isInMap(e)){
                    mymap[e] = 0;
                    answer++;
                }else{
                    mymap.insert({e,0});
                    answer += 5;
                }
            }else{
                if(isInMap(e)){
                    mymap[e] = 0;
                    answer++;
                }else{
                    delMap();
                    mymap.insert({e,0});
                    answer += 5;
                }
            }
        }
    }
    return answer;
}
