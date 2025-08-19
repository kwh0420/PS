#include <bits/stdc++.h>
using namespace std;
long long int arr[1002];
int main() {
    int n;
    cin >> n;
    arr[1]=1;
    arr[2]=1;
    arr[3]=2;
    for (int i=4; i<=n; i++) {
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout <<arr[n];
}