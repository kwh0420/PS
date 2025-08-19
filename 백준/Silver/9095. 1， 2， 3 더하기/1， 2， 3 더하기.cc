#include <bits/stdc++.h>
using namespace std;
int k[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p=0;
    cin >> p;
    for(int i=0;i<p;i++) {
        int n;
        cin >> n;
        k[1]=1;
        k[2]=2;
        k[3]=4;
        for (int i=4; i<=n; i++) {
            k[i] = k[i-1]+k[i-2]+k[i-3];
        }
        cout << k[n]<< "\n";
    }
}