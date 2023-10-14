#include<bits/stdc++.h>

using namespace std;

bool conditions(int a, int b){
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string solution(vector<int> numbers) {
    
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), conditions);
    
    for(auto e:numbers){
        answer += to_string(e);
    }
    
    
    if(answer[0] == '0'){
        answer = '0';
    }
    
    return answer;
}