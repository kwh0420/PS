#include <bits/stdc++.h>
using namespace std;
long long int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>T;
    while (T--) {
        long long int n;
        cin >> n;
        multiset<long long int> s;
        while (n--) {
            char ins;
            long long int k;
            cin >> ins >> k;
            switch (ins) {
                case 'I': {
                    s.insert(k);
                    break;
                }
                case 'D': {
                    if (!s.empty()) {
                        if (k==1) {
                            auto it = prev(s.end());
                            s.erase(it);
                        }
                        if (k==-1) {
                            auto it = s.begin();
                            s.erase(it);
                        }
                    }
                    break;
                }
            }
        }
        if (s.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *(--s.end()) << " " << *s.begin() <<"\n";
        }
    }
}