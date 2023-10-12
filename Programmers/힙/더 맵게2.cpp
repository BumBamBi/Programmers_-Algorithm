#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto e:scoville){
        pq.push(e);
    }
    
    int ans = 0;
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        if(K <= first){
            break;
        }else{
            int second = pq.top();
            pq.pop();
            pq.push(first + second*2);
            ans += 1;
        }
    }
    
    if(pq.top() < K){
        ans = -1;
    }
    
    return ans;
}