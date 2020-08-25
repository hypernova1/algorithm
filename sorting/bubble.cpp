#include <iostream>
/*
 * 버블정렬
 *   - 이웃된 요소끼리 비교를 하여 앞의 요소가 더 크면 뒤의 요소와 위치를 바꾼다.
 *   - 마지막 요소까지 반복하여 자리를 바꿔 나간다.
 *   - 한 바퀴를 돌게 되면 가장 큰 숫자가 맨 뒤로 가게 되고 1을 뺀 길이만큼 다시 루프를 돌며 위치를 바꾼다.
 *   - 반복
 * */
using namespace std;

int main() {

    int arr[] = { 1, 6, 5, 7, 4, 3, 2, 10, 9, 8 };
    int len = sizeof(arr) / sizeof(int);
    int temp;
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < len - i; j++) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
