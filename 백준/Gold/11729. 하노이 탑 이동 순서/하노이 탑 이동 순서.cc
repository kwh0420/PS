#include <iostream>
#include <vector>
using namespace std;
int a;
vector<pair<int,int>> v;
void hannoi(int n, int d1, int d2, int d3) {
	if (n == 1) {
		v.push_back({ d1,d3 });
		return;
	}

	else {
		hannoi(n - 1, d1, d3, d2);
		v.push_back({ d1,d3 });
		hannoi(n - 1, d2, d1, d3);
	}
}
int main() {
	cin >> a;

	hannoi(a,1,2,3);
	cout << v.size()<< endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
}