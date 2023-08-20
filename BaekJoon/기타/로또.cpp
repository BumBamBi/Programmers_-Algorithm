#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int k;
vector<int> v;
int ans[6];

void dfs(int start, int depth){
    // 6자리 되면 출력
    if(depth == 6){
        for (int i = 0; i < 6;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }else{
        // ans에 새로운값 하나씩 넣으면서 6자리까지인 dfs트리 모든 조합 만들기
        for (int i = start; i < k; i++) {
            ans[depth] = v[i];
            dfs(i + 1, depth+1);
        }
    }
}

int main(){

    // 최초 입력
    cin >> k;

    while(k != 0){
        // 숫자 입력
        for (int i = 0; i < k; i++){
            int input;
            cin >> input;
            v.push_back(input);
        }
        // 함수 호출
        dfs(0, 0);

        // 초기화
        v.clear();
        
        // 줄바꿈 출력
        cout << endl;
        
        // k 초기화
        cin >> k;
    }

    return 0;
}