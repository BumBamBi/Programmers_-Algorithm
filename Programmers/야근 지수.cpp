#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long solution(int n, vector<int> works) {
    
    for(int i=0; i<n; i++){
        int maxNumIndex = max_element(works.begin(), works.end()) - works.begin();
        if(works[maxNumIndex] > 0){
            works[maxNumIndex]--;
        }
    }
    
    long long answer = 0;
    for(auto e:works){
        answer += pow(e,2);
    }
    return answer;
}