#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int two=0;
    int five=0;
    for(int i=2;i<=n;i++) {
        int k=i;
        while (k%2==0) {
            k/=2;
            two++;
        }
        while (k%5==0) {
            k/=5;
            five++;
        }
    }
    cout << min(two,five);
}