#include <iostream>
#include <queue>

using namespace std;
#define MAX 102

int n, target_x, target_y, m;

int arr[MAX][MAX];  // 배열 그래프
int visited[MAX];   // 인덱스를 1~100 까지 사용하고, 해당 목표까지 도달하는데 걸리는 최소 횟수를 저장
queue<int> q;       // bfs를 위한 queue

void bfs(int k) {
    q.push(k);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        // 현재 노드(사람)과 연결되어있는 사람 중에서, 이태까지 한번도 거치지 않은 노드(사람)이라면 queue에 삽입
        for(auto i = 1; i <= n; i ++) {
            if(arr[cur][i] !=0 && !visited[i]) {
                q.push(i);
                visited[i] = visited[cur]+1; 
            }
        }
    }
}

int main() {

    cin >> n;
    cin >> target_x >> target_y;
    cin >> m;

    // 배열 그래프 생성
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    // 탐색을 시작할 노드(사람)
    bfs(target_x);

    if(visited[target_y] == 0){
        cout << -1;
    }else{
        cout << visited[target_y];
    }

    return 0;
}