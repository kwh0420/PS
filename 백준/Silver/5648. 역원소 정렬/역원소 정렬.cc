#include <bits/stdc++.h>
using namespace std;
long long int n;
priority_queue<long long int,vector<long long int>,greater<long long int>>q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (long long  int i = 0; i < n; i++) {
        long long int a;
        cin >> a;
        long long int temp=0;
        while (a>0) {
            temp*=10;
            temp+=a%10;
            a/=10;
        }
        q.push(temp);
    }
    for (long long int i = 0; i<n; i++) {
        cout << q.top() << "\n";
        q.pop();
    }
}