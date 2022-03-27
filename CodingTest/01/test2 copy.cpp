#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int target = 1;
int lastTarget;
int answer = 0;

class Node{
public:
    int y;
    int x;
    int cnt;

    Node(int _y, int _x, int _cnt){
        y = _y;
        x = _x;
        cnt = _cnt;
    }
};

queue<Node> q;

void addNodes(int cy, int cx, int cnt, int SIZE){
    // 사방 탐색을 통해 주변 확인
    for (int i = 0; i < 4; i++){
        
        // 주변의 인덱스 접근
        int di = cy + dy[i];
        int dj = cx + dx[i];

        // 범위 초과시 반대편으로 이동
        // ---------------------------------
        if(di < 0){
            di = SIZE - 1;
        }else if(di >= SIZE){
            di = 0;
        }
        
        if(dj < 0){
            dj = SIZE - 1;
        }else if(dj >= SIZE){
            dj = 0;
        }
        // ---------------------------------
        q.push(Node(di, dj, cnt + 1));
    }
}

int solution(int n, vector<vector<int>> board) {
    lastTarget = (n * n)+1;
    q.push(Node(0, 0, 0));

    while(!q.empty()){
        // 가장 앞 노드 빼오기
        Node cur = q.front();
        q.pop();

        // 모든 숫자를 지웠다면
        if(target == lastTarget){
            break;
        }

        // 현재 값이 타겟이면
        if(board[cur.y][cur.x] == target){
            // 지금까지 움직인 비용 추가
            answer += cur.cnt+1;
            // 다음 타겟 설정
            target++;

            // 남은 큐 싹 비우기
            int qSize = q.size();
            for (int i = 0; i < qSize; i++){
                q.pop();
            }

            // 주변 사방 노드를 추가하여 다시 시작
            addNodes(cur.y, cur.x, 0, n);
        }else{
            // 주변 사방 노드를 카운트하면서 추가
            addNodes(cur.y, cur.x, cur.cnt, n);
        }
    }

    return answer;
}

int main(){
    vector<vector<int>> input = {{3, 5, 6}, {9, 2, 7}, {4, 1, 8}};
    cout << "\nans : " << solution(3, input);
}