#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> v;
vector<int> indegree, timeVector, dp;
queue<int> q;

// 동시작업 가능 위상정렬
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  v.resize(n + 1);
  indegree.resize(n + 1);
  timeVector.resize(n + 1);
  dp.resize(n + 1);

  for(int i = 1; i <= n; i++){
    int t, c;
    cin >> t >> c;

    timeVector[i] = t;

    if(c == 0){
      q.push(i);
      indegree[i] = 0;
      dp[i] = t;
    }

    for(int j = 0; j < c; j++){
      int temp;
      cin >> temp;

      v[temp].push_back(i);
      indegree[i]++;
    }
  }

  int ans = 0;
  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(auto next : v[current]){
      indegree[next]--;

      dp[next] = max(dp[next], dp[current] + timeVector[next]);

      if(indegree[next] == 0) q.push(next);
    }
  }

  for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);

  cout << ans << "\n";

  return 0;
}
