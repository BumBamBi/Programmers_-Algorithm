#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 큰 cnt를 확인하기 위한 변수
int max_cnt = 0;

void DFS(string start, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer, vector<string>& temp, int cnt) {
    
    // 임시의 temp에 start를 추가
    temp.push_back(start);
    
    // 가장 큰 cnt를 확인하기 위함
    if (max_cnt < cnt) {
        // max_cnt를 초기화 하고
        max_cnt = cnt;
        // 현재까지의 경로를 answer로 두기
        answer = temp;
    }

    // 티켓 개수만큼 반복 (알파벳 정렬된상태)
    for (int i = 0; i < tickets.size(); i++) {
        // start가 동일한 노드? 이면서 + 방문하지 않은 경우
        if (start == tickets[i][0] && !visit[i]) {
            // 방문 true
            visit[i] = true;
            // 도착점을 시작점으로 하고, 횟수 + 1 하고, 다시 반복
            DFS(tickets[i][1], tickets, visit, answer, temp, cnt + 1);
            // 함수가 끝나면서 돌아갈 때 방문을 취소한다
            visit[i] = false;
        }
    }
    // 방문이 끝나면서 temp도 visit처럼 일부 초기화를 위한 것
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    
    int cnt = 0;
    
    // 벡터 answer, temp 생성
    vector<string> answer, temp;
    
    // tickets의 개수만큼 visit 생성 후 False로 설정
    vector<bool> visit(tickets.size(), false);
    
    // tickets을 알파벳 순서로 정렬
    sort(tickets.begin(), tickets.end());
    
    // ICN에서 시작하는 반복함수 시작
    DFS("ICN", tickets, visit, answer, temp, cnt);
    
    return answer;
}