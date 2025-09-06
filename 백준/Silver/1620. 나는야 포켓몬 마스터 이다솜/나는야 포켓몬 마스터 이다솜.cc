#include <bits/stdc++.h>
using namespace std;
long long int T,N,M;
unordered_map<string ,int> as;
string sa[100005];
 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
    int n,m;
    cin >> n >> m;
     for(int i=0;i<n;i++) {
         string s;
         cin >> s;
         as[s]=i;
         sa[i]=s;
     }
     for(int i=0;i<m;i++) {
        string q;
         cin >> q;
         if (isdigit(q[0])) {
             int c= stoi(q);
             cout << sa[c-1] << "\n";
         }
         else {
             cout << as[q]+1<<"\n";
         }
     }
}
