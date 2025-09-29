#include <bits/stdc++.h>
using namespace std;
int Set[10];
bool check_int(int num) {
    if (num==0) {
    if (Set[0]==1) {return 0; }
    else return 1;}
    while (num>0) {
        if (Set[num%10]) {return false;}
        num/=10;
    }
    return true;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < m;i++) {
        int k;
        cin >> k;
        Set[k] = 1;
    }
    int minval = abs(n-100);
    for (int i=0; i<2000000; i++) {
        if (check_int(i)) {
            minval = min(minval, abs(n-i)+(int)((i!=0)?log10(i)+1:1));
        }
    }
    cout << minval;
}