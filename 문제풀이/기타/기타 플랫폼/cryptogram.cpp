/*
    암호 해독하기
        - 문제 내용
            - 문자열이 주어지면 인접한 문자가 같은지 판단하고 같으면 지운다. (우테코 1기 7번 문제)
        - 예
            - aabbc -> bbc -> c
            - browoanoommnaon -> browoanmmnaon -> browoannaon -> browoaaon -> browoon -> brown
*/

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str = "browoanoommnaon";
    int i = 0;
    while (true) {
        //현재 문자와 다음 문자가 같으면
        if (str[i] == str[i + 1]) {
            //만약 문자가 2개라면 빈 문자열로 만듬 ex) str = "aa";
            if (str.size() == 2) {
                str = "";
                break;
            }
            //해당 인덱스 전까지 자른 문자열 + 다음 안덱스 + 1부터 끝까지 자른 문자열
            str = str.substr(0, i) + str.substr(i + 2, str.length());
            //다시 처음부터 탐색하도록 인덱스를 0으로 바꿈
            i = 0;
            continue;
        }
        i++;
        //i가 str이라는것은 if조건을 만족하지 못했다는 뜻이다. 따라서 반복문을 종료한다.
        if (i == str.length()) break;
    }
    cout << str;
}
