#include <bits/stdc++.h>
using namespace std;
vector<int> arr(50002,1e9);
int main() {
    int n;
    cin >> n;
    arr[0]=0;
    for (int i = 1; i <= n; i++) {
        for (int j=1; j*j<=i; j++) {
            arr[i]=min(arr[i],arr[i-j*j]+1);
        }
    }
    cout << arr[n];
}