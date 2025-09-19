#include <bits/stdc++.h>
using namespace std;
long long int  arr[202][202];
long long int  N,M,C;
int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (long long int  i=1; i<=N; i++) {
        for (long long int  j=1; j<=N; j++) {
            arr[i][j]=1e18;
        }
    }
    for (long long int  i=0; i<M; i++) {
        long long int  a,b,c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b],c);
    }
    for (long long int  i=1; i<=N; i++) {
        arr[i][i]=0;
    }
    for (long long int  i=1; i<=N; i++) {
        for (long long int  j=1; j<=N; j++) {
            for (long long int  k=1; k<=N; k++) {
                if (arr[j][k] > arr[j][i] + arr[i][k]) {
                    arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }
    }

    cin >> C;
    vector <long long int > fr;
    for (long long int  i=0; i<C; i++) {
        long long int  k;
        cin >> k;
        fr.push_back(k);
    }
    vector<pair<long long int ,long long int > > s;
    for (long long int  i=1; i<=N; i++) {
        long long int  val=0;
        for (long long int  j=0; j<C; j++) {
            long long int  cur = fr[j];
            val = max(val,arr[cur][i]+arr[i][cur]);
        }
        s.push_back(make_pair(val,i));
    }
    sort(s.begin(),s.end());
    for (long long int  i=0; i<s.size(); i++) {
        if (i==s.size()-1) {cout << s[i].second ;break;}
        cout << s[i].second << " ";
        if (s[i].first!=s[i+1].first)break;
    }
}