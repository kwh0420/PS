#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,P,Q;
map<ll,ll> mp;
ll go (ll n) {
    if (mp[n]!=0) return mp[n];
    if (n==0)
        return mp[n]=1;
    return mp[n]=go(n/P)+go(n/Q);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> P >> Q;
    cout << go(N) << "\n";


}