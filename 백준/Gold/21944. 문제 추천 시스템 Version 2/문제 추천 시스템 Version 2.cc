#include <bits/stdc++.h>
using namespace std;
int N, M;
set<pair<long long int, long long int> > set1[103];
set<pair<long long int, long long int> > set2;
map<long long int, long long int> map1;
map<long long int, long long int> map2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int P, L, G;
        cin >> P >> L >> G;
        map1[P] = L;
        map2[P] = G;
        set1[G].insert({L, P});
        set2.insert({L, P});
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string command;
        cin >> command;
        if (command == "add") {
            int P, L, G;
            cin >> P >> L >> G;
            map1[P] = L;
            map2[P] = G;
            set1[G].insert({L, P});
            set2.insert({L, P});
        } else if (command == "recommend") {
            int G, x;
            cin >> G >> x;
            if (x == 1) {
                cout << (*prev((set1[G]).end())).second;
            } else if (x == -1) {
                cout << (*((set1[G]).begin())).second;
            }
            cout << "\n";
        } else if (command == "recommend2") {
            int x;
            cin >> x;
            if (x == 1) {
                cout << (*(prev(set2.end()))).second;
            } else if (x == -1) {
                cout << (*(set2.begin())).second;
            }
            cout << "\n";
        } else if (command == "recommend3") {
            int x, L;
            cin >> x >> L;
            auto it = set2.lower_bound({L, 0});
            if (x == 1) {
                if (it != set2.end()) {
                    cout << it->second;
                } else {
                    cout << -1;
                }
            } else if (x == -1) {
                if (it != set2.begin()) {
                    cout << prev(it)->second;
                } else {
                    cout << -1;
                }
            }
            cout << "\n";
        } else if (command == "solved") {
            int P;
            cin >> P;
            set1[map2[P]].erase({map1[P], P});
            set2.erase({map1[P], P});
        }
    }
}
