#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({100*a + b, 100*c + d}); // 날짜파싱을 이런식으로 할 수 있음. 어차피 크기순으로 정렬만 할거고 날짜간 차이를 계산하진 않기때문에 상관없음.
    }

    // 시작 날짜 기준 오름차순 정렬
    sort(v.begin(), v.end());

    int cur = 301;     // 현재 덮고 있는 날짜 (3월 1일 시작)
    int maxval = 0;    // 현재 범위에서 가장 늦게 지는 꽃의 날짜
    int cnt = 0;       // 선택한 꽃의 개수

    // 3월 1일 이전에 시작하는 꽃이 하나도 없는 경우
    if (v[0].first > 301) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        // 현재 날짜(cur) 이후에 피는 꽃을 만나면,
        // 지금까지 찾은 maxval로 덮어야 한다.
        if (v[i].first > cur) {
            if (maxval <= cur) {  // 이어질 수 없는 경우
                cout << 0;
                return 0;
            }
            cur = maxval;  // 갱신
            cnt++;
        }

        // 가장 늦게까지 덮을 수 있는 날짜 갱신
        maxval = max(maxval, v[i].second);

        // 11월 30일을 넘어서 덮으면 종료
        if (maxval > 1130) {
            cout << cnt + 1;
            return 0;
        }
    }

    cout << 0; // 끝까지 갱신 못한 경우
}

