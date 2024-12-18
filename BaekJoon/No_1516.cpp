#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> graph(n + 1);
  vector<int> indegree(n + 1);
  vector<int> selfBuild(n + 1);

  for(int i = 1; i <= n; i++){
    cin >> selfBuild[i];

    while(true){
      int temp;
      cin >> temp;

      if(temp == -1) break;

      graph[temp].push_back(i);
      indegree[i]++;
    }
  }

  queue<int> queue;

  for(int i = 1; i <= n; i++){
    if(indegree[i] == 0) queue.push(i);
  }

  vector<int> result(n + 1);

  while(!queue.empty()){
    int current = queue.front();
    queue.pop();

    for(int next : graph[current]){
      indegree[next]--;
      result[next] = max(result[next], result[current] + selfBuild[current]);

      if(indegree[next] == 0) queue.push(next);
    }
  }

  for(int i = 1; i <= n; i++) cout << result[i] + selfBuild[i] << "\n";

  return 0;
}