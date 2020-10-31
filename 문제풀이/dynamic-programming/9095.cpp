/**
 * https://www.acmicpc.net/problem/9095
 * 
 * n이 4인 경우까지만 보니 n-1 부터 1까지의 개수를 쭉 결과를 더해야 하는 줄 알아서 틀렸다.
 * 최대한 많이 테스트 해 본 후 예외가 있는지 확인해봐야겠다.
*/

#include <iostream>

using namespace std;

int dp[10];

int solution(int n) {
    if (n <= 2) return n;
    if (n == 3) return 4;
    if (dp[n]) return dp[n];
    dp[n] = solution(n - 1) + solution(n - 2) + solution(n - 3);
    return dp[n];

}

int main(void) {
    cout << wrong(4);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << solution(arr[i]) << endl;
    }
}
