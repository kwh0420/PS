#include <bits/stdc++.h>
using namespace std;
pair<int,int>arr [502];
int check_arr[502][502];
int cnt[502];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        arr[i] = make_pair(a,b);
    }
    sort(arr,arr+n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), arr[i].second);
        if (it == v.end()) {v.emplace_back(arr[i].second);}
        else{*it = arr[i].second;}
    }
    cout << n- v.size();
}