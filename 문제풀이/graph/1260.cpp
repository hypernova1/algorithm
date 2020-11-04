#include <iostream>
#include <queue>

using namespace std;

//정점 개수, 간선 개수, 시작 번호
int n, m, s;
//정점이 최대 1000개까지 있으므로 1001로 선언
int v[1001][1001];
//지났다는 표시를 하기 위한 배열
bool c1[1001];
bool c2[1001];

//깊이 우선 탐색
void dfs(int num) {
    //출력
    cout << num << ' ';
    //정점을 지났다고 표시
    c1[num] = true;
    //1번부터 정점의 개수까지 순회하면서 그 정점을 지나지 않았고 연관 관계가 있다면 재귀 호출
    for (int i = 1; i <= n; i++) {
        if (v[num][i] && !c1[i]) {
            dfs(i);
        }
    }
}

//너비 우선 탐색
void bfs(int num) {
    queue<int> q;

    q.push(num);
    //지났다고 표시
    c2[num] = true;

    //정점을 지나면서 관계가 있는 정점 들을 큐에 넣고 출력
    while (!q.empty()) {
        int x = q.front();
        c2[x] = true;
        cout << x << ' ';
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (!c2[i] && v[x][i]) {
                c2[i] = true;
                q.push(i);
            }
        }
    }
}

int main(void) {
    int v1, v2;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> v1 >> v2;
        v[v1][v2] = 1;
        v[v2][v1] = 1;

    }
    dfs(s);
    cout << endl;
    bfs(s);

}
