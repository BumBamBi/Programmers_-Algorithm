#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    int a[3][10] = {{1, 2, 3, 4, 5},
                    {2, 1, 2, 3, 2, 4, 2, 5},
                    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    
    int ans[3] = {0,0,0};
        
    for(int i=0; i<answers.size(); i++){
        if(a[0][i%5] == answers[i]){
            ans[0] += 1;
        }
        if(a[1][i%8] == answers[i]){
            ans[1] += 1;
        }
        if(a[2][i%10] == answers[i]){
            ans[2] += 1;
        }
    }
    
    vector<int> answer;
    
    if((ans[0] >= ans[1]) & (ans[0] >= ans[2])){
        answer.push_back(1);
    }
    if((ans[1] >= ans[0]) & (ans[1] >= ans[2])){
        answer.push_back(2);
    }
    if((ans[2] >= ans[1]) & (ans[2] >= ans[0])){
        answer.push_back(3);
    }
       
    
    return answer;
}