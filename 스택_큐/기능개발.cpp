#include <string>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    stack<int> mystack;
    
    for(int i=progresses.size()-1; i>=0; i--){
        mystack.push((int)ceil((100.0 - progresses[i]) / speeds[i]));
    }
    
    int temp = mystack.top();
    int cnt = 0;
    vector<int> answer;
    
    while(!mystack.empty()){
        if(temp >= mystack.top()){
            mystack.pop();
            cnt += 1;
        }else{
            answer.push_back(cnt);
            cnt = 0;
            temp = mystack.top();
        }
    }
    answer.push_back(cnt);
    
    return answer;
}