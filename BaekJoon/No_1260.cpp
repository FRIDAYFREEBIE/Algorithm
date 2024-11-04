#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

void DFS(int current);
void BFS(int start);

vector<int> adj[1001];
bool visitDFS[1001];
bool visitBFS[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m, v;
  cin >> n >> m >> v;

  while(m--){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++){
    sort(adj[i].begin(), adj[i].end());
  }

  DFS(v);
  cout << "\n";

  BFS(v);

  return 0;
}

void DFS(int current){
  visitDFS[current] = true;

  cout << current << " ";

  for(auto next : adj[current]){
    if(visitDFS[next]){
      continue;
    }

    DFS(next);
  }
}

void BFS(int start){
  queue<int> q;
  q.push(start);
  visitBFS[start] = true;

  while(!q.empty()){
    int current = q.front();
    q.pop();

    cout << current << " ";

    for(auto next : adj[current]){
      if(visitBFS[next]){
        continue;
      }

      visitBFS[next] = true;
      q.push(next);
    }
  }
}