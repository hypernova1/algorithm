#include <iostream>

using namespace std;

/**
 * 재귀 함수를 이용한 피보나치 수열
 *  - 함수를 실행할 때마다 두 개의 함수가 실행되기 때문에 시간 복잡도는 O(N^2)이다.
*/
int fibonacci(int n) {
    if (n < 2) 
        return n;
    else 
        return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * 동적 계획법을 이용한 피보나치 수열
 *  - 캐시를 위한 배열을 만들어 두고 처음 만들어진 수이면 캐시에 저장
 *  - 캐시에 값이 있다면 재귀 함수를 호출하지 않고 캐시를 반환하기 때문에 시간 복잡도는 O(N)이다.
 *  - ex) 0
 *        1
 *        1 => 0 + 1
 *        2 => 0 + 1 + 1(= 0 + 1)
 *        3 => 0 + 1 + 1(= 0 + 1) + 2(= 0 + 1 + 1(= 0 + 1))
 *        5 => 0 + 1 + 1(= 0 + 1) + 2(= 0 + 1 + 1(= 0 + 1)) + 3(= 0 + 1 + 1(= 0 + 1) + 2(= 0 + 1 + 1(= 0 + 1)))
 *        ...
 *      - 위와 같이 중복되는 계산에 계속 있기 때문에 캐시를 만들어 두는 것.
*/
int cache[11];

int fibonacci_dp(int n) {
    if (n < 2)
        return n;
    if (cache[n])
        return cache[n];
    cache[n] = fibonacci_dp(n - 1) + fibonacci_dp(n - 2);
    return cache[n];
}

/**
 * 꼬리 재귀(tail recursion)를 이용한 피보나치 수열
 *  - 일반적인 재귀 함수는 함수가 호출 된 후 해야할 일이 남아 있기 때문에 스택에 저장이 된다. 하지만 꼬리 재귀는 재귀 함수 실행 후 해야할 일이 남아있지 않기 때문에 스택에 저장할 필요가 없다.
 *  - 프로그래머가 코드는 제어할 수 있지만 재귀 함수를 스택으로 쌓지 않여 최적화 하는 것은 언어 자체에서 지원해 주어야 한다.
 *  - 재귀 호출을 매 번 한 번씩 하기 때문에 시간 복잡도는 O(N)이다.
*/
int fibonacci_tail(int n, int before, int next) {
    if (n == 0)
        return before;
    else
        return fibonacci_tail(n - 1, next, before + next);
}

int fibonacci_tail(int n) {
    return fibonacci_tail(n, 0, 1);
}

/**
 * 반복문을 이용한 피보나치 수열
*/
int fibonacci_loop(int n) {
    int before = 0, cur = 1, i, temp;

    if (n <= 1) {
        return n;
    }
    for (i = 0; i < n; i++) {
        temp = cur;
        cur = before + cur;
        before = temp;
    }
    return cur;
}

int main() {

    int num = 10;

    cout << "------ 재귀 ------" << endl;
    for (int i = 0; i < num; i++) {
        cout << fibonacci(i) << endl;
    }
    cout << "------ 동적 계획법 ------" << endl;
    for (int i = 0; i< num; i++) {
        cout << fibonacci_dp(i) << endl;
    }
    cout << "------ 꼬리 재귀 ------" << endl;
    for (int i = 0; i < num; i++) {
        cout << fibonacci_tail(i) << endl;
    }
    cout << "------ 반복문 ------" << endl;
    for (int i = 0; i < num; i++) {
        cout << fibonacci_loop(i) << endl;
    }

    return 0;
}
