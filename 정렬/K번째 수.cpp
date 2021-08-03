#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int start = 0;
    int end = 0;
    int target = 0;
    int wait_cnt = 1;
    vector<int> temp;
        
    for(int i=0; i<commands.size(); i++){
        start = commands[i][0];
        end = commands[i][1];
        target = commands[i][2];
        
        // 자르기
        for(auto& e:array){
            if((wait_cnt >= start) & (wait_cnt <= end)){
                temp.push_back(e);
            }
            wait_cnt += 1;
        }
        // 정렬
        sort(temp.begin(), temp.end());
        // 값 삽입
        answer.push_back(temp[target-1]);
        // 초기화
        temp.clear();
        wait_cnt = 1;
    }
    
    return answer;
}