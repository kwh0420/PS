#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>> pq;
multiset<int> s; //set은 중복되는 원소 저장하지 않음을 까먹고 헤맴.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int K=N;
    while (N--) {
        int height,cnt;
        cin >> height >> cnt;
        pq.push(make_pair(height,cnt));
    }
    while (K--) {
        auto[height,cnt] = pq.top();
        pq.pop();
        auto it= s.lower_bound(cnt);
        if (it == s.begin()) {
            s.insert(1);
        }
        else {
            it--;
            s.insert((*it)+1);
            s.erase(it);
        }
    }
    cout << s.size();

}
