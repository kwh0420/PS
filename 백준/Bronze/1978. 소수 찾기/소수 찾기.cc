#include <bits/stdc++.h>
using namespace std;
int cnt=0;
void go(int k) {
    if (k==1 ){return;}
    for (int i=2; i*i<=k; i++) {
        if (k%i==0) {
            return;
        }
    }
    cnt++;
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        go(k);
    }
    cout << cnt;
}