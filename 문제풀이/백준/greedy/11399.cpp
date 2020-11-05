/*
    최소의 경우는 소요 시간이 짧은 순으로 세운 후 계산하면 된다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    //첫 번째는 대기가 없으므로 첫 번째는 바로 더해준다.
    int w = arr[0];
    int answer = arr[0];
    //두 번째부터 대기 시간을 계속 더해가며 결과에 실행시간과 함께 더해준다.
    for (int i = 1; i < n; i++) {
        answer += arr[i] + w;
        w += arr[i];
    }
    cout << answer;
}
