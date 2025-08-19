#include <bits/stdc++.h>
using namespace std;
int c[1002];
int k[1002];
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> c[i];
        k[i]=1;
    }
    int sum=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (c[i] > c[j]) {
                k[i]=max(k[i],k[j]+1);
            }
        }
    }
    cout <<*max_element(k,k+n) ;
}