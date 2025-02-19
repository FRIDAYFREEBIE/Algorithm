#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, m;
vector<vector<int>> tree;  // 트리
vector<int> depth;         // 노드의 깊이
int parent[21][100001];    // 부모
vector<bool> visited;      // 방문
int kMax;

void BFS(int root);
int LCA(int a, int b);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  tree.resize(n + 1);
  depth.resize(n + 1);
  visited.resize(n + 1, false);

  for(int i = 0; i < n - 1; i++){
    int s, e;
    cin >> s >> e;
    tree[s].push_back(e);
    tree[e].push_back(s);
  }

  kMax = (int)log2(n);

  BFS(1); // 루트노드에서 탐색 시작

  // 부모 배열 구성
  for(int k = 1; k <= kMax; k++){
    for(int i = 1; i <= n; i++){
      // 부모가 존재할 때만 갱신
      if(parent[k - 1][i] != 0){
        parent[k][i] = parent[k - 1][parent[k - 1][i]];
      }
    }
  }

  cin >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    cout << LCA(a, b) << "\n";
  }

  return 0;
}

void BFS(int root){
  queue<int> q;
  q.push(root);
  visited[root] = true;
  depth[root] = 0; // 루트의 깊이는 0

  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int next : tree[current]){
      if(!visited[next]){
        visited[next] = true;
        q.push(next);
        parent[0][next] = current;        // 부모 노드 저장
        depth[next] = depth[current] + 1; // 깊이 설정
      }
    }
  }
}

int LCA(int a, int b){
  if(depth[a] < depth[b]){
    swap(a, b);
  }

  // 깊이 맞추기
  for(int k = kMax; k >= 0; k--){
    if((1 << k) <= depth[a] - depth[b]){
      a = parent[k][a];
    }
  }

  if(a == b) return a;

  // 공통 조상 찾기
  for(int k = kMax; k >= 0; k--){
    if(parent[k][a] != 0 && parent[k][a] != parent[k][b]){
      a = parent[k][a];
      b = parent[k][b];
    }
  }

  return parent[0][a];
}
