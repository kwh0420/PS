#include <bits/stdc++.h>
using namespace std;
int arr1[500001];
int arr2[500001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        cin>>arr1[i];
    }
    for(int i=0;i<M;i++) {
        cin>>arr2[i];
    }
    sort(arr1,arr1+N);
    sort(arr2,arr2+M);
    vector<int> ans;
    for(int i=0;i<N;i++) {
        if (!binary_search(arr2,arr2+M,arr1[i])) {
            ans.push_back(arr1[i]);
        };
    }
    cout<<ans.size()<<"\n";
    for (auto i: ans) {
        cout<<i<<" ";
    }
}