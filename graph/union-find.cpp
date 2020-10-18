/*
 * 합집합 찾기 (Union-Find)
 *  - 서로소 집합 알고리즘이라고도 불림
 *  - 여러개의 노드가 존재할 때 두 개의 노드를 선택하여, 현재 이 두 노드가 서로 같은 그래프에 속하는 지 판별
 *
 *  - 구현 방법
 *      1. 모든 노드가 자기 자신을 부모로 가리키도록 함
 *      2. 부모를 합칠 때 더 작은 값 쪽으로 합침
 *      3. 재귀 함수를 사용하여 최상위 부모를 가리키도록 함
 *
 * */
#include <iostream>

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

int main() {
    int parent[11];
    for (int i = 1; i <= 10; i++) {
        parent[i] = i;
    }

    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);
    printf("%d\n", findParent(parent, 1, 5));
    unionParent(parent, 1, 5);
    printf("%d\n", findParent(parent, 1, 5));
}