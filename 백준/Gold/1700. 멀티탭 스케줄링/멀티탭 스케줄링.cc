#include <bits/stdc++.h>
using namespace std;
int N,K;
vector<int> v;
int arr[102];
int check[102];
int minval=0;
int minindex=0;
int check_ready(int idx) {
    for (int i=0; i<v.size(); i++) {
        if (v[i]==arr[idx]) {
            return 1;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    int cnt=0;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < K; i++) {

        if (check_ready(i)) {
            continue;
        }
        else if (v.size()<N) {
            v.push_back(arr[i]);
        }
        else {
                int target=-1;
                int maxval = -1;
            for (int j = 0; j < v.size(); j++) {
                int cur=K;
                for (int k=i+1; k<K; k++) {
                    if (v[j]==arr[k]) {
                        cur=k;
                        break;
                    }
                }
                if (cur>maxval) {
                    maxval=cur;
                    target=j;
                }
            }
            v[target]=arr[i];
            cnt++;
        }
    }
    cout << cnt;
}