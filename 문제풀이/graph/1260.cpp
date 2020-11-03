#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> g[1001];
bool c1[1001];
bool c2[1001];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    c1[s] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if (!c1[y]) {
                q.push(y);
                c1[y] = true;
            }
        }
    }
}

void dfs(int s) {
    c2[s] = true;
    cout << s << ' ';
    for (int i = 0; i < g[s].size(); i++) {
        int x = g[s][i];
        if (!c2[x]) {
            dfs(x);
        }
    }
}

int main(void) {
    int n, m, s;
    cin >> n >> m >> s;
    int v1, v2;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    //작은 수부터 출력되어야 하므로 그래프 연관 관계를 오름차순으로 정렬
    for (int i = 1; i < n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(s);
    cout << endl;
    bfs(s);
}