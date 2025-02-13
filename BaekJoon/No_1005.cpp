#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while(t--){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(n + 1); // 건물
    vector<int> cost(n + 1); // 건물 비용
    vector<int> indegree(n + 1); // 노드 차수

    for(int i = 1; i <= n; i++) cin >> cost[i];

    for(int i = 0; i < k; i++){
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      indegree[b]++;
    }

    // 위상 정렬
    queue<int> q;
    vector<int> dp(n + 1, 0); // dp

    for(int i = 1; i <= n; i++){
      if(indegree[i] == 0){
        q.push(i);
        dp[i] = cost[i];
      }
    }


    while(!q.empty()){
      int current = q.front();
      q.pop();

      //cout << current << " " << dp[current] << "\n";

      // 현재 노드에 연결되어있는 노드 방문
      for(auto node : v[current]){
        indegree[node]--;
        dp[node] = max(dp[node], dp[current] + cost[node]);
        if(indegree[node] == 0) q.push(node);
      }
    }

    
    int w;
    cin >> w;
    
    cout << dp[w] << "\n";
  }

  return 0;
}