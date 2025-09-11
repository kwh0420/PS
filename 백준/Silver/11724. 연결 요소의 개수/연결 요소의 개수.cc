#include <iostream>
#include <vector>
using namespace std;
int node, road;
int count123;
int graphstart, graphend;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> graph_count;
int bfs(int a) {
	if (!visited[a]) {
		count123++;
		visited[a] = true;
		for (int i = 0; i < graph[a].size(); i++) {
			bfs(graph[a][i]);
		}
		return 0;
	}
	else {
		return 0;
	}


}
int main() {
	cin >> node >> road;
	graph.resize(node + 1,vector<int>());
	visited.resize(node + 1);
	for (int i = 0; i < road; i++) {
		cin >> graphstart >> graphend;
		graph[graphstart].push_back(graphend);
		graph[graphend].push_back(graphstart);
	}
	for (int i = 1; i < node+1; i++) {
		count123 = 0;
		bfs(i);
		if (count123 != 0) {
			graph_count.push_back(count123);
		}
	}
	cout << graph_count.size();
	return 0;
}
