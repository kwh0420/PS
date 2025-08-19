#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[1000003];
int route[1000003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    arr[1]=0;
    route[1]=0;
    for (int i = 2; i <= N; i++) {
        arr[i]=arr[i-1] +1;
        route[i] = i-1;
        if (i%2 ==0 && arr[i] > arr[i/2]+1) {
            arr[i]=arr[i/2]+1;
            route[i]=i/2;
        }
        if (i%3==0 && arr[i] > arr[i/3]+1) {
            arr[i]=arr[i/3]+1;
            route[i]=i/3;
        }
    }
    cout << arr[N] << "\n";
    int cur=N;
    while (1) {
        cout <<cur << " ";

        if (cur ==1) {
            return 0;
        }
        cur = route[cur];

    }
}