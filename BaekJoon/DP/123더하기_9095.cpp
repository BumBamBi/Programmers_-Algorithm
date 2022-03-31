#include <cstdio>

using namespace std;

/*
dp[1] dp[2] dp[3] 은 기본으로 두고,

4의 경우는
    dp[4]   = dp[3] + "1" (dp[3]의 경우에 3을 더하기)
            = dp[2] + "2" (dp[2]의 경우에 3을 더하기)
            = dp[1] + "3" (dp[1]의 경우에 3을 더하기)

모든 경우는
    dp[x]   = dp[x-1] + "1" (dp[x-1]의 경우에 3을 더하기)
            = dp[x-2] + "2" (dp[x-2]의 경우에 3을 더하기)
            = dp[x-3] + "3" (dp[x-3]의 경우에 3을 더하기)

따라서 dp[n] = dp[n-1] + dp[n-2] +dp[n-3];
 */

int main() {
    int T, n, i, j, cnt;
    int DP[11];

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    scanf("%d", &T);

    for(i = 0; i < T; i++) {
        scanf("%d", &n);
        for(j = 4; j <= n; j++) {
            DP[j] = DP[j-1] + DP[j-2] + DP[j-3];
        }
        printf("%d\n", DP[n]);
    }

    return 0;
}