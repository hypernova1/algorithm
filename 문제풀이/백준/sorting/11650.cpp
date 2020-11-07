/*
    compare 함수를 정의 해서 x 좌표가 작으면 그대로 정렬하고 같으면 y를 기준으로 정렬하게 한다.
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

int main(void) {
    int n;
    scanf("%d", &n);
    pair<int, int> p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    sort(p, p + n, comp);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", p[i].first, p[i].second);
    }
}