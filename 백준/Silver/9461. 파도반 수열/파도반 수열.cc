#include <bits/stdc++.h>
using namespace std;
long long int c[102];
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int k=0;
        cin >> k;
        c[0]=1;
        c[1]=1;
        c[2]=1;
        for (int i=3; i<k; i++) {
            c[i]=c[i-2]+c[i-3];
        }
        cout << c[k-1] << '\n';
    }
}