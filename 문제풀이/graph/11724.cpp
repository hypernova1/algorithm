/*
    이어져 있는 그래프가 몇 개 인지 알려면 모든 정점으로 부터 탐색을 시작하여 탐색이 된다면 개수를 1 늘리면 된다. 
     -> 모든 그래프의 정점은 이어져 있으므로 어떠한 정점에서 시작하더라도 모두 탐색이 된다는 개념을 이용한다.
*/

#include<iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[1001];
bool c[1001];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    c[s] = true;
    while (!q.empty()) {
        int x = q.front();
        c[x] = true;
        q.pop();
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if (!c[y]) {
                q.push(y);
                c[y] = true;
            }
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    int v1, v2;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!c[i]) {
            bfs(i);
            count++;
        }
    }
    cout << count;
}