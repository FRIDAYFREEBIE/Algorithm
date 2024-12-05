#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> visit, answer;

void BFS(int node);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  graph.resize(n + 1);
  answer.resize(n + 1);
  visit.resize(n + 1);

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
  }

  for(int i = 1; i <= n; i++){
    fill(visit.begin(), visit.end(), false);
    BFS(i);
  }

  int maxValue = 0;
  for(int i = 1; i <= n; i++) maxValue = max(maxValue, answer[i]);

  for(int i = 1; i <= n; i++){
    if(maxValue == answer[i]) cout << i << " ";
  }

  cout << "\n";

  return 0;
}

void BFS(int node){
  queue<int> q;
  q.push(node);
  visit[node] = true;

  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int i : graph[current]){
      if(visit[i]) continue;

      visit[i] = true;
      answer[i]++; 
      q.push(i);
    }
  }
}