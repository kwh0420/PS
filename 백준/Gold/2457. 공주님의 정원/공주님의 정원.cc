#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v.push_back({100*a+b,100*c+d});
    }
    sort(v.begin(),v.end());
    int cur = 301;
    int start=0;
    int maxval=0;
    int cnt=0;
    if (v[0].first >301) {
        cout << 0;
        return 0;
    }
    for (int i=0; i<n; i++) {
        if (v[i].first > cur ) {
            if (maxval < v[i].first) {
                cout << 0;
                return 0;
            }
            cur=maxval;
            cnt++;
        }
        maxval = max(maxval,v[i].second);

        if (maxval >1130) {
            cout<<++cnt;
            return 0;
        }
    }


    cout << 0;
}