#include <bits/stdc++.h>
using namespace std;
int cnt;
int result[10000000][2];
void hannoi(int n, int a, int b) {
    if (n==1) {
        result[cnt][0]=a;
        result[cnt][1]=b;
        cnt++;


        return;
    }
    hannoi(n-1,a, 6-a-b);
    hannoi(1,a,b);
    hannoi(n-1,6-a-b,b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    hannoi(k,1,3);
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        cout << result[i][0] << " " << result[i][1];
        cout <<"\n";
    }
}