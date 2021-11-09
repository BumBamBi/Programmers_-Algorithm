#include <string>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    stack<int> mystack;
    
    // 필요한 날짜만큼 stack에 역으로 저장.(가장 마지막 기능이 먼저 push)
    for(int i=progresses.size()-1; i>=0; i--){
        // (남은 작업진도 / 속도) 올림한 값
        // (100-93)/3 = 2.xx 이라 3일이 걸리지만, int형은 내림 하므로 2일이 된다.
        // double형으로 하여 2.xx 로 바꾸고 올림하고 int형으로 재 변경.
        mystack.push((int)ceil((100.0 - progresses[i]) / speeds[i]));
    }
    
    // 정답을 넣을 벡터
    vector<int> answer;
    // 스택의 최초 top값을 저장할 변수
    int before_top = mystack.top();
    // 한번에 pop한 수를 카운트하는 변수
    int cnt = 0;
    
    // 스택에 있는값을 전부 pop
    while(!mystack.empty()){
        if(before_top >= mystack.top()){
            // 차례로 pop하되, top에 있는 값보다 작은 값들은 연속으로 pop
            mystack.pop();
            cnt += 1;
        }else{
            // 한번에 pop한 수를 answer에 push하고, before_top변수 초기화
            answer.push_back(cnt);
            cnt = 0;
            before_top = mystack.top();
        }
    }
    answer.push_back(cnt);
    
    return answer;
}