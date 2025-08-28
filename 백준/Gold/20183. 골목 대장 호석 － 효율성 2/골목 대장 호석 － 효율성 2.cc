#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int,int>> v[100001];
long long int dist[100001];
long long int pre[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  long long int N;
  long long int M;
  long long int A;
  long long int B;
  long long int C;
  cin >> N >> M >> A >> B >>C;
  for (long long int i=0; i<M; i++) {
    long long int U,V,W;
    cin >> U >> V >> W;
    v[U].push_back(make_pair(W,V));
    v[V].push_back(make_pair(W,U));
  }
  priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>q;
  q.push({0,A});
  pre[B]=-1;
  for (long long int i=1; i<=N; i++) {
    pre[i]=1e18;
  }
  pre[A]=0;

  while(!q.empty()) {
    auto [cur_val,cur_node]=q.top();
    q.pop();
    //cout << cur_node << " " << cur_val << endl;

    for (auto[nxt_val,nxt_node]: v[cur_node]) {
      //cout << pre[nxt_node] << " " << pre[cur_node] << " " << nxt_val << endl;
      if ( cur_val + nxt_val >C || (pre[nxt_node]<=max(pre[cur_node],nxt_val))){continue;} //다익스트라 알고리즘을 변형해서 최단거리가 아니더라도 우선순위큐에 들어올 수 있게 했음. 단, 현재 최대값보다 작아야함.
      pre[nxt_node]=max(pre[cur_node],nxt_val);
      q.push({cur_val+nxt_val,nxt_node});
    }

  }
  cout << ((pre[B]==1e18)?-1:pre[B]);

}
