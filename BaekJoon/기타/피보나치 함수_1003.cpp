#include<iostream>
#include<vector>

using namespace std;

int main(){

    // 입력 --------------------------
    int T;
    cin >> T;

    for (int i = 0; i < T; i++){
        int N;
        cin >> N;


        // fibo(i) = fibo(i-1) + fibo(i-2)
        // 그러나 0과 1은 각 0 과 1 로 초기화 필요
        vector<pair<int, int>> dp(N+1, make_pair(0,0));
        dp[0].first = 1;    // 0 : 1
        dp[1].second = 1;   // 1: 1

        for (int j = 2; j <= N; j++){
            dp[j].first = dp[j - 1].first + dp[j - 2].first;
            dp[j].second = dp[j - 1].second + dp[j - 2].second;
        }

        cout << dp[N].first << " " << dp[N].second << endl;
    }
    // -------------------------------

    return 0;
}