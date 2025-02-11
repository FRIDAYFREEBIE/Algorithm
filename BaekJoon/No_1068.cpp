#include <iostream>
#include <vector>

using namespace std;

int n, root, ans, deleteNode;
vector<vector<int>> tree;
vector<bool> visited;

void DFS(int root);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  tree.resize(n);
  visited.resize(n);

  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    
    if(a != -1){
      tree[i].push_back(a);
      tree[a].push_back(i);
    }
    else root = i;
  }

  cin >> deleteNode;

  if(deleteNode == root) cout << 0 << "\n";
  else{
    DFS(root);
    cout << ans << "\n";
  }

  return 0;
}

void DFS(int root){
  visited[root] = true;

  int temp = 0;
  for(auto n : tree[root]){
    // 방문한 적 없고 삭제 노드가 아닐 때
    if(!visited[n] && n != deleteNode){
      temp++;
      DFS(n);
    }
  }

  // temp가 0이면 리프 노드
  if(temp == 0) ans++;
}
