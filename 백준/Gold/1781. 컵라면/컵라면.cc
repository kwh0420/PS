#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<pair<long long int,long long int>>v;
priority_queue<long long int,vector<long long int>,greater<long long int>>q;
 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
    cin >> n;
    for (long long int i = 1; i <= n; i++) {
        long long int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    for (long long int i = 0; i < n; i++) {
        if (q.size() >=v[i].first) {
            if (q.top() < v[i].second) {
                q.pop();
                q.push(v[i].second);
            }
        }
        else {
            q.push(v[i].second);
        }
    }
    long long int sum=0;
    while (!q.empty()) {sum+=q.top(); q.pop();}
    cout << sum ;
}