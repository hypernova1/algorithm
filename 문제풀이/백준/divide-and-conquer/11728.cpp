/*
    병합 정렬과 같은 방식으로 양쪽의 배열을 비교하며 값이 작은 요소가 있는 배열의 요소를 넣고 해당 배열의 인덱스를 증가 시킨다.
    끝까지 돌지 않은 배열이 있다면 비교가 끝난 후 끝까지 돌려서 남은 요소를 넣어준다. (이미 정렬되어있는 배열이기 때문)
*/
#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int num;
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    int i = 0;
    int j = 0;
    int k = 0;
    int arr3[n + m];
    while (true) {
        if (arr1[i] <= arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        if (arr1[i] > arr2[j]) {
            arr3[k++] = arr2[j++];
        }
        if (i == n || j == m) break;
    }
    if (i != n) {
        for (; i < n; i++) {
            arr3[k++] = arr1[i];
        }
    }
    if (j != m) {
        for (; j < m; j++) {
            arr3[k++] = arr2[j];
        }
    }
    for (int l = 0; l < n + m; l++) {
        printf("%d ", arr3[l]);
    }
}
