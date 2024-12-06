#include <iostream>
#include <vector>

using namespace std;

void DFS(int node);

vector<vector<int>> graph;
vector<int> check;
vector<bool> visit;
bool isVaild;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;  

  for(int i = 0; i < n; i++){
    int v, e;
    cin >> v >> e;

    graph.resize(v + 1);
    visit.resize(v + 1);
    check.resize(v + 1);
    isVaild = true;

    for(int j = 0; j < e; j++){
      int a, b;
      cin >> a >> b;

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    for(int j = 1; j <= v; j++){
      if(isVaild) DFS(j);
      else break;
    }

    if(isVaild) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    for(int j = 0; j <= v; j++){
      graph[j].clear();
      visit[j] = false;
      check[j] = 0;
    }
  }

  return 0;
}

void DFS(int node){
  visit[node] = true;

  for(int i : graph[node]){
    if(!visit[i]){
      check[i] = (check[node] + 1) % 2;
      DFS(i);
    }
    else if(check[node] == check[i]) isVaild = false;
  }
}