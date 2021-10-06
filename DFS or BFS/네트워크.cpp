#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int i, vector<vector<int>> computers, bool visited[]){
    if(visited[i] == true){
        return 0;
    }else{
        visited[i] = true;
        
        // 현재 노드와 연결 된 노드가 더 있는지 찾아보기
        for(int j=0; j<computers[i].size(); j++){
            // 연결 된 노드가 있다면
            if(computers[i][j] == 1){
                dfs(j, computers, visited);
            }
        }
        return 1;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool* visited = new bool[n]{false};
    
    // 모든 노드에 접근
    for(int i=0; i<n; i++){
        // 방문하지 않았던 노드라면 dfs를 거쳐 추가
        if(visited[i] == false){
            answer += dfs(i, computers, visited);
        }
    }
    
    return answer;
}