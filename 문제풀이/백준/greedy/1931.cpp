#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

/*
    2중 포문을 돌리며 시작과 끝사이에서 가장 폭이 작은 페어를 찾고 개수를 증가 시키고,
    그 요소의 second를 시작 인덱스로 둔 후 반복해서 풀었지만 시간초과가 났다. 코드도 너무 더럽고 알아보기 힘들다.
    사실 정답인지도 모르겠다. 반례를 검색해서 돌려보기만 했다. 그래서 정답을 찾아 보았다.
*/
void wrong() {
    int n;
    cin >> n;
    pair<int, int> p[n + 1];
    int end = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        if (p[i].second > end) end = p[i].second;
    }
    int start = 0;
    int count = 0;
    while (true) {
        int i = 1;
        int min = end;
        bool a = false;
        for (;i <= n; i++) {
            if (p[i].first >= start && p[i].second <= min) {
                if (min >= p[i].second) {
                    min = p[i].second;
                    a = true;
                }
            }
        }
        if (a) {
            start = min;
            count ++;
        }
        if (min == end) break;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i].first == end && p[i].second == end) {
            count++;
            break;
        }
    }
    cout << count;
}
/*
    아래와 같이 종료 시간을 기준으로 오름차순으로 정렬한 후 가장 빠른 종료 시간의 요소 가져온 후,
    그 요소의 시작 시간을 기준점으로 두고 시작 시간보다 크면서 가장 빠른 인덱스의 요소를 가져온다.
*/
int main(void) {
    int n;
    cin >> n;
    pair<int, int> p[n + 1];
    //종료 시간을 먼저 받음 pair은 first 기준으로 정렬되기 때문
    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p + n);
    //시작을 일단 0으로 둔다.
    int start = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        //시작 시간보다 크거나 같은 요소를 가져와서 다시 그 요소의 종료 시간을 기준으로 두고 반복한다.
        if (start <= p[i].second) {
            start = p[i].first;
            count++;
        }
    }
    cout << count;
}
