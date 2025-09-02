#include <iostream>
#include <vector>
using namespace std;
int bino_coef(int n, int r) {
	vector<vector<int>> cache(n + 1, vector<int>(r + 1, 0));
	for (int i = 0; i < r + 1; i++) {
		cache[i][0] = 1;
	}
	for (int i = 0; i < n + 1; i++) {
		cache[i][0] = 1;
	}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= r; j++) {
				cache[i][j] = (cache[i - 1][j] + cache[i - 1][j - 1]) % 10007;
			}
		}
		return cache[n][r];
	
}
int main() {
	int n, m;
	cin >> n >> m;
	cout <<bino_coef(n, m);
}