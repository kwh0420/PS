#include <bits/stdc++.h>
using namespace std;
int arr[1000003];    int cnt=0;
int lc[1000003];
int rc[1000003];
void dfs(int cur) {
    if (cur==0){return;}
    dfs(lc[cur]);
    dfs(rc[cur]);
    cout << cur <<"\n";
}
int main() {
    int a;
    while (cin >> a) {
        arr[cnt++]=a;
    }
    set<int> s;
    s.insert(arr[0]);
    for (int i = 1; i < cnt; i++) {
        if (arr[i-1]>arr[i]) {
            lc[arr[i-1]]=arr[i];
        }
        else {
                int cur=i;
                auto it =s.lower_bound(arr[cur]);
                int k = *(prev(it));
                s.erase(prev(it));
                rc[k]=arr[i];
        }
        s.insert(arr[i]);

    }
    dfs(arr[0]);
}