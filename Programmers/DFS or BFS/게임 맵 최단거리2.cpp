#include <bits/stdc++.h>

using namespace std;

int n, m;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visited[101][101];
bool isReach = false;

bool isVaild(int y, int x){
    if(y >= 0 && x >= 0 && y <= n-1 && x <= m-1){
        return true;
    }else{
        return false;
    }
}

int solution(vector<vector<int>> maps)
{
    int ans = 0;
    
    n = maps.size();
    m = maps[0].size();
    
    queue<pair<pair<int, int>, int>> q;
    
    q.push(make_pair(make_pair(0,0), 1));
    
    while(!q.empty()){
        int nn = q.front().first.first;
        int mm = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(nn == n-1 && mm == m-1){
            ans = cnt;
            isReach = true;
            break;
        }else{
            for(int i=0;i<4; i++){
                int y = nn + dy[i];
                int x = mm + dx[i];
                if(isVaild(y, x)){
                    if(maps[y][x] == 1 && visited[y][x] == false){
                        q.push(make_pair(make_pair(y, x), cnt+1));
                        visited[y][x] = true;
                    }
                }
            }
        }
    }
    
    if(isReach){
        return ans;
    }else{
        return -1;
    }
}