/*
 * 이진 트리의 구현과 순회 방식
 *  1. 전위 순회: 자신 -> 왼쪽 -> 오른쪽
 *  2. 중위 순회: 왼쪽 -> 자신 -> 오른쪽
 *  3. 후위 순회: 왼쪽 -> 오른쪽 -> 자신
 */
#include <iostream>

using namespace std;

int number = 15;

typedef struct node *treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;

//전위 순회
void preorder(treePointer ptr) {
    if (ptr) {
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

//중위 순회
void inorder(treePointer ptr) {
    if (ptr) {
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}

//후위 순회
void postorder(treePointer ptr) {
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

/*
 * 2진 트리 구조
 *                      1
 *               2              3
 *            4     5       6      7
 *           8 9  10 11   12 13  14 15
 * */
int main() {
    node nodes[number + 1];

    for (int i = 1; i <= number; i++) {
        nodes[i].data = i;
        nodes[i].leftChild = nullptr;
        nodes[i].rightChild = nullptr;
    }
    for (int i = 1; i <= number; i++) {
        if (i % 2 == 0) {
            nodes[i / 2].leftChild = &nodes[i];
        } else {
            nodes[i / 2].rightChild = &nodes[i];
        }
    }
    preorder(&nodes[1]);
    cout << endl;
    inorder(&nodes[1]);
    cout << endl;
    postorder(&nodes[1]);
}