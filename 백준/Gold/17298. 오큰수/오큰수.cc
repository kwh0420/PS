#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>>pq; // pq를 우선순위 큐로 해야된다고 생각했다. 그런데 top>arr[i]를 유지하므로  pq는 최상단 수를 기준으로 오름차순으로 정렬된다. 따라서 스택으로 두어도 상관이 없다. (스택-> 우선순위큐 280ms -> 180ms)
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

