/*
    https://programmers.co.kr/learn/courses/30/lessons/17682
*/
#include <string>
#include <cmath>

using namespace std;

int solution(string d) {
    int answer = 0;
    int prev = 0;
    int i = 0;
    while (i < d.length()) {
        // 숫자를 가져온다.
        int val = d[i++] - '0';
        // 다음 문자가 0이면 10이라는 뜻이므로 원래 값에 10을 곱해준다.
        if (d[i] - '0' == 0) {
            val *= 10;
            i++;
        }
        // S는 1을 제곱하기 때문에 pass 나머지는 계산한다.
        if (d[i] == 'D') {
            val = pow(val, 2);
        } else if (d[i] == 'T') {
            val = pow(val, 3);
        }
        // 다음 글자로 넘어간다.
        i++;
        // 만약 다음 글자가 없으면 가져온 숫자를 더해주고 반복문을 빠져 나온다.
        if (i == d.length()) {
            answer += val;
            break;
        }
        // 최종적으로 결과에 더해 줄 값
        int sum = val;
        // *이라면 현재 값에는 2를 곱해주고 이전 값을 더해준다(이전 값은 이미 더해져있으므로 * 2를 하면 안 된다).
        if (d[i] == '*') {
            val = val * 2;
            sum = val + prev;
            i++;
        // #이라면 원래 숫자에 -1을 곱해준다.
        } else if (d[i] == '#') {
            val *= -1;
            sum = val;
            i++;
        }
        answer += sum;
        // 현재 값을 이전 값으로 할당한다.
        prev = val;
    }
    
    return answer;
}