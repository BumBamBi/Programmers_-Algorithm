#include <bits/stdc++.h>

using namespace std;

int TARGET;
int ans;

void dfs(vector<int> v, int sum, int cnt){
    if(v.size()-1 == cnt){
        if(sum == TARGET){
            ans++;
        }
        return;
    }else{
        dfs(v,sum+v[cnt+1], cnt+1);
        dfs(v,sum-v[cnt+1], cnt+1);
    }
}

int solution(vector<int> numbers, int target) {
    
    TARGET = target;
    
    // 벡터, 현재값, 카운트
    dfs(numbers, numbers[0], 0);
    dfs(numbers, -numbers[0], 0);
    
    
    return ans;
}