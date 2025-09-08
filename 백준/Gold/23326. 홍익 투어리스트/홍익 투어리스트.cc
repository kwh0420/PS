#include <bits/stdc++.h>
using namespace std;
long long int N,Q;
set<long long int> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int cur=0;
    cin>>N>>Q;
    for(int i=0;i<N;i++) {
        int t;
        cin>>t;
        if (t==1) {
            s.insert(i);
        }
    }
    for (int i=0;i<Q;i++) {
        int command;
        cin>>command;
        if (command==1) {
            int num=0;
            cin>>num;
            if (s.find(num-1)!=s.end()) {
                s.erase(num-1);
            }
            else {
                s.insert(num-1);
            }
        }
        else if (command==2) {
            long long int num;
            cin>>num;
            cur= (cur+num)%N;
        }
        else if (command==3) {
            if (s.empty()) {
                cout << -1<<"\n";
            }
            else {
                auto firs= s.lower_bound(cur);
                if (firs!=s.end()) {
                    cout << (*firs)-cur <<"\n";
                }
                else {
                    auto sec= s.begin();
                    cout << ((*sec)-cur+N)%N<<"\n";
                }
            }
        }
    }
}

