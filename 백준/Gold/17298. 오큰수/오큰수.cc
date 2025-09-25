#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>>pq;
int N;
int arr[1000002];
int result[1000002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    fill(result, result + N, -1);
    for (int i = 0; i < N; i++) {
        while (!pq.empty() && (pq.top().first < arr[i])) {
            result[pq.top().second] = arr[i];
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
    }
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}
