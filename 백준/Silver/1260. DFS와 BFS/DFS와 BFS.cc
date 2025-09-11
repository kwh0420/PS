#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool visited[1001];
vector<vector<int>> graph;
queue<int> q;
bool dfs(int x)
{
	if (x == 0) {
		return false;
	}
	else {
		visited[x] = true; //방문한 노드 방문처리
		cout << x << " ";
		for (int i = 0; i < graph[x].size(); i++) {//그래프[x]의 사이즈 크기만큼 인접한 노드 탐색
			int y = graph[x][i];
			if (!visited[y]) { //인접한 노드 탐색
				dfs(y);
			}
		}
		return true;
	}
}
bool bfs(int x) {
	cout << "\n";
	q.push(x); // 초기값 설정
	visited[x] = true;
	cout << x << ' '; // 초기값 출력
	while (!q.empty()) {
		int x = q.front();
		q.pop(); // 프론트 값 제외
		if (x == 0) {
			return false;
		}
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i]; // 프론트값 인접 노드 탐색
			if (!visited[y]) {
				q.push(y); // 프론트값 인접 노드 삽입
				visited[y] = true;
				cout << y << ' ';
			}

		}
	}
	return true;
}

int main() {
	int node, road, start_point; //정점개수, 간선개수, 시작점
	int point1, point2;//연결할 노드 1, 노드2
	cin >> node >> road >> start_point;
	cin.ignore();
	graph.assign(node + 1, vector<int>()); // graph n*n 벡터 만들기
	for (int i = 0; i < road; i++) {//노드연결 입력받기
		cin >> point1 >> point2;
		graph[point1].push_back(point2); // 양방향 노드 연결
		graph[point2].push_back(point1);
		cin.ignore();
	}
	for (int i = 1; i <= node; i++) {// 오름차순 정렬
		sort(graph[i].begin(), graph[i].end());
	}
	fill_n(visited, 1001, false); // visited값 초기화
	dfs(start_point); //dfs 실행
	fill_n(visited, 1001, false); //visited값 초기화
	bfs(start_point); //bfs 실행

}