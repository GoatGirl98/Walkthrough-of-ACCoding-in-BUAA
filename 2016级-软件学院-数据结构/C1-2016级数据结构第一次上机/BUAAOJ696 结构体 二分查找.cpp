#pragma G++ optimize(2)
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10010
int n, m;
struct Student {
    char name[100];
    int num;
    double grade;
    int position;
}stu[maxn];
int num[maxn];
bool cmp(Student a, Student b)
{
    if (a.grade == b.grade)
    {
        return (a.num < b.num);
    }
    return (a.grade > b.grade);
}
bool cmp2(Student a, Student b) {
    return a.num < b.num;
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s %d %lf", &stu[i].name, &stu[i].num, &stu[i].grade);
        }
        sort(stu, stu + n, cmp);
        for(int i=0;i<n;i++)
        {
            stu[i].position = i + 1;
        }
        sort(stu, stu + n, cmp2);
        for (int i = 0; i < n; i++)num[i] = stu[i].num;
        scanf("%d", &m);
        int search1;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &search1);
            int* pos = lower_bound(num, num + n, search1);
            if (num[pos - num] == search1) {
                printf("%s %d %.2lf %d\n", stu[pos - num].name, stu[pos - num].num, stu[pos - num].grade, stu[pos - num].position);
            }
            else {
                printf("Only god knows where he is.\n");
            }
        }
    }
}
