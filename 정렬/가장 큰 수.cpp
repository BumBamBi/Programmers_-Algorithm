#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool condition(int& _a, int& _b){
    string sa = to_string(_a);
    string sb = to_string(_b);

    string strcat1 = sa + sb;
    string strcat2 = sb + sa;

    return stoi(strcat1) > stoi(strcat2);
}

string solution(vector<int> numbers) {
    vector<int> my;
    for(auto e:numbers){
        my.push_back(e);
    }

    sort(my.begin(), my.end(), condition);

    string answer;

    // answer에 값 입력
    for(auto e:my){
        for(int i=0; i<to_string(e).length(); i++){
            answer += to_string(e)[i];
        }
    }
    
    if(answer[0] == '0'){
        answer = "0";
    }
    
    return answer;
}