/*
 * 에라토스테네스의 체
 *  - 소수를 구하는 알고리즘
*/

#include <iostream>
#include <math.h>

using namespace std;

/**
 * 일반적인 소수 알고리즘
 * 시간 복잡도는 O(N)
 * 모든 약수를 다 따져본다는 점에서 매우 비효율적
*/
bool isPrimeNumber(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

/**
 * 소수 문제는 O(N^(1/2))로 계산 가능
 * 8 = 2 * 4 = 4 * 2 와 같이 대칭을 이루기 때문
 * 제곱근을 구하여 제곱근까지만 순회
*/
bool isPrimeNumber2(int x) {
    int end = (int) sqrt(x);
    for (int i = 2; i <= end; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

/**
 * 에라토스테네스의 체
 *  - 여러개의 소수를 구해야 할 때 사용
*/
int number = 100000;
int a[100001];

void primeNumberSieve() {
    for (int i = 2; i <= number; i++) {
        a[i] = i;
    }
    for (int i = 2; i <=number; i++) {
        if (a[i] == 0) continue;
        for (int j = i + i; j <= number; j += i) {
            a[j] = 0;
        }
    }

    for (int i = 2; i <= number; i++) {
        if (a[i] != 0) cout << a[i] << ' ';
    }
}

int main() {
    printf("%d", isPrimeNumber(7));
    primeNumberSieve();
}