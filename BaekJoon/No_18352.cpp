#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> visit, answer;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long n, m, k, x;
  cin >> n >> m >> k >> x;
  graph.resize(n + 1);

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
  }

  visit.resize(n + 1, -1);

  queue<int> q;
  q.push(x);
  visit[x] = 0;

  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int i : graph[current]){
      if(visit[i] != -1) continue;

      visit[i] = visit[current] + 1;
      q.push(i);
    }
  }

  for(int i = 0; i <= n; i++){
    if(visit[i] == k) answer.push_back(i);
  }

  if(answer.empty()) cout << -1 << "\n";
  else{
    sort(answer.begin(), answer.end());

    for(int a : answer) cout << a << "\n";
  }

  return 0;
}