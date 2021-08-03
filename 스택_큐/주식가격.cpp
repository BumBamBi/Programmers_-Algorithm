#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int std = 0;
    int cnt = 0;
    
    for(int i=0; i<prices.size(); i++){
        std = prices[i];
        for(int j=i+1; j<prices.size(); j++){
            if(std <= prices[j]){
                cnt += 1;
            }else{
                cnt += 1;
                break;
            }
        }
        answer.push_back(cnt);
        cnt = 0;
    }
    
    return answer;
}