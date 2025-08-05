#include <bits/stdc++.h>
using namespace std;
int graph[100002];
int visited[100002];
bool circulation[100002];
#define NOT_VISITED 0
#define CYCLE -1
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;
    for (int i=0; i<T; i++){
        for (int j=0; j<100002; j++) {
            visited[j]=NOT_VISITED;
            graph[j]=-1;
        }
        int n;
        cin>>n;
        for (int k=1; k<=n; k++) {
            cin >> graph[k];
        }
        int sum=0;
        for (int k=1; k<=n; k++) {
            int now = k;
            if (visited[now] != NOT_VISITED) {
                continue;
            }
            visited[now] = k;
            while (1) {
                now=graph[now];
                if (visited[now] != NOT_VISITED) {
                    if (visited[now]==k) {
                        sum++;
                        for (int i=graph[now];i!=now;i=graph[i]) {
                            sum++;
                        }
                    }
                    break;
                }
                visited[now]=k;
            }
        }
        cout <<n-sum <<"\n";

    }
}