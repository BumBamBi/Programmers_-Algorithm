#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    
    while(n > 0){
        
        int maxNum = *max_element(works.begin(), works.end());
    
        if(maxNum == 0){
            break;
        }

        works.erase(find(works.begin(), works.end(), maxNum));
        
        int maxNum2 = *max_element(works.begin(), works.end());
        
        int diff = maxNum - maxNum2;
        
        cout << maxNum << " " << maxNum2 << endl;
        
        break;
        
        if(diff > 0 && diff <= n){
            works.push_back(maxNum-diff);
            n -= diff;
        }else{
            works.push_back(maxNum-1);
            n--;
        }

    }
    
    long long ans = 0;
    for(auto e:works){
        ans += pow(e,2);
    }
    
    
    return ans;
}