#include<unordered_map>
#include<iostream>
#include<iterator>
using namespace std;
int n;
int tmpInt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        unordered_map<int, pair<int, int>> counterMap;
        //first : number second.firse: first appear index second.second : count

        for (int i = 0; i < n; ++i) {
            cin >> tmpInt;
            unordered_map<int, pair<int, int>>::iterator search =
                counterMap.find(tmpInt);
            if (search == counterMap.end()) {
                counterMap.insert(make_pair(tmpInt, make_pair(i, 1)));
            }
            else {
                ++search->second.second;
            }
        }
        int result = 0;
        int maxCount = 0;
        int minIndex = 10001;

        for (auto& a : counterMap) {
            if (a.second.second > maxCount || (a.second.second == maxCount && a.second.first < minIndex)) {
                result = a.first;
                maxCount = a.second.second;
                minIndex = a.second.first;
            }
        }
        cout << result << endl;
    }

}
