/**
 * https://www.acmicpc.net/problem/11726
 * */

#include <iostream>

using namespace std;

int dp[1001];

int solution(int n) {
    if (n <= 2) return n;
    if (dp[n]) return dp[n];
    dp[n] = solution(n - 1) + solution(n - 2);
    return dp[n];
}

int main(void) {
    int n;
    cin >> n;
    if (n <= 1) cout << 0;
    else {
        solution(n);
        cout << dp[n];
    }
}