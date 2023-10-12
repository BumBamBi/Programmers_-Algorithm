#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    map<string, int> m;
    
    for(auto e:participant){
        if(m.find(e) != m.end()){
            int cnt = m[e];
            m.erase(e);
            m.insert({e, cnt+1});
        }
        else{
            m.insert({e, 1});
        }
    }
    
    for(auto e:completion){
        int cnt = m[e];
        m.erase(e);
        if(cnt != 1){
            m.insert({e, cnt-1});
        }
    }

    return m.begin()->first;
}