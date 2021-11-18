#include<cstdio>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#define mp make_pair
using namespace std;
map<int, pair<string, double> >menu;
map<string, pair<double, int> > buy;
typedef map<string, pair<double, int> >::iterator IT;
inline void init() {
    menu.insert(mp(932071, mp("chips", 3.50)));
    menu.insert(mp(114049, mp("chocolate", 8.00)));
    menu.insert(mp(304985, mp("soap", 2.90)));
    menu.insert(mp(955962, mp("cupcake", 4.90)));
    menu.insert(mp(313903, mp("cookie", 6.50)));
    menu.insert(mp(243813, mp("milk", 3.20)));
    menu.insert(mp(961995, mp("toothbrush", 4.80)));
    menu.insert(mp(933328, mp("toothpaste", 9.30)));
    menu.insert(mp(914500, mp("teapot", 29.80)));
}
int input;
int maxlen;
char tmp[10];
string Tmp;
double total;
int main() {
    init();
    total = 0.0;
    while (scanf("%d", &input) && input) {
        if (!buy.count(menu[input].first))
            buy.insert(mp(menu[input].first, mp(menu[input].second, 1)));
        else
            buy[menu[input].first].second++;
    }
    for (IT it = buy.begin(); it != buy.end(); ++it)
        maxlen = max(maxlen, (int)(*it).first.size());
    printf("NAME");
    for (int i = 0; i <= maxlen - 4; ++i)putchar(' ');
    puts("QUANTITY PRICE SUM");
    for (IT it = buy.begin(); it != buy.end(); ++it) {
        printf("%s", (*it).first.c_str());
        for (int i = 0; i <= maxlen - (*it).first.size(); ++i)putchar(' ');
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "%d", (*it).second.second);
        Tmp = tmp;
        printf("%s", Tmp.c_str());
        for(int i = 0; i <= 8 - Tmp.size(); ++i)putchar(' ');
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "%.1f", (*it).second.first);
        printf("%s", tmp);
        Tmp = tmp;
        for (int i = 0; i <= 5 - Tmp.size(); ++i)putchar(' ');
        double add = (*it).second.first * (double)(*it).second.second;
        printf("%.2f\n", add);
        total += add;

    }
    printf("total:%.2f", total);
}
