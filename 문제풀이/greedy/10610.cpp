/*
    숫자 크기가 아니라 자리수가 최대 1000000개라서 숫자형으로 선언하지 않고 문자열로 받아서 처리하는 게 좋다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    string n;
    cin >> n;
    vector<int> v;
    //문자열을 숫자 배열로 바꿈
    for (int i = 0; i < n.length(); i++) {
        v.push_back(n[i] - '0');
    }
    //정렬
    sort(v.begin(), v.end());

    //0번째가 0이 아니면 30으로 나누어 떨어지지 않기 때문에 -1 반환
    if (v[0] != 0) {
        cout << -1;
    } else {
        //0이 포함되어 있기 때문에 거꾸로 정렬하면 0이 마지막에 온다.
        //각 자릿수의 합이 3의 배수이기만 그 수는 하다면 30의 배수이다.
        int m = 0;
        string r;
        //오름차순이기 때문에 가장 큰 수가 앞에 오도록 끝부터 더한다.
        for (int i = v.size() - 1; i >= 0; i--) {
            //각 자리수를 더한다.
            m += v[i];
            //문자열을 계속 더해준다.
            r += to_string(v[i]);
        }
        //3으로 나누어 떨어지면 결과 반환 아니면 -1 반환
        if (m % 3 != 0) {
            cout << -1 ;
        } else {
            cout << r;
        }
    }
}
