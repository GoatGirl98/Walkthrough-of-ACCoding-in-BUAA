#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;
struct Book {
    string title, author;
    friend bool operator < (const Book &a, const Book &b) {
        return a.author < b.author || (a.author==b.author && a.title < b.title);
    }
}tmp;

vector<Book> books;
map<string, int> ID;
set<int> desk, shelve;
string op, line, title;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    while(getline(cin, line) && line!="END") {
        int p = line.find("by");
        tmp = Book{ line.substr(0, p-1), line.substr(p+3) };
        books.push_back(tmp);
    }
    sort(books.begin(), books.end());
    for(int i = 0; i < books.size(); i++) {
        ID[ books[i].title ] = i;       //为书本名称编号
        shelve.insert(i);
    }
    while(cin>>op && op!="END") {
        if(op=="SHELVE") {
            for(auto x:desk) {
                auto p = shelve.find(x);
                printf("Put %s", books[x].title.c_str());
                if(p == shelve.begin()) puts(" first");
                else printf(" after "), puts(books[*(--p)].title.c_str());
            }
            desk.clear();
            puts("END");
            continue;
        } else {
            getline(cin, title);
            title = title.substr(1);        ///getline不会忽略cin>>op时留下的空格
            if(op == "RETURN") desk.insert(ID[title]), shelve.insert(ID[title]);
            else if(op == "BORROW") shelve.erase(ID[title]);
        }
    }
}
