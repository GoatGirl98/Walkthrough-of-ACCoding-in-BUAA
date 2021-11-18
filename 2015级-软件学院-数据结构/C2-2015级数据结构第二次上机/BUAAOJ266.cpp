#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int n, m;
int tmpint;
char Insert[5] = "Ins";
char Delete[5] = "Del";
char Locate[5] = "Loc";
char Getcha[5] = "Get";
char operation[5];

int opA, opB;

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmpint);
            a.push_back(tmpint);
        }
        while (m--) {
            scanf("%s", operation);
            if (!strcmp(operation, Insert)) {
                scanf("%d%d", &opA, &opB);

                if (opA > (a.size() + 1)||opA <= 0) {
                    printf("Wrong input!\n");
                }
                else  {
                    a.insert(a.begin() + opA - 1, opB);
                    for (int n : a)printf("%d ", n);
                    printf("\n");
                }
            }
            else if (!strcmp(operation, Delete)) {
                scanf("%d", &opA);
                bool mark = false;
                for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
                    if (*it == opA) {
                        mark = true;
                        a.erase(it);  //本题当中不涉及多个元素的删除，所以迭代器无需回退
                        for (int n : a)printf("%d ", n);
                        printf("\n");
                        break;
                    }
                }
                if(!mark)printf("Wrong input!\n");
            }
            else if (!strcmp(operation, Locate)) {
                scanf("%d", &opA);
                bool mark = false;
                vector<int>::iterator it = a.begin();
                for (int i = 0; it + i != a.end(); ++i) {
                    if (*(it + i) == opA) {
                        mark = true;
                        printf("%d\n", ++i);
                        break;
                    }
                }
                if (!mark)printf("Wrong input!\n");
            }
            else if (!strcmp(operation, Getcha)) {
                scanf("%d", &opA);
                vector<int>::iterator it = a.begin();
                if (opA > a.size()||opA<=0)printf("Wrong input!\n");
                else printf("%d\n", *(it + opA - 1));
            }
        }


    }



}
