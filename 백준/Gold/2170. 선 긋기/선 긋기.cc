#include <bits/stdc++.h>

using namespace std;

long long int leftval;
long long int rightval;
vector<pair<long long int, long long int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
        long long int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    leftval=v[0].first;
    rightval=v[0].second;
    long long int sum=rightval-leftval;
    for (long long int i = 1; i < v.size(); i++) {
        if (rightval<=v[i].first) {
            leftval=v[i].first;
            rightval=v[i].second;
            sum+=rightval-leftval;
            continue;
        }
        else {
            if (v[i].second>rightval){
                sum+=v[i].second-rightval;
                rightval = v[i].second;
            }
        }

    }
    cout << sum ;
}