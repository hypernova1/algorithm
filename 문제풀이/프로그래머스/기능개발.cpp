/*
    앞의 기능이 개발되지 않으면 다음 기능이 완료되어도 배포할 수 없으므로
    순회를 하면서 완료되지 않은 작업 인덱스 전까지만 카운트를 하고 그 다음 인덱스를 시작으로 두고 반복한다.
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer;
    int start = 0;
    while (true) {
        //모든 작업의 진척도에 작업양을 한 번씩 더해준다.
        for (int i = start; i < p.size(); i++) {
            p[i] += s[i];
        }
        //만약 시작 인덱스에 해당하는 작업의 진척도가 100 이상이라면
        if (p[start] >= 100) {
            //카운트 증가 시킴
            int count = 1;
            //시작 인덱스 다음 요소부터 진척도가 100 미만인 요소까지 카운트한다.
            for (int i = start + 1; i < p.size(); i++) {
                if (p[i] < 100) {
                    break;
                }
                count++;
            }
            //카운트가 0보다 크면 결과 배열에 넣어주고 현재 시작 인덱스를 그만큼 증가 시킨다.
            if (count > 0) {
                answer.push_back(count);
                start += count;
            }
        }
        //만약 배열을 다 돌았다면 빠져나온다.
        if (start == p.size()) break;
    }
    return answer;
}