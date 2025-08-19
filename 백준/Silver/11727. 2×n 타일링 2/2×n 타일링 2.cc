#include <bits/stdc++.h>
using namespace std;
int arr[1002];
int main() {
    int n;
    cin >> n;
    arr[1]=1;
    arr[2]=arr[1]+2;
    for (int i=3; i<=n; i++) {
        arr[i]=(arr[i-1]+arr[i-2]*2)%10007;
    }
    cout <<arr[n];
}