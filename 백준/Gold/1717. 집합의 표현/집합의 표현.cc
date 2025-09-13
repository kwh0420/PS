#include <bits/stdc++.h>
using namespace std;
int n,m;
int p[1000002];
int find1(int i) {
      if (p[i] <0) {
          return i;
      }
    return p[i]=find1(p[i]);
}
bool union1(int u,int v) {
    u=find1(u);
    v=find1(v);
    if (u==v) return false;
    if (p[v]<p[u]) {
        swap(u,v);
    }
    if (p[u]==p[v]) {
        p[u]--;
    }
    p[v]=u;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);


    cin>>n>>m;
    for(int i=0;i<=n;i++) {
        p[i]=-1;
    }
    for(int i=1;i<=m;i++) {
        int command,a,b;
        cin>>command>>a>>b;
        if (command==0) {
            union1(a,b);
        }
        else {
            int u=find1(a);
            int v=find1(b);
            if (u==v) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

}