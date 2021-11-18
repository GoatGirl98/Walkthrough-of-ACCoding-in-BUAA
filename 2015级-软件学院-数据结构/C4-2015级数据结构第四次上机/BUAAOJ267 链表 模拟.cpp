#include<cstdio>
int l, r, t, tmpInt;
/*
复习C语言的基本链表操作
本题就是一个基本的循环链表操作
*/
struct List {
    int data;
    List* next;
};
//头指针为fNode，尾部插入num节点
//头指针只记录个数
List* addNode(int num, List* fNode) {
    List* lNode = fNode;
    while (lNode->next != fNode) {
        lNode = lNode->next;
    }
    List* nNode = new List;
    nNode->data = num;
    nNode->next = fNode;
    lNode->next = nNode;
    fNode->data++;
    return nNode;
}
//删除第pos个节点
void deleteNode(int pos, List* fNode) {
    List* tNode = fNode;
    for (int i = 1; i < pos; ++i)
        tNode = tNode->next;
    tNode->next = tNode->next->next;
    fNode->data--;
}

void printList(List* fNode) {
    List* tNode = fNode->next;
    while (tNode != fNode) {
        printf("%d ", tNode->data);
        tNode = tNode->next;
    }
    putchar('\n');
}

int main() {
    while (scanf("%d", &t) != EOF) {
        List* lists = new List;
        lists->data = 0;
        lists->next = lists;
        for (int i = 0; i < t; ++i) {
            scanf("%d", &tmpInt);
            addNode(tmpInt, lists);
        }
        scanf("%d%d", &l, &r);
        for (int i = 0; i < r - l + 1; ++i) {
            deleteNode(l, lists);
        }
        printList(lists);
        delete lists;
    }
    return 0;
}
