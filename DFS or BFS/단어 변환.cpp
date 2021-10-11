// dfs 시 stack을 이용하는 경우

#include <string>
#include <vector>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

bool canChange(string std, string other){
    int diff = 0;
    
    for(int i=0; i<std.size(); i++){
        if(std[i] != other[i]){
            diff += 1;
        }
    }
    
    if(diff == 1){
        return true;
    }else{
        return false;
    }
}

void dfs(string begin, string target, vector<string> words){
    set<string> visited;
    stack<string> mystack;
    vector<int> count;
    
    mystack.push(begin);
    int cnt = -1;
    
    while(mystack.empty() != true){
        string cur_node = mystack.top();
        mystack.pop();
        cnt += 1;
        if(auto iter = visited.find(cur_node) == visited.end()){
            visited.insert(cur_node);
            for(int i=0; i<words.size(); i++){
                if(visited.find(words[i]) == visited.end() && canChange(cur_node, words[i])){
                    mystack.push(words[i]);
                    // 끝에 도착하면 그만 탐색하도록..
                    /*if(words.top() == target){
                        count.push_back(cnt);
                        cnt = 0;
                    }
                    */
                }
            }
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    dfs(begin, target, words);
    return answer;
}