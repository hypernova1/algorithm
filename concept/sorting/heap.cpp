/*
	힙 정렬
	- 합: 최소값과 최대값을 빠르게 찾아내기 위해 완전 이진 트리를 이용하는 트리
		- 완전 이진 트리: 이진 트리가 왼쪽부터 차례대로 채워진 형태
		- 최대 힙: 부모 노드가 자식 노드보다 값이 큼
		- 최소 힙: 부모 노드가 자식 노드보다 값이 작음

	힙 정렬 순서
		- 힙 구조가 완성 되면 가장 큰 수(루트)와 가장 작은 수를 바꿔준다.
		- 가장 큰 수의 노드를 제외하고 나머지 노드로 다시 힙 구조를 만든다.
		- 반복
	
	- 힙구조를 만들 때는 높이만큼 계산하기 때문에 logN 만큼의 시간복잡도를 가짐
		- ex. 노드의 개수가 8개면 높이는 3이 됨. 따라서 logN
	- 노드 수만큼 반복하기 때문에 시간 복잡도는 N * logN이 된다.
*/

#include <iostream>

int number = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main() {
	// 트리 구조를 힙 구조로 바꿈
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	//크기를 줄여가면서 반복적으로 힙 구성
	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			//자식 중에 더 큰 값 찾기
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}
			//루트보다 자식이 더 크다면 교환
			if (heap[root] < heap[c] && c < i) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}

	for (int i = 0; i < number; i++) {
		printf("%d", heap[i]);
	}
}