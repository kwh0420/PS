#include <bits/stdc++.h>
using namespace std;
long long int n,c;
map<int,int,greater<int>>cnt;
map<int,int> vis;
int arr[1002];
vector<int>v[1002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >>c;
    for (int i=0; i<n; i++) {

        cin >> arr[i];
        cnt[arr[i]]++;
        vis[arr[i]]=0;
    }
    for (int i=0; i<n; i++) {
        if (!vis[arr[i]])
        v[cnt[arr[i]]].push_back(arr[i]);
        vis[arr[i]]=1;
    }
    for (int i=n; i>0; i--) {
        for (auto j : v[i]) {
            for (int k=0 ; k<i ; k++)
                cout << j <<" ";
        }
    }

}
