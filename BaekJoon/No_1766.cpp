#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> indegree, ans;
priority_queue<int, vector<int>, greater<int>> q;

// 문제를 위상정렬 하되 쉬운 문제부터 풀기(우선순위 큐)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  v.resize(n + 1);
  indegree.resize(n + 1);

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    v[a].push_back(b);
    indegree[b]++;
  }

  // 위상정렬
  for(int i = 1; i <= n; i++){if(indegree[i] == 0) q.push(i);}

  while(!q.empty()){
    int current = q.top();
    q.pop();

    for(auto next : v[current]){
      indegree[next]--;
      if(indegree[next] == 0) q.push(next);
    }

    ans.push_back(current);
  }

  for(auto n : ans) cout << n << " ";
  cout << "\n";

  return 0;
}