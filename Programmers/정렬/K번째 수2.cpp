#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    
    for(auto e:commands){
        vector<int> v(array.begin()+e[0]-1, array.begin()+e[1]);
        
        sort(v.begin(), v.end());
        
        answer.push_back(v[e[2]-1]);
    }
    
    
    return answer;
}