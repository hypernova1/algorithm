/**
 * 이진 탐색
 *  - 정렬된 배열에서 찾으려는 값이 중앙의 값과 같은지 비교하여 값이 같을 때 까지 반으로 나눠가며 탐색한다.
 *      - 찾으려는 값이 중앙의 값보다 작으면 반으로 나눠진 2개의 배열의 왼쪽 부분으로 다시 탐색한다.
 *      - 찾으려는 값이 중앙의 값보다 크다면 반으로 나눠진 2개의 배열의 오른쪽 부분으로 다시 탐색한다.
 * 
 *  - 예시) [1, 2, 3, 4, 5, 6, 7, 8, 9]의 배열에서 3을 찾는 방법
 *      1. 중앙의 값인 5와 3을 비교한다.
 *      2. 3이 더 작으니 반으로 나눠 왼쪽 부부으로 다시 탐색한다. [1, 2, 3, 4];
 *      3. 중앙의 값이 3과 같으므로 종료한다.
 *          * 배열의 길이가 짝수 일 경우 반으로 나눈 값에 1을 더하거나 1을 빼서 비교한다.
 * 
 * - 구현
 *      - 재귀함수를 이용하여 구현한다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int binarySearch(int l, int r, int n) {
    if (r >= l) {
        //중앙의 인덱스 값을 구한다.
        int mid = (l + r) / 2;
        //n이 중앙의 값보다 크다면 중앙을 기준으로 나눈 부분 배열의 오른쪽을 탐색
        if (n > arr[mid]) return binarySearch(mid + 1, r, n);
        //n이 중앙의 값보다 작다면 중앙을 기준으로 나눈 부분 배열의 왼쪽을 탐색
        else if (n < arr[mid]) return binarySearch(l, mid - 1, n);
        //값이 일치한다면 1을 반환
        else return 1;
    }
    //r이 l보다 작다면 배열의 길이가 0이므로 0을 반환 (찾을 수 없음)
    return 0;
}

int main(void) {
    int r = binarySearch(0, 8, 10);
    cout << r;
}