#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<cstring>

using namespace std;

bool sorted;

char Add[4] = "Add";
char Del[4] = "Del";
char Sum[4] = "Sum";
char op[5];
int tmpint;
int n;
long long result;
int main() {
    while (scanf("%d",&n) != EOF) {
        vector<int> a;
        sorted = true;
        while (n--) {
            scanf("%s", op);
            if (!strcmp(op, Add)) {
                scanf("%d", &tmpint);
                a.push_back(tmpint);
                sorted = false;
            }
            else if (!strcmp(op, Del)) {
                if (!sorted) { sort(a.begin(), a.end()); sorted = true;}
                scanf("%d", &tmpint);
                for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
                    if (*it == tmpint) {
                        a.erase(it);  //本题当中不涉及多个元素的删除，所以迭代器无需回退
                        break;
                    }
                }
            }
            else if (!strcmp(op, Sum)) {
                result = 0;
                if (!sorted) { sort(a.begin(), a.end()); sorted = true; }
                for (int i = 2; i < a.size(); i += 5) {
                    result += (long long)a[i];
                }
                printf("%lld\n", result);
            }
        }
    }
}
