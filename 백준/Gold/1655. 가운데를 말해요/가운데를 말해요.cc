#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k;
    cin>>k;
    s.insert(k);
    auto it  = s.begin();
    cout << *it << "\n";
    int big=0;
    int small=0;
    for(int i=2;i<=n;i++) {
        int k;
        cin>>k;
        s.insert(k);
        if ((*it)<=k) {
            if (i% 2 ==1)
                it++;
        }
        else if ((*it)>k) {
            if (i%2==0) {
                it--;
            }
        }
        cout << *it << "\n";
    }
}