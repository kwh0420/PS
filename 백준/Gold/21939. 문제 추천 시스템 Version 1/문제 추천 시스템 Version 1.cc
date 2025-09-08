#include <bits/stdc++.h>
using namespace std;
int N,M;
set<long long int>s[103];
int main() {
    cin>>N;
    for (int i = 1; i <= N; i++) {
        int p,r;
        cin>>p>>r;
        s[r].insert(p);
    }
    cin>>M;
    for (int i = 1; i <= M; i++) {
        string command;
        cin>>command;
        if (command=="add") {
            int p,r;
            cin>>p>>r;
            s[r].insert(p);
        }
        else if (command=="recommend") {
            int recom;
            cin>>recom;
            if (recom==1) {
                for (int i = 102;i>=1;i--) {
                    if (!s[i].empty()) {
                        cout << *prev(s[i].end())<<"\n";
                        break;
                    }
                }
            }

            else if (recom==-1) {
                for (int i = 1;i<=102;i++) {
                    if (!s[i].empty()) {
                        cout << *(s[i].begin())<<"\n";
                        break;
                    }
                }
            }
        }
            else if (command == "solved") {
                long long int n;
                cin>>n;
                for (int i = 1;i<=102;i++) {
                    if (s[i].find(n) != s[i].end()) {
                        s[i].erase(n);
                        break;
                    }
                }
            }

    }
}

