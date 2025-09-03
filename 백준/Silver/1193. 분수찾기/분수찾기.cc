#include <bits/stdc++.h>
using namespace std;
int main() {
    int X;
    cin >> X;
    int cnt=0;
    int k=0;

    while (((k)*(k+1)/2)<X) {
        k++;
    }
    int l = (k-1)*(k)/2;
    if (k%2==0)
    cout << X-l<<"/"<<k+1+l-X ;
    else {
        cout <<k+1+l-X <<"/"<< X-l;

    }
}