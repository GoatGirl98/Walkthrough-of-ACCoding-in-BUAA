#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

struct Card {
    char name[50];
    int cost;
    Card(char name1[] = NULL,int cost1 = 0) {
        strcpy(name, name1);
        cost = cost1;
    }
};

struct Round {
    vector<Card> play;
};
int n, m;
int cardCnt;
char name[4];
char tmpCard[50];
int tmpCost;
int tmpRound, tmpCardCount;
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        vector<Round> Boss;
        vector<Round> Kevin;
        while (n--) {
            scanf("%d", &cardCnt);
            Round round;
            scanf("%s", name);
            while (cardCnt--) {
                scanf("%s%d", tmpCard, &tmpCost);
                round.play.push_back(Card(tmpCard, tmpCost));
            }
            if (name[0] == 'B')Boss.push_back(round);
            else Kevin.push_back(round);
        }
        while (m--) {
            scanf("%s%d%d", name, &tmpRound, &tmpCardCount);
            if (name[0] == 'B') {
                printf("%s %d\n", Boss[tmpRound - 1].play[tmpCardCount - 1].name, Boss[tmpRound - 1].play[tmpCardCount - 1].cost);
            }
            else {
                printf("%s %d\n", Kevin[tmpRound - 1].play[tmpCardCount - 1].name, Kevin[tmpRound - 1].play[tmpCardCount - 1].cost);
            }
        }

    }


}

