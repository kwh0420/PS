#include <bits/stdc++.h>
using namespace std;
int arr[500001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int N;
    cin >> N;
    for (int i = 0; i < N ; i++) {
    cin >> arr[i];
    }
    sort(arr, arr+N);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        cout << binary_search(arr, arr+N, k)<< " ";
    }
}