/*
    369 게임
        - 문제 내용
            - 369 게임을 하면서 박수를 친 횟수만큼 값을 출력한다
            - 33의 경우 숫자 안에 3이 두 개 있으므로 박수를 두 번 친다.
        - 예
            - input:3 output: 1
*/

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        //숫자를 문자열로 바꿈
        string str = to_string(i);
        //문자열을 순회하면서 각 문자가 3, 6, 9 라면 횟수를 증가한다.
        for (int j = 0; j < str.length(); j++) {
            if (str[j] - '0' == 3 || str[j] - '0' == 6 || str[j] - '0' == 9) {
                count++;
            }
        }
    }
    cout << count;
}
