#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
struct Info{
    char name[15];
    int score;
    /*
    bool operator < (const Info & b) const {
        return score < b.score;
    }
    */
}ScoreSheet[maxn];
bool needSort;
bool cmp(Info a, Info b) {
    if (a.score == b.score) {
        return (strcmp(b.name, a.name)>0);
    }
    else {
        return a.score > b.score;
    }
}
int size;
char temp[15];
int temp_score;
bool locate(char lala[],int lalala) {
    for (int i = 0; i < size; ++i) {
        if (!strcmp(lala, ScoreSheet[i].name)) {
            ScoreSheet[i].score = lalala;
            return true;
        }
    }
    return false;
}
void add(char lala[], int lalala) {
    strcpy(ScoreSheet[size].name, lala);
    ScoreSheet[size++].score = lalala;
}
int q;
int op;
int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%s%d", temp, &temp_score);
            if (!locate(temp, temp_score))add(temp, temp_score);
            needSort = true;
        }
        else {
            scanf("%d", &temp_score);
            if(needSort)std::sort(ScoreSheet, ScoreSheet + size,cmp);
            printf("%s %d\n", ScoreSheet[temp_score - 1].name, ScoreSheet[temp_score - 1].score);
            needSort = false;
        }
    }
}
