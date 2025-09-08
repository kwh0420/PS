#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
typedef struct {
	int x;
	int y;
	int z;
	int c;
}test;
test flag[4] = {{1,0},{0,1},{-1,0},{0,-1}};
vector<vector<int>> v;
vector<vector<int>> visit1;
vector<vector<int>> visit2;

int qq;
int ww;
int cc;
int ee;
int kwh = 0;
int bfs() {
	queue<test>q;
	test t = { 0,0,0,0 };
	q.push(t);
	visit1[0][0] = 1;
	visit2[0][0] = 1;
	while (!q.empty()) {
		test temp = q.front();
		if (temp.x == n - 1 && temp.y == m - 1) {
			kwh = temp.c;
			return 1;
		}

		q.pop();
		for (int i = 0; i < 4; i++) {
			qq = temp.x + flag[i].x;
			ww = temp.y + flag[i].y;
			cc = temp.c + 1;
			if (0 <= qq&& qq < n && 0 <= ww &&ww < m) {
				ee = temp.z + v[qq][ww];
				if (ee == 0) {
					if (visit1[qq][ww]==1) {
						continue;
					}
				}
				else if (ee == 1) {
					if (visit2[qq][ww]==1) {
						continue;
					}
				}
				else {
					continue;
				}
				test real = { qq,ww,ee,cc };
				if (temp.z == 0) {
					visit1[qq][ww] = 1;

				}
				else {
					visit2[qq][ww] = 1;
				}
				q.push(real);
				//cout << "hang : " << qq << '\n' << "yeol: " << ww << '\n' << "count : " << cc << "\n"<< "wall : " << ee <<'\n' << "------------------" << "\n";
			}
		}
	}
	return 0;
}
int main() {
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m, 0));
	visit1 = vector<vector<int>>(n, vector<int>(m, 0));
	visit2 = vector<vector<int>>(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			v[i][j] = getchar() - '0';
		}
	}

	if (bfs()) {
		printf("%d", kwh+1);
	}
	else {
		printf("-1");
	}
}