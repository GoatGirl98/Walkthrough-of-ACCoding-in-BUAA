#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define RADIX 10
#define debug 0
int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;//*f
}
void write(int x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x >= RADIX)write(x / RADIX);
    putchar(x % RADIX + 48);
}
typedef struct node {
    int number;
    struct node* next;
}node;
node* head, * tail;
FILE* in, * out;
void init() {
    head = (node*)malloc(sizeof(node));
    head->number = 0;
    head->next = NULL;
    tail = head;
}
void updateTail() {
    while (tail->next != NULL)tail = tail->next;
}
void addHead(int a) {
    node* temp;
    temp = (node*)malloc(sizeof(node));
    head->number++;
    temp->number = a;
    temp->next = head->next;
    head->next = temp;
    updateTail();
}
void addTail(int a) {
    node* temp;
    temp = (node*)malloc(sizeof(node));
    head->number++;
    temp->number = a;
    temp->next = NULL;
    tail->next = temp;
    tail = tail->next;
}
void removeTarget(int a) {
    node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->number == a) {
            node* target = temp->next;
            temp->next = temp->next->next;
            head->number--;
            free(target);
            return;
        }
        temp = temp->next;
    }
    putchar('e'); putchar('r'); putchar('r'); putchar('o'); putchar('r'); putchar('\n');
}
void removeHead() {
    if (head->next != NULL) {
        write(head->next->number);
        putchar('\n');
        node* target = head->next;
        head->next = head->next->next;
        head->number--;
        free(target);
    }
    else {
        putchar('e'); putchar('r'); putchar('r'); putchar('o'); putchar('r'); putchar('\n');
    }
}
void printSize() {
    write(head->number); putchar('\n');
}
void print() {
    if (head->next != NULL) {
        node* temp = head->next;
        while (temp != NULL) {
            write(temp->number);
            putchar(' ');
            temp = temp->next;
        }
    }
    else {
        putchar('n'); putchar('u'); putchar('l'); putchar('l');
    }
    putchar('\n');
}
int m;
int opA, opB;
void handle() {
    opA = read();
    if (opA == 1) {
        opB = read();
        addTail(opB);
    }
    else if (opA == 2) {
        opB = read();
        addHead(opB);
    }
    else if (opA == 3) {
        removeHead();
    }
    else if (opA == 4) {
        opB = read();
        removeTarget(opB);
    }
    else {
        printSize();
    }
    if (debug) { printf("remain %d : ",m); print(); }
}

int main() {
    //in = freopen("testfile for BUAAOJ2165.txt", "r", stdin);
    init();
    m = read();
    while (m--) { handle(); }
    print();
    return 0;
}
