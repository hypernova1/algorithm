/*
 * 크루스칼 알고리즘(Kruskal)
 *  - 가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘
 *  - 최소 비용 신장 트리를 만들기 위한 대표적인 알고리즘
 *  - ex) 도시가 여러개 있을 때 각 도시를 도로룰 이용하여 연결
 *
 *  - 구현 방법
 *      1. 정렬된 순서에 맞게 그래프에 포함 시킴
 *      2. 포함 시키기 전에 사이클 테이블(사이클이 발생하는지)을 확인 (Union-Find 사용)
 *      3. 사이클을 형성하는 경우 간선을 포함하지 않음
* */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return getParent(parent, parent[x]);
}

//각 노드의 부모를 합침
int unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

//같은 부모 노드를 가지는지 확인
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) return 1;
    return 0;
}

//간선 클래스 선언
class Edge {
public:
    int node[2]{};
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator <(Edge &edge) const {
        return this->distance < edge.distance;
    }
};

int main() {

    int n = 7; //정점의 개수
    int m = 11; //간선의 개수

    vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));

    //간선의 비용을 기준으로 오름차순 성렬
    sort(v.begin(), v.end());

    //각 정점이 포함된 그래프가 어디인지 저장
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        //사이클이 발생하지 않는 경우 그래프에 포함
        if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
            sum += v[i].distance;
            unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }

    cout << sum << endl;

}