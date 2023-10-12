#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    map<int, int> mymap;
    
    for(auto e:nums){
        // 값이 있으면
        if(mymap.find(e) != mymap.end()){
            int cnt = mymap[e];
            mymap.erase(e);
            mymap.insert({e, cnt+1});
        }
        // 없으면 추가
        else{
            mymap.insert({e, 1});
        }
    }    
    return min((int)mymap.size(), (int)nums.size()/2);
}