#include <iostream>
#include <vector>

using namespace std;

// 인접 리스트 DFS 사용, 깊이 == 5 ? 1 : 0

int n, m;
vector<vector<int>> graph; // 그래프(인접 리스트)
vector<bool> visit;
bool isvalid;

void DFS(int current, int depth);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  // 초기화
  graph.resize(n);
  visit = vector<bool>(n, false);

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    // 무방향 그래프
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i = 0; i < n; i++){
    // 모든 노드에 대한 DFS
    DFS(i, 1);

    if(isvalid) break;
  }

  if(isvalid) cout << 1 << "\n";
  else cout << 0 << "\n";

  return 0;
}

void DFS(int current, int depth){
  if(depth == 5 || isvalid){
    isvalid = true;
    return;
  }

  visit[current] = true;

  for(auto a : graph[current]){
    if(!visit[a]) DFS(a, depth + 1);
  }

  visit[current] = false;
}