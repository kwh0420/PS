#include <bits/stdc++.h>
using namespace std;
long long int s1[500003];
long long int s2[500003];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n,m;
    cin >> n >> m;
    long long int a,b;
    cin >> a >> b;
    for (long long int i=0; i<n; i++) {
        long long int k;
        cin >> k;
s1[i] = k;
    }
    for (long long int i=0; i<m; i++) {
        long long int p;
        cin >> p;
    s2[i] = p;
    }
    sort(s1, s1+n);
    sort(s2, s2+m);
    s1[n]=1e18;
    s2[m]=1e18;
    long long int pointer1 =0;
    long long int pointer2 =0;
    long long int maxdis=1e18;
    long long int cnt=0;
    while (pointer1<n && pointer2<m) {

        if (maxdis > abs(s1[pointer1]-s2[pointer2])) {
            maxdis = abs(s1[pointer1]-s2[pointer2]);
            cnt=1;
        }
        else if (maxdis == abs(s1[pointer1]-s2[pointer2])) {
            cnt ++;
        }
        if (abs(s1[pointer1+1]-s2[pointer2])<abs(s1[pointer1]-s2[pointer2+1])  ) {
            pointer1++;
        }
        else {
            pointer2++;
        }
    }
    cout << maxdis + abs(a-b) << " " << cnt ;
}