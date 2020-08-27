#include <iostream>

/*
 * 병합 정렬 (분할 정복 알고리즘)
 *   - 퀵 정렬과 다르게 정확하게 반씩 나눠서 정렬을 함
 *   - 일단 나누고 다음에 정렬
 *   - O(N * logN)의 시간 복잡도를 가짐
 * */

using namespace std;

int number = 8;
int sorted[8];

void merge(int data[], int left, int middle, int right) {
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right) {
        if (data[i] <= data[j]) {
            sorted[k++] = data[i++];
        } else {
            sorted[k++] = data[j++];
        }
    }
    if (i > middle) {
        for (int t = j; t <= right; t++) {
            sorted[k++] = data[t];
        }
    } else {
        for (int t = i; t <= middle; t++) {
            sorted[k++] = data[t];
        }
    }

    for (int t = left; t <= right; t++) {
        data[t] = sorted[t];
    }
}

void mergeSort(int data[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(data, left, middle);
        mergeSort(data, middle + 1, right);
        merge(data, left, middle, right);
    }
}

int main() {
    int arr[8] = { 7, 6, 5, 8, 3, 2, 9, 1 };
    mergeSort(arr, 0, number - 1);
    for (int i = 0; i < number; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
