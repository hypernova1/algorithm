/*
    너비 우선 탐색(BFS)
        - 너비를 우선으로 하여 탐색을 하는 탐색 알고리즘
        - 맹목적인 탐색을 하고자 할 때 사용
        - 최단 길이를 찾을 때 많이 사용
        - 큐(queue)를 사용하여 구현
        - 가장 가까운 노드부터 차례대로 탐색

        - 구현 방법
            1. 큐에서 노드 하나를 꺼낸 후 노드와 연결된 노드 들을 큐에 넣고 방문 처리함
            2. 다음 노드를 꺼낸 후 연결된 노드 들 중 아직 방문처리 되지 않은 노드들을 큐에 넣고 방문 처리 함
            3. 반복 후 방문 처리된 노드 들을 차례대로 출력
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int c[7]; //방문을 완료한 노드를 넣을 리스트
vector<int> a[8]; //그래프를 만들기 위한 벡터, 각 노드의 인덱스가 1부터 시작되도록 8로 선언

void bfs(int start) {
    queue<int> q;
    q.push(start);
    c[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        printf("%d ", x);

        //큐에서 꺼낸 노드와 인접한 노드를 방문하면서 방문처리를 함
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            //방문을 하지 않은 노드라면
            if (!c[y]) {
                //큐에 넣어주고
                q.push(y);
                //방문 처리
                c[y] = true;
            }
        }
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

    bfs(1);

    return 0;
}