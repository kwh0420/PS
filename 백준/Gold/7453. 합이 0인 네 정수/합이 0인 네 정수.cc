#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<long long int> input1;
vector<long long int> input2;
vector<long long int> input3;
vector<long long int> input4;
vector<long long int> sum1;
vector<long long int> sum2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (long long int i=0; i<n; i++) {
        long long int a,b,c,d;
        cin >> a >> b >> c >> d;
        input1.push_back(a);
        input2.push_back(b);
        input3.push_back(c);
        input4.push_back(d);
    }
    for (long long int i=0; i<n; i++) {
        for (long long int j=0; j<n; j++) {
            sum1.push_back(input1[i]+input2[j]);
            sum2.push_back(input3[i]+input4[j]);
        }
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    long long int cnt=0;

    for (long long int i=0; i<sum1.size(); i++) {
        cnt+=upper_bound(sum2.begin(),sum2.end(),-sum1[i])-lower_bound(sum2.begin(),sum2.end(),-sum1[i]);
    }
    cout<<cnt;
}