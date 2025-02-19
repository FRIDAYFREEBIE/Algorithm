#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> tree; // 트리
vector<int> depth; // 노드의 깊이
vector<int> parent; // 부모
vector<bool> visited; // 방문

void BFS(int i);
int LCA(int a, int b); // 최소 공통 조상

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  tree.resize(n + 1);
  depth.resize(n + 1);
  parent.resize(n + 1);
  visited.resize(n + 1);

  for(int i = 0; i < n - 1; i++){
    int s, e;
    cin >> s >> e;
    tree[s].push_back(e);
    tree[e].push_back(s);
  }

  BFS(1); // 루트노드에서 탐색 시작

  cin >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    cout << LCA(a, b) << "\n";
  }

  return 0;
}

void BFS(int i){
  queue<int> q;
  q.push(i);
  visited[i] = true;

  int level = 1, size = 1, cnt = 0;
  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int next : tree[current]){
      if(!visited[next]){
        visited[next] = true;
        q.push(next);
        parent[next] = current; // 부모 노드
        depth[next] = level; // 깊이
      }
    }

    cnt++;

    if(cnt == size){
      cnt = 0;
      size = q.size();
      level++;
    }
  }
}

int LCA(int a, int b){
  // 더 깊이가 깊은 노드를 a에 놓는다다
  if(depth[a] < depth[b]){
    int temp = a;
    a = b;
    b = temp;
  }

  // a와 b의 깊이가 같아질 때 까지 a의 조상을 찾아 올라감
  while(depth[a] != depth[b])
    a = parent[a];

    // 깊이가 같을 때 최소 공통 조상 찾기기
  while(a != b){
    a = parent[a];
    b = parent[b];
  }

  return a;
}