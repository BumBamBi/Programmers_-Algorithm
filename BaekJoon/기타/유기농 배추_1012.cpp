#include <bits/stdc++.h>

using namespace std;

int N;
int M;
int K;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool visited[51][51] = {};
bool table[51][51] = {};


void dfs(int i, int j){

    visited[i][j] = true;

    for(int d=0; d<4; d++){
        // 인덱스 초과가 안난다면
        if(i+dy[d] >= 0 && i+dy[d] < N && j+dx[d] >= 0 && j+dx[d] < M){
            // 해당 값이 1이라면
            if((table[i+dy[d]][j+dx[d]] == 1) && visited[i+dy[d]][j+dx[d]] == false){
                dfs(i+dy[d], j+dx[d]);
            }
        }
    }
}

int main(){
    int T;
    cin >> T;
    
    vector<int> ans;

    for(int curTC = 0; curTC<T; curTC++){

        // TestCase마다 table과 visited 초기화
        memset(table, 0, sizeof(table));
        memset(visited, false, sizeof(visited));

        // 이번 TestCase에 사용될 warmCnt
        int warmCnt = 0;

        // 입력 받기
        cin >> M >> N >> K;
        
        // 배추의 x, y 좌표 받아오기
        for(int inputLoop=0; inputLoop<K; inputLoop++){
            int i, j;
            cin >> j >> i;
            table[i][j] = 1;
        }

        // 입력 끝 -------------------------------------

        // 모든 좌표를 탐색하면서
        // 방문하지 않고, 배추가 있는(1) 곳이 있다면
        // 벌레를 한마리 더 추가하면서 해당 구역 dfs
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!visited[i][j] && (table[i][j] == 1)){
                    warmCnt++;
                    dfs(i, j);
                }
            }
        }

        // 정답 모으기
        ans.push_back(warmCnt);
    }

    // 출력
    for(auto e:ans){
        cout << e << endl;
    }
}