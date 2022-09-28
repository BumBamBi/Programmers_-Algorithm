#include<vector>
#include<queue>

using namespace std;

int answer = 0;
int n;
int m;
bool visited[101][101];

// 상하좌우
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

bool isAvailable(int y, int x){
    if(x >= 0 && y >= 0 && x < m && y < n){
        if(visited[y][x] == false){
            return true;
        }
    }
    return false;
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    
    bool isReach = false;

    // y,x,이동거리
    queue<pair<pair<int, int>, int>> q;

    // 초기값 큐에 세팅
    q.push(make_pair(make_pair(0, 0),1));
    visited[0][0] = true;

    // bfs 진행
    while(!q.empty()){
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        
        // 종료조건
        if(cur.first.first == (n-1) && cur.first.second == (m-1)){
            isReach = true;
            answer = cur.second;
            break;
        }
        
        for(int i=0; i<4; i++){
            int yy = cur.first.first + dy[i];
            int xx = cur.first.second + dx[i];
            
            if(isAvailable(yy, xx)){
                if(maps[yy][xx] == 1){
                    q.push(make_pair(make_pair(yy, xx), cur.second+1));
                    visited[yy][xx] = true;
                }
            }
        }
    }
    
    if(isReach){
        
    }else{
        answer = -1;
    }
    
    return answer;
}