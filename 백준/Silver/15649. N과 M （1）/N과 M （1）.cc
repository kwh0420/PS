#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[9];
int visited[9];
void func(int k) {
    if (k==M) {
        for (int i=0; i<M; i++) {
            cout<<arr[i];
            cout << '\n';

        }
        return;
    }
    else {
        for (int i=1; i<=N;i++) {
            if (visited[i]==0) {
                visited[i]=1;
                arr[k]=i;
                func(k+1);
                visited[i]=0;
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    func(0);
}