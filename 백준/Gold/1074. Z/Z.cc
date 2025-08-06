#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
		unsigned long long int a=0, b=0, m = 1, n = 1, bex = 0;

		cin >> n >> a >> b;
		while (b >= m * 2) {
			m *= 2;
		}
		while (b >= 1) {
			if (b < m) {
				m /= 2;
				continue;
			}
			b -= m;
			bex += pow(m, 2);
			m /= 2;

		}
		m = 1;
		while (a >= m * 2) {
			m *= 2;
		}
		while (a >= 1) {
			if (a < m) {
				m /= 2;
				continue;
			}
			a -= m;
			bex += pow(m, 2) * 2;
			m /= 2;

		}
		cout << bex + a + b * 2;
}