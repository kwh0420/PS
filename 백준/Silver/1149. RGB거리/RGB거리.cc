#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int k;
int max_index;
vector<vector<int>> t;
int main() {
	cin >> k;
	int m = 0;
	t.resize(k, vector<int>(3, 0));
	for (int i = 0; i < k; i++) {
		cin >> t[i][0] >> t[i][1] >> t[i][2];
	}
	for (int i = 1; i < k; i++) {
		t[i][0] += min(t[i - 1][1], t[i - 1][2]);
		t[i][1] += min(t[i - 1][0], t[i - 1][2]);
		t[i][2] += min(t[i - 1][0], t[i - 1][1]);
	}
	cout << *min_element(t[k - 1].begin(), t[k - 1].end());
}