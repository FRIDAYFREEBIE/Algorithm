#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ans;
vector<bool> visited;
vector<vector<int>> tree;

void DFS(int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  ans.resize(n + 1);
  visited.resize(n + 1);
  tree.resize(n + 1);

  for(int i = 1; i <= n; i++){
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  DFS(1); // 루트 노드에서 DFS 실행

  for(int i = 2; i <= n; i++)
    cout << ans[i] << "\n";

  return 0;
}

void DFS(int n){
  visited[n] = true;

  for(int i : tree[n]){
    if(!visited[i]){
      // 정답 벡터에 저장
      ans[i] = n;
      DFS(i);
    }
  }
}