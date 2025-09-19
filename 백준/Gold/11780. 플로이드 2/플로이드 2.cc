#include <bits/stdc++.h>
using namespace std;
long long int  n,m;
long long int  arr[102][102];
long long int  nxt[102][102];
 int  main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     cin>>n>>m;
     for(long long int  i=1;i<=n;i++)
         for(long long int  j=1;j<=n;j++)
             arr[i][j]=1e17;
     for (long long int  i=0 ; i<m; i++) {
         long long int  a,b,c;
         cin>>a>>b>>c;
         if (arr[a][b]>c) {
             arr[a][b]=c;
             nxt[a][b]=b;
        }
     }
     for(long long int  i=1;i<=n;i++) {
         arr[i][i]=0;
     }
    for(long long int  i=1;i<=n;i++) {
        for (long long int  j=1;j<=n;j++) {
            for (long long int  k=1;k<=n;k++) {
                if (arr[j][k]>arr[j][i]+arr[i][k]) {
                    arr[j][k]=arr[i][k]+arr[j][i];
                    nxt[j][k]=nxt[j][i];
                }
            }
        }
    }
    for(long long int  i=1;i<=n;i++) {
        for (long long int  j=1;j<=n;j++) {
            if (arr[i][j]==1e17) cout << 0 << " ";
            else cout << arr[i][j] << " ";
        }
        cout <<"\n";
    }
    for(long long int  i=1;i<=n;i++) {
        for (long long int  j=1;j<=n;j++) {
            if ((arr[i][j]==0)||(arr[i][j]==1e17)) { cout << 0 << "\n";continue;}
            long long int  cur=i;
            long long int  dest=j;
            vector<int> route;
            while (1) {
                route.push_back(cur);
                if (cur == dest){break;}
                cur=nxt[cur][dest];
            }
            cout << route.size() <<" ";
            for (auto i : route) {
                cout << i <<" ";
            }
            cout <<"\n";
        }
    }
}