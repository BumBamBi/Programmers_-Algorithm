#include <bits/stdc++.h>

using namespace std;

int nodeCnt;
int edgeCnt;

int ans = 0;

// 방문 여부 확인
bool visited[101];

// 인접행렬 그래프 생성
bool table[101][101] = {};

void search(int n){
    // 2. 조건에 만족하므로 ans++, visited true
    ans++;
    visited[n] = true;

    // 1. 조건에 만족해야지만 재귀
    // from -> to만 생각하기
    for(int i=1; i<= nodeCnt; i++){
        // 조건에 충족해야지만 dfs진행
        if(table[n][i] && !visited[i]){
            search(i);
        }
    }
}

int main(){
    cin >> nodeCnt;

    cin >> edgeCnt;

    for(int i=0; i<edgeCnt; i++){
        int s;
        int e;
        cin >> s >> e;
        table[s][e] = true;
        table[e][s] = true;
    }

    search(1);

    cout << ans-1;
}