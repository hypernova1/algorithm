/*
    풀이
        밧줄을이 버틸 수 있는 중량을 내림차순으로 정렬하고 제일 큰 밧줄을 max로 놓는다. (문제 풀이는 내림 차순으로 정렬하여 제일 마지막부터 탐색하였다)
        밧줄의 개수를 늘려가며 해당 밧줄이 버티는 중량 * 밧줄 개수를 max와 비교하여 max보다 크면 그 중량을 max로 설정한다.
    예
        10 15 10 -> 가장 큰 밧줄이 15이지만 총 3개를 이용하여 들면 30을 들 수 있다.
        1 15 3   -> 가장 큰 밧줄이 15이고 3개를 모두 쓰더라도 1 * 3이므로 하나로 15짜리 하나로 들어야 최대 중량이다.

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
    int max = arr[n - 1];
    int count = 2;
    for (int i = n - 2; i >= 0; i--) {
        int s = arr[i] * count++;
        if (max < s) {
            max = s;
        }
    }
    cout << max;
}
