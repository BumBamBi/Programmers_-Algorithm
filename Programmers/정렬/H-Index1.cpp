#include <string>
#include <vector>
#include <algorithm>

bool condition(int& _a, int& _b){
    // 내림차순 true
    return _a > _b;
}

using namespace std;

int solution(vector<int> citations) {
    
    // 내림차순 정렬
    sort(citations.begin(), citations.end(), condition);

    int answer = 0;
    int citations_cnt = 0;
    int papers_cnt = 0;
    int temp = 0;

    for(int i=0; i<citations.size(); i++){
        // 인용된 횟수
        citations_cnt = citations[i];
        // 인용횐수보다 많이 인용된 논문 수
        papers_cnt = i+1;
        
        // (인용된 횟수 vs 인용횟수보다 많이 인용된 논문 수) 중 작은 값.
        temp = min(citations_cnt, papers_cnt);
        // 선별된 작은 값중에서 가장 큰 값
        answer = max(answer, temp);
    }

    return answer;
}