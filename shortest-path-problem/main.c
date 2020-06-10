#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define COUNT 8 // 정점 개수
#define INF INT_MAX // 무한 정의

//방문한 노드
bool v[COUNT];
//거리
int dist[COUNT];
//이전에 거쳐간 정점을 담을 배열
int before[COUNT];
//정점 이름
char vertexNames[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'z' };

// 최소 거리를 가지는 정점 인덱스 반환
int minDistance() {
    // 최소값을 무한으로 초기화
    int min = INF;
    int index = 0;

    for (int i = 0; i < COUNT; i++) {
        // 방문하지 않은 정점이고, 거리가 최소값 보다 작다면
        if (!v[i] && dist[i] < min) {
            // 최소값을 그 거리 값으로 갱신
            min = dist[i];
            index = i;
        }
    }

    return index;
}

// 출발점을 제외한 정점 순서 출력
void printPath(int j) {
    // 이전 정점이 존재하지 않으면 리턴
    if (before[j] == -1) {
        return;
    }
    printPath(before[j]);

    // 정점 출력
    printf(" -> %c", vertexNames[j]);

}

// 표 출력 함수
void printSolution() {
    int src = 0;
    printf("Vertex\t Distance\t Path");
    for (int i = 1; i < COUNT; i++) {
        printf("\n%c -> %c \t\t %d\t\t%c", vertexNames[src], vertexNames[i], dist[i], vertexNames[src]);
        printPath(i);
    }
}

void dijkstra(int graph[COUNT][COUNT], int src) {
    for (int i = 0; i < COUNT; i++) {
        before[0] = -1;
        dist[i] = INT_MAX;
        v[i] = false;
    }

    // 시작점에서 시작점까지의 거리를 0으로 설정
    dist[src] = 0;
    for (int count = 0; count < COUNT - 1; count++) {
        // 최소 거리를 가지는 정점의 인덱스 반환
        int current = minDistance();
        // 그 정점을 방문했다고 표시
        v[current] = true;

        for (int j = 0; j < COUNT; j++) {
            // 거쳐가지 않은 정점이고, 원래 알고 있던 값보다 작다면
            if (!v[j] && graph[current][j] != INF
                    && dist[current] + graph[current][j] < dist[j]) {
                before[j] = current;
                // 여태까지 온 정점에서 새로운 정점까지의 거리를 최소 거리로 설정
                dist[j] = dist[current] + graph[current][j];
            }
        }
    }

    printSolution();
}

int main() {
    //그래프 초기화
    int graph[COUNT][COUNT] = {
            { 0, 4, 3, INF, INF, INF, INF, INF },   //a
            { 4, 0, 2, 5, INF, INF, INF, INF },     //b
            { 3, 2, 0, 3, 6, INF, INF, INF },       //c
            { INF, 5, 3, 0, 1, 5, INF, INF },       //d
            { INF, INF, 6, 1, 0, INF, 5, INF },     //e
            { INF, INF, INF, 5, INF, 0, 2, 7 },     //f
            { INF, INF, INF, INF, 5, 2, 0, 4 },     //g
            { INF, INF, INF, INF, INF, 7, 4, 0 }    //z
    };

    dijkstra(graph, 0);

    return 0;
}
