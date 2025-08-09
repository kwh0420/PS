#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10];
int input_arr[10];
int vis[10002];
vector<array<int,10>> v;
void N_M(int depth,int n) {
    if (depth == M) {
        array<int, 10> temp;
        copy(arr, arr + M, temp.begin());
        v.push_back(temp);
        return;
    }
    for (int i=0; i<N; i++) {
        if (vis[i]) {continue;}
        vis[i] = 1;
        arr[depth] = input_arr[i];
        N_M(depth+1,i+1);
        vis[i] = 0;
    }
}
int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> input_arr[i];
    }
    sort (input_arr,input_arr+N);

    N_M(0,0);
    sort(v.begin(), v.end());

    v.erase(unique(v.begin(),v.end()), v.end());

    for (auto i : v) {
        for (int j=0; j<M; j++) {
            cout << i[j] << " ";
        }
        cout << endl;
    }
}