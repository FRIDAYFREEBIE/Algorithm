#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n + 1);
  vector<int> indegree(n + 1);

  for(int i = 0; i < m; i++){
    int s, e;
    cin >> s >> e;

    graph[s].push_back(e);
    indegree[e]++;
  }

  queue<int> queue;

  for(int i = 1; i <= n; i++){
    if(indegree[i] ==  0) queue.push(i);
  }

  while(!queue.empty()){
    int current = queue.front();
    queue.pop();

    cout << current << " ";

    for(int i : graph[current]){
      indegree[i]--;

      if(indegree[i] == 0) queue.push(i);
    }
  }

  cout << "\n";

  return 0;
}