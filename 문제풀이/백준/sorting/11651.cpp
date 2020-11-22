/*
    compare 함수를 정의 해서 y좌표 기준으로 오름차순으로 정렬을 하는데 값이 같다면 x좌표를 가준으로 오름차순 정렬한다.
*/

#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second < p2.second) return true;
	else if (p2.second < p1.second) return false;
	else {
		if (p1.first < p2.first) return true;
		else return false;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	pair<int, int> p[n];
	int first, second;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &first, &second);
		p[i] = make_pair(first, second);
	}
	
	sort(p, p + n, compare);
	
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", p[i].first, p[i].second);
	}
	
}
