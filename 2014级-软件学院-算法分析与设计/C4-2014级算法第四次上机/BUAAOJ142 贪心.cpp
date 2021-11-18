#include<cstdio>
#define DEBUG 0
using namespace std;

int cashValue[6] = { 1,5,10,50,100,500 };
int cashCount[6];

int price;
int count;
bool mark;

int main() {
    while (scanf("%d%d%d%d%d%d%d", cashCount, cashCount + 1, cashCount + 2, cashCount + 3, cashCount + 4, cashCount + 5, &price) != EOF) {
        //printf("%d %d %d %d %d %d %d\n", cashCount[0], cashCount[1], cashCount[2], cashCount[3], cashCount[4], cashCount[5], price);
        count = 0;
        mark = false;
        for (int i = 5; i >= 0; --i) {
            
            while (cashCount[i] > 0) {
                if (price < cashValue[i])break;
                price -= cashValue[i];
                cashCount[i]--;
                count++;
                if (price == 0) { mark = true; break; }
            }
            if (mark)break;
        }
        printf("%d\n", count);
    }


}
