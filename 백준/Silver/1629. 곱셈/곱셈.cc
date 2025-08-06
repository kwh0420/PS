#include <bits/stdc++.h>
#include <iostream>
#include <bits/ostream.tcc>
using namespace std;
long long gop(long long a, long long b, long long c) {
    if (b==1){return a%c;}
    long long t = gop(a, b/2, c);
    if (b%2 == 1)return ((t*t)%c*a)%c;
    else return (t*t)%c;
}
int main() {
    long long a,b,c;
    cin >> a >> b >> c;
    cout << gop(a,b,c);
}