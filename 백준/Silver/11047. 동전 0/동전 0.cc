#include <bits/stdc++.h>
using namespace std;
int N,K;
int coin[10];
int main() {
  cin >> N >> K;
  for(int i=0;i<N;i++) {
    cin>>coin[i];

  }
  int cnt=0;
  for (int i=N-1; i>=0; i--) {
    while (K>=coin[i]) {
      K-=coin[i];
      cnt++;
    }
  }
  cout << cnt;
}