#include <iostream>
#include <vector>

using namespace std;

void func(int N, int M, vector<int> visited, int start){
    // 마지막 출력단계
    if(visited.size() == M){
        for(auto e:visited){
            cout << e << ' ';
        }
        cout << '\n';
    }else{
        // 마지막 입력값~N까지 반복해서 재귀
        for(int i=start; i<=N; i++){
            visited.push_back(i);
            func(N, M, visited, visited.back());
            visited.pop_back();
        }
    }
    return;
}

int main(){

    // 입력 --------------------------
    int N, M;
    cin >> N >> M;
    // -------------------------------

    vector<int> visited;

    func(N, M, visited, 1);

    return 0;
}