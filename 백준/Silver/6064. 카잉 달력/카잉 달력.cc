#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<bool>prime(1000001,1);
int gcd(int a,int b) {
    return a%b==0?b:gcd(b,a%b);
}
int lcm(int a,int b) {
    return (a*b)/gcd(a,b);
}
void go(int a, int b, int c, int d, int l) {
    if (a==c){ c=0;}
    if (b==d){ d=0;}

    for (int i=c; i<=l;i+=a) {
        if (i==0){continue;}
        if (i%b==d){
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int l =lcm(a,b);
        go(a,b,c,d,l);
    }

}