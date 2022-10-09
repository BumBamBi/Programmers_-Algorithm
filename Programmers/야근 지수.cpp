#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    
    priority_queue<int, vector<int>> pq;
    
    for(auto e:works){
        pq.push(e);
    }
    
    for(int i=0; i<n; i++){
        int maxNum = pq.top();
        if(maxNum == 0){
            break;
        }else{
            pq.pop();
            pq.push(maxNum-1);
        }
    }
    
    long long answer = 0;
    while(!pq.empty()){
        int top = pq.top();
        pq.pop();
        answer += (long long)pow(top,2);
    }
    return answer;
}