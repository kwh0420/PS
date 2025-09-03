#include <bits/stdc++.h>
using namespace std;
vector<bool> v(123457*2,1);
int main() {
    v[1]=0;
    for (int i = 2; i*i <= 123457*2; i++) {
        if (!v[i]){continue;}
        for (int j = i*i; j <= 123457*2; j+=i) {
            v[j] = 0;
        }
    }
    while (1) {
        int n;
        cin >> n;
        if (n==0) {
            break;
        }
        int cnt=0;
        for (int i = n+1; i <= 2*n; i++) {
            if (v[i]) {
                cnt++;
            }
        }
        cout <<cnt << "\n";
    }
}