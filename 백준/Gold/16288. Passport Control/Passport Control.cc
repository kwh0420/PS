#include <bits/stdc++.h>
using namespace std;
int arr[102];
int vis[102];
set<int> s;
int main() {
    int N,K;
    cin>>N>>K;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }
    int cnt=0;
    for (int i=0;i<N; i++) {
        auto it=s.lower_bound(arr[i]);
        if (it != s.begin()) {it--;s.insert(arr[i]);s.erase(it);}
        else{s.insert(arr[i]);};
        //for ( auto j : s) {cout << j;}cout << endl;
        if (s.size() >K){cout << "NO";return 0;}
    }
    cout << "YES";
}