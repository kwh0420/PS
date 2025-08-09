#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10002];
int vis[10002];
int result[10002];
void N_M(int depth,int n) {
    if (depth == M) {
        for (int i=0; i<M ;i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    else {
        int temp =0;
        for (int i=n; i<N;i++) {
            if (temp != arr[i]) { // N_M(n-1) + temp 가 새로운 배열이다. 이때 중복되는 temp를 넣지 않으면 중복 배열이 발생하지 않음.
                temp=arr[i];
                result[depth]= arr[i];
                N_M(depth+1,i+1);
            }
        }
    }
}
int main () {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    N_M(0,0);

}
