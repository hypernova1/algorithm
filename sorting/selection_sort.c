#include <stdio.h>

#include <stdio.h>
/*
 * 선택 정렬
 *   - 주어진 리스트 중 최소값을 찾아 맨 앞의 요소와 바꾼다.
 *   - 맨 앞의 요소를 제외한 나머지 리스트를 같은 방법으로 교체한다.
 *   - 배열을 다 돌때까지 반복한다.
 * */

int main(void) {
    int arr[] = { 1, 6, 5, 7, 4, 3, 2, 10, 9, 8 };
    int index;
    int temp;
    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < len - 1; i++) {
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
        printf("%d ", arr[i]);
    }
}

