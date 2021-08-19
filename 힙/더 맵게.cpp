#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(auto e:scoville){
        pq.push(e);
    }
    
    
    int min_1 = 0;
    int min_2 = 0;
    int cnt = 0;
    
    while(pq.top() < K){
        if(pq.size() == 1){
            return -1;
        }
        min_1 = pq.top();
        pq.pop();
        min_2 = pq.top();
        pq.pop();
        
        pq.push(min_1 + min_2*2);
        cnt += 1;
    }
    answer = cnt;
    return answer;
}