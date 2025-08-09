#include <bits/stdc++.h>
using namespace std;
int N;
pair<int,int> arr[10];
#define S first
#define W second
int result=0;
int compare(int depth) {
    for (int i=0; i<N; i++) {
        if (i==depth) {continue;}
        if (arr[i].S>0) {
            return 0;
        }
    }
    return 1;
}
void egg(int depth) {
    if (depth==N || compare(depth)) {
        int cnt=0;
        for (int i=0; i<N; i++) {
            if (arr[i].S<=0) {
                cnt++;
            }
        }

        if (cnt > result) {
            result = cnt;
        }
        return;
    }
    else if (arr[depth].S<=0) {
        egg(depth+1);
    }
    else {
        for (int i=0; i<N; i++) {
            if (i == depth) {
                continue;
            }
            if (arr[i].S<=0) {
                continue;
            }
            arr[depth].S -=arr[i].W;
            arr[i].S -= arr[depth].W;
            egg(depth+1);
            arr[depth].S +=arr[i].W;
            arr[i].S += arr[depth].W;

        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i].S >> arr[i].W;
    }
    egg(0);
    cout << result << endl;
}