#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int std = 0;
    int cnt = 0;
    
    // prices 만큼 반복
    for(int i=0; i<prices.size(); i++){
        std = prices[i];
        // 선택한 요소 다음 요소부터 반복
        for(int j=i+1; j<prices.size(); j++){
            // 가격이 떨어진다면
            if(std > prices[j]){
                cnt += 1;
                break;
            }
            // 가격이 떨이지지 않는다면
            else{
                cnt += 1;
            }
        }
        // 한 요소에 대한 결과 삽입 후 초기화
        answer.push_back(cnt);
        cnt = 0;
    }
    
    return answer;
}