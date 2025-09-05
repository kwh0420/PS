#include <bits/stdc++.h>
using namespace std;
int arr[10000000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        arr[a+1000001]++;
    }
    for (int i=0; i<=2000005;i++) {
        while (arr[i]--) {
            cout << i-1000001<<'\n';
        }
    }
}