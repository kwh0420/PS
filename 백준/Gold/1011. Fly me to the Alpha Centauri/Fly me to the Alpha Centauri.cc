#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
        long long int a,b;
        cin >> a >> b;
        long long int k=b-a;
        int range= sqrt(k);
        if (k==range*range) {
            cout << 2*range-1;
        }
        else  if (k>range*range+range){
            cout << 2*range+1;
        }
        else {
            cout << 2*range;
        }
        cout << "\n";
    }
}