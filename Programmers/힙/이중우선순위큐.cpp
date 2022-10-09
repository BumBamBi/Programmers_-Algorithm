#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    
    priority_queue<int, vector<int>> pq;
    int lazy_minus_cnt = 0;
    
    for(auto e:operations){
        // 숫자
        int num = stoi(e.substr(2,e.size()-2));
        
        // 삽입
        if(e[0] == 'I'){
            pq.push(num);
        }
        // 삭제
        else{
            if(pq.size() > 0){
                // 최소값빼는 경우라면
                if(e[2] == '-'){
                    // 나중에 일괄 삭제
                    lazy_minus_cnt++;
                }else{
                    pq.pop();
                }
            }else{
                continue;
            }
        }
    }

    vector<int> answer;
    
    // 큐가 비어있다면
    if(pq.size() <= lazy_minus_cnt){
        answer.push_back(0);
        answer.push_back(0);
    }
    // 비어있지 않다면
    else{
        int size = pq.size();
        int maxNum = pq.top();
        int minNum = 0;

        // 최소값 삭제 한값 직전까지 pop 한 값이 최소 값임
        for(int i=0; i<size-lazy_minus_cnt; i++){
            minNum = pq.top();
            pq.pop();
        }
        
        answer.push_back(maxNum);
        answer.push_back(minNum);
    }
    
    
    return answer;
}