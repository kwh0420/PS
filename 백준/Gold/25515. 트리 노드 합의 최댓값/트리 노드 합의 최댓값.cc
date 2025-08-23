#include <bits/stdc++.h>
using namespace std;
long long n;
long long w[100002];
vector<long long> v[100002];
long long dp[100002];
long long go(long long cur,long long par) {
    if (v[cur].size()==1 && cur !=0) { // cur==1과 cur==0을 헷갈림.. 노드의 첫 번호가 0인지 1인지 잘 확인해야한다.
            return w[cur];
    }
    long long sum=0;
    for (long long i : v[cur]) {
        if (i== par) {
            continue;
        }
        long long result = go(i,cur);
        if (result<0) {
            continue;
        }
        sum +=result;
    }
    return dp[cur]=sum+w[cur];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (long long i=0; i<n-1; i++) {
        long long a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (long long i=0; i<n; i++) {
        cin>>w[i];
    }

    cout << go(0,-1);
    cout << "\n";

}
