#include <bits/stdc++.h>
using namespace std;
int arr[1002][1002];
long long int val=0;
set<pair<int,int>>s;
int main() {
    int n,m;
    cin >> n >>m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int k;
            cin >>k;
            arr[i][j]=k;
            val+= k;
        }
    }
    for (int i=0; i<n; i++) {
        int x,y;
        int maxval=-1e9;
        for (int j=0; j<m; j++) {
            if (maxval < arr[i][j]) {
                x=i;
                y=j;
                maxval=arr[i][j];
            }
        }
        s.insert(make_pair(x,y));
    }
    for (int i=0; i<m; i++) {
        int x,y;
        int maxval=-1e9;
        for (int j=0; j<n; j++) {
            if (maxval < arr[j][i]) {
                x=j;
                y=i;
                maxval=arr[j][i];
            }
        }
        s.insert(make_pair(x,y));
    }
    for (auto i : s) {
        auto [x,y]= i;
        val-=arr[x][y];
    }
    cout << val;
}