#include <bits/stdc++.h>
using namespace std;
#define ll long long long long int 
long long int  dist[102][102];
long long int  n,m;

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (long long int  i = 1; i <= n; i++) {
        for (long long int  j=1; j<=n; j++) {
            dist[i][j]=1e18;
        }
    }
    for (long long int  i=0; i<m; i++) {
        long long int  a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
    }
    for (long long int  i = 1; i <= n; i++) {dist[i][i]=0;}
    for (long long int  i=1; i<=n; i++) {
        for (long long int  j=1; j<=n; j++) {
            for (long long int  k=1; k<=n; k++) {
                if (dist[j][k]>dist[j][i]+dist[i][k]) {
                    dist[j][k] = dist[j][i]+dist[i][k];
                }
            }
        }
    }
    for (long long int  j=1; j<=n; j++) {
        for (long long int  k=1; k<=n; k++) {
            cout << ((dist[j][k]==1e18)?0:dist[j][k]) <<" ";
        }
        cout <<"\n";
    }
}