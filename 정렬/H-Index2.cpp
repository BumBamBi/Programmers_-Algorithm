#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool condition(int _a, int _b){
    return _a > _b;
}

int solution(vector<int> citations) {
    
    // 내림차순 정렬
    sort(citations.begin(), citations.end(), condition);

    int citations_cnt = 0;
    int paper_citations_cnt = 0;
    int temp_h_index = 0;
    int h_index = 0;

    for(int i=0; i<citations.size(); i++){
        // 논문의 인용 횟수
        citations_cnt = citations[i];
        // 인용 횟수 이상 인용된 논문 개수(index로 판단)
        paper_citations_cnt = i+1;
        
        // (인용된 횟수 vs 인용횟수보다 많이 인용된 논문 수) 중 작은 값.
        // 매개변수가 [7] 이면, 7번 이상 인용된 논문이 1편 이상이므로 h-index는 1.
        // 즉, 1 이상에 7이 포함되므로 작은 수를 선택. 
        temp_h_index = min(citations_cnt, paper_citations_cnt);
        // 선별된 작은 값중에서 가장 큰 값 (h-index의 최대값)
        h_index = max(h_index, temp_h_index);
    }

    return h_index;
}