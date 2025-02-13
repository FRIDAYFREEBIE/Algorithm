#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<vector<int>> tree; // 트리
vector<int> subTreeSize; // 서브 트리 크기
vector<bool> visited; // 방문

int childCnt(int root); // 자식 노드의 갯수

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> r >> q;
  tree.resize(n + 1);
  subTreeSize.resize(n + 1);
  visited.resize(n + 1);

  for(int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  childCnt(r);

  for(int i = 0; i < q; i++){
    int temp;
    cin >> temp;
    cout << subTreeSize[temp] << "\n";
  }

  return 0;
}

int childCnt(int root){
  visited[root] = true;
  subTreeSize[root] = 1; // 자신 포함

  // 자식 노드 순회
  for(int node : tree[root]){
    if(!visited[node]) subTreeSize[root] += childCnt(node);
  }

  return subTreeSize[root];
}