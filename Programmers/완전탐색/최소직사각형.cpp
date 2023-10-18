#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {    
    int rowMax = 0;
    int colMax = 0;
    
    for(auto e:sizes){
        // 세로가 더 길면
        if(e[0] < e[1]){
            // 가로 최대값 비교
            if(rowMax < e[1]){
                rowMax = e[1];
            }
            // 세로 최대값 비교
            if(colMax < e[0]){
                colMax = e[0];
            }
        }
        // 가로가 더 길면
        else{
            // 가로 최대값 비교
            if(rowMax < e[0]){
                rowMax = e[0];
            }
            // 세로 최대값 비교
            if(colMax < e[1]){
                colMax = e[1];
            }
        }
    }
    return colMax*rowMax;
}