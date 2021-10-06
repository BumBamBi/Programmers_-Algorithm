#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> _v, bool visited[], int& answer){
    // 모든 노드를 검사
    for(int i=0; i<_v.size(); i++){
        // 이미 확인했던 노드가 아니라면
        if(visited[i] == false){
            // 확인 한 것으로 바꾸고
            visited[i] = true;
            
            // 독립된 노드라면 + 1
            if(count(_v[i].begin(), _v[i].end(), 1) == 1){
                answer += 1;
            }
            // 독립된 노드가 아니라면 다시 확인
            else{
                dfs(_v, visited, answer);
            }
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    
    bool* visited = new bool[n]{false};
    int answer = 1;
    
    dfs(computers, visited, answer);

    return answer;
}