#include <stdio.h>
#include <stdbool.h>

#define INF 1000000

// 꼭지점의 개수
int number = 8;

// 전체 그래프 초기화
int a[8][8] = {
        { 0, 4, 3, INF, INF, INF, INF, INF },   //a
        { 4, 0, 2, 5, INF, INF, INF, INF },     //b
        { 3, 2, 0, 3, 6, INF, INF, INF},        //c
        { INF, 5, 3, 0, 1, 5, 2, INF },         //d
        { INF, INF, 6, 1, 0, INF, 5, INF },     //e
        { INF, INF, INF, 5, INF, 0, 2, 7},      //f
        { INF, INF, INF, INF, 5, 2, 0, 4},      //g
        { INF, INF, INF, INF, INF, 7, 4, 0 }
};

// 방문한 노드
bool v[8];
// 거리
int d[8];

//최소 거리를 가지는 정점 반환 함수
int getSmallIndex() {
    int min = INF;
    int index = 0;
    for (int i = 0; i < number; i++) {
        if (d[i] < min && !v[i]) {
            min = d[i];
            index = i;
        }
    }
    return index;
}

int dijkstra(int start) {
    for (int i = 0; i < number; i++) {
        d[i] = a[start][i];
    }
    v[start] = true;
    for (int i = 0; i < number - 2; i++) {
        int current = getSmallIndex();
        v[current] = true;
        for (int j = 0; j < number; j++) {
            if (!v[j]) {
                if (d[current] + a[current][j] < d[j]) {
                    d[j] = d[current] + a[current][j];
                }
            }
        }
    }
}

int main(void) {
    // 꼭지점 이름
    char vertexNameList[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'z' };

    dijkstra(0);
    for (int i = 0; i < number; i++) {
        printf("%c->%c %d\n", vertexNameList[0], vertexNameList[i], d[i]);
    }
}
