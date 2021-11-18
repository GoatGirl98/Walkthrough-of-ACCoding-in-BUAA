#include<iostream>
#include<cstring>
#define DEBUG 0
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    string lalala;
    string tls = "tls";
    string lls = "lls";
    string lzy = "lzy";
    int counter;
    int index;
    while (cin >> lalala) {

        counter = 0;
        index = 0;
        while ((index = lalala.find(tls, index)) != -1) { counter++; if (DEBUG)printf("find tls! : %d\n", index); index++; }
        index = 0;
        while ((index = lalala.find(lls, index)) != -1) { counter++; if (DEBUG)printf("find lls! : %d\n", index); index++; }
        index = 0;
        while ((index = lalala.find(lzy, index)) != -1) { counter++; if (DEBUG)printf("find lzy! : %d\n", index); index++; }
        if (counter == 1)printf("YES\n"); else printf("NO\n");
    }

}
