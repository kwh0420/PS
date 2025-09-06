#include <bits/stdc++.h>
using namespace std;
unordered_set<string> as;
 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int n;
     cin>>n;
     for (int i=0; i<n; i++) {
         string s, query;
         cin>>s>>query;
         if (query=="enter") {
             as.insert(s);
         }
         else {
             as.erase(s);
         }
     }
     vector<string> v(as.begin(), as.end());
     sort(v.begin(), v.end(),greater<string>());
     for (auto i : v) {
         cout << i << "\n";
     }

}
