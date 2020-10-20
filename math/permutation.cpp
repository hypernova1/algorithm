/**
 * 순열 알고리즘
 *  - 순열이란 n개의 원소를 나열할 수 있는 모든 경우의 수이다.
 *  - 재귀를 이용하여 구현한다.
 *
 *  ex)
 *  1 2 3
 *  1 3 2
 *  2 1 3
 *  2 3 1
 *  3 1 2
 *  3 2 1
*/
#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int>& arr, int start, int end) {
    if (start == end) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    else {
        for (int i = start; i <= end; i++) {
            swap(arr[start], arr[i]);
            permutation(arr, start + 1, end);
            swap(arr[start], arr[i]);
        }
    }
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    permutation(v, 0, v.size() - 1);
    return 0;
}