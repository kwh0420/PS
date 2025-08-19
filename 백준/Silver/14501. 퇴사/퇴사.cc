#include <bits/stdc++.h>
using namespace std;
int consult[15][2];
int c[15];
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> consult[i][0] >> consult[i][1];
        if (n-i<consult[i][0]) {
            consult[i][1]=0;
        }
        c[i]=consult[i][1];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if ((i-j>=consult[j][0]) && n-i>=consult[i][0]) {
                c[i]=max(c[j]+consult[i][1],c[i]);
            }
        }
    }
    cout << *max_element(c,c+n);
}