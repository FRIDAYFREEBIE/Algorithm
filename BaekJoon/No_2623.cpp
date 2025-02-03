#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> indegree, ans;
queue<int> q;

// 위상 정렬 문제
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  v.resize(n + 1);
  indegree.resize(n + 1);

  for(int i = 0; i < m; i++){
    int temp;
    cin >> temp;
    
    int prev;
    cin >> prev;
    for(int j = 0; j < temp - 1; j++){
      int temp;
      cin >> temp;

      v[prev].push_back(temp);
      indegree[temp]++;
      prev = temp;
    }
  }

  // 위상정렬
  for(int i = 1; i <= n; i++){if(indegree[i] == 0) q.push(i);}

  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int next : v[current]){
      indegree[next]--;
      if(indegree[next] == 0) q.push(next);
    }

    ans.push_back(current);
  }

  if(ans.size() != n) cout << 0 << "\n";
  else for(auto n : ans) cout << n << "\n";

  // indegree 출력
  //for(int i = 1; i <= n; i++) cout << i << " " << indegree[i] << "\n";

  // 그래프 순회 출력
  // for(int i = 1; i <= n; i++){
  //   cout << i << " ";
  //   for(auto n : v[i]) cout << n << " ";
  //   cout << "\n";
  // }

  return 0;
}