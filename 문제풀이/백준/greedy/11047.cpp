/**
 * https://www.acmicpc.net/problem/11047
 * 
 * 동전 0
 *  가장 적게 동전을 써야하기 때문에 큰 동전부터 차례대로 빼나간다.
 * */

#include <cstdio>

using namespace std;

int main(void) {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] <= m) {
            int count = m / arr[i];
            answer += count;
            m -= arr[i] * count;
        }
        if (m == 0) break;
    }
    printf("%d", answer);
}
