#include <iostream>

/*
 * 퀵 정렬 (분할정복 알고리즘)
 *   1. 첫 번째 요소를 기준 값(Pivot)으로 설정한다.
 *   2. 피봇을 기준으로 오르쪽으로 탐색하면서 피봇보다 큰 요소를 선택한다.
 *   3. 피봇을 기준으로 왼족으로 탐색하면서 피봇보다 작은 요소를 선택한다.
 *   4. 선택된 두 요소의 자리를 바꾸고 다시 2로 돌아가서 반복한다.
 *   5. 작은 값 요소의 인덱스가 큰 값 요소의 인덱스보다 작다면 (엇갈렸다면) 더 작은 값 요소와 피봇 요소의 위치를 바꾼다.
 *   6. 피봇 보다 왼쪽에 있는 요소의 집합과 오른쪽에 있는 요소의 집합으로 나눈 후 2부터 다시 반복한다.
 *
 *  * O(N^2)의 복잡도를 가지는 정렬 방식은 데이터가 10만개만 넘어가도 엄청난 연산을 수행하게 된다. (100000 * 100000)
 *  * 퀵 정렬 알고리즘은 평균 O(N * logN) 복잡도를 가지므로 위의 정렬 방식보다 월등하게 속도가 빠르다.
 *  * 피봇이 중앙에 가까울 수록 속도가 빠르다.
 *  * 이미 정렬되어 있는 경우 복잡도는 O(N^2)이다.
 *    - 정렬이 되어 있을 수록 속도가 느리다.
 * */

using namespace std;

int number = 10;
int arr[] = { 1, 10, 4, 8, 7, 6, 5, 3, 2, 9 };

void quickSort(int *data, int start, int end) {
    if (start >= end) {
        return;
    }
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while (i <= j) {
        while (data[i] <= data[key]) {
            i++;
        }
        while (data[j] >= data[key] && j > start) {
            j--;
        }
        if (i > j) {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
        quickSort(data, start, j - 1);
        quickSort(data, j + 1, end);
    }
}

int main() {
    quickSort(arr, 0, number - 1);
    for (int i : arr) {
        cout << i << " ";
    }
}
