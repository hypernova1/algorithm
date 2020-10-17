/*
    깊이 우선 탐색(DFS)
        - 깊이를 우선으로 하여 탐색을 하는 탐색 알고리즘
        - 맹목적인 탐색을 하고자 할 때 사용
        - 스택(stack)을 사용하여 구현
        - 하지만 스택을 이용하여 구현할 시 조금 복잡해지기 때문에 재귀함수를 이용하여 스택 처럼 구현

        - 구현 방법
            - 스택을 직접 사용하지 않고 재귀 함수를 이용하여 구현 (재귀함수가 스택 방식으로 동작하기 때문)
            - 인접한 노드 중 값이 작은 노드를 먼저 탐색 후 다음 노드로 계속 탐색 후 더 이상 노드가 없다면 방문하지 않은 노드가 있는 노드로 가서 탐색
*/
#include <iostream>
#include <vector>

using namespace std;

int c[7];
vector<int> a[8];

void dfs(int x) {
    //이미 방문한 노드라면 함수를 종료
    if (c[x]) return;
    //방문 처리
    c[x] = true;
    //출력
    cout << x << ' ';
    //재귀함수를 이용하여 해당 노드와 인접한 노드를 끝까지 탐색
    for (int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        dfs(y);
    }
}

int main() {
    //그래프 만들기
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    dfs(1);

    return 0;
}