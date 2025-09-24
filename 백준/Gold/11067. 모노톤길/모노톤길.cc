#include <bits/stdc++.h>
using namespace std;
map<long long int ,vector<long long int >> mp;
vector<pair<long long int ,long long int >> v;
 int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int  t;
    cin>>t;
    for (long long int  i=0;i<t;i++) {
        long long int  n;
        cin>>n;
        for (long long int  j=0;j<n;j++) {
            long long int  x,y;
            cin>>x>>y;
            mp[x].push_back(y);
        }
        for (auto &i : mp) {
            sort(i.second.begin(),i.second.end());
        }
        long long int nextint=0;
        for (auto i : mp) {
            long long int  st,en;
            if (i.second[0]>= nextint) {
                en = i.second.size();
                st = 0;
                for (long long int  j=st; j<en; j++) {
                    v.push_back({i.first,i.second[j]});
                    nextint = i.second[j];
                }
            }
            else {

                st = i.second.size()-1;
                en = 0;
                for (long long int  j=st; j>=en; j--) {
                    v.push_back({i.first,i.second[j]});
                    nextint = i.second[j];
                }
            }
        }
        long long int  c;
        cin>>c;
        for (long long int  j=0;j<c;j++) {
            long long int  x,y;
            cin>>x;
            cout << v[x-1].first << " " << v[x-1].second << "\n";
        }
        v.clear();
        mp.clear();
    }
}