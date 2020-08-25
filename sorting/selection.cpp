#include <iostream>
/*
 * 선택 정렬
 *   - 주어진 리스트 중 최소값을 찾아 맨 앞의 요소와 바꾼다.
 *   - 맨 앞의 요소를 제외한 나머지 리스트를 같은 방법으로 교체한다.
 *   - 배열을 다 돌때까지 반복한다.
 * */
using namespace std;

int main() {

    int arr[] = { 3, 2, 5, 4, 1, 10, 9, 7, 8, 6 };
    int temp;
    int index;
    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < len; i++) {
        int min = arr[i];
        for (int j = i + 1; j < len; j++) {
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        if (min == arr[i]) continue;
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
