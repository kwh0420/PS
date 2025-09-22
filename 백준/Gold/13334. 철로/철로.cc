#include <bits/stdc++.h>
using namespace std;
long long int  N;
long long int  arr[100002];
priority_queue<long long int ,vector<long long int >,greater<long long int >> q;
vector<pair<long long int , long long int >> v;
int  main() {
    cin >>N;
    for (long long int  i = 0; i < N; i++) {
        long long int  a,b;
        cin>>a>>b;
        if (a>b){swap(a,b);}
        v.push_back(make_pair(b,a));
    }
    long long int  D;
    cin>>D;
    sort(v.begin(),v.end());
    long long int  ans = 0;
    for (long long int  i = 0; i < N; i++) {
        q.push(v[i].second);
        while (!q.empty()&&v[i].first-D> q.top()) {q.pop();}
        ans = max(ans,(long long int )q.size());
    }
    cout <<ans;
}