#include <iostream>

/*
 * 삽입정렬
 *   - 루프를 돌면서 선택된 요소가 바로 이전 요소보다 작다면 왼쪽으로 보낸다.
 *   - 선택된 요소보다 이전 요소가 작을 때까지 반복한다.
 *
 *   * O(N^2)의 복잡도를 갖는 정렬 알고리즘(선택, 버블, 삽입) 중 가장 효율적이다.
 *     - 선택된 요소보다 왼쪽 요소가 작다면 이미 정렬되어 있는 상태이기 때문
 * */
using namespace std;

int main() {

    int arr[10] = { 2, 9, 1, 10, 5, 6, 8, 7, 3, 4 };
    int j, temp;
    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < len - 1; i++) {
        j = i;
        while (arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j--;
        }
    }

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
