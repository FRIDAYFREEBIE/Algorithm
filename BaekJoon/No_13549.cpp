#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
bool visit[100001];

void BFS();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  BFS();

  return 0;
}

void BFS(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <시간, 위치>
  pq.push({0, n});

  while(!pq.empty()){
    pair<int, int> current = pq.top();
    pq.pop();

    // 방문
    if(visit[current.second]) continue;

    visit[current.second] = true;

    if(current.second == k){
      cout << current.first << "\n";
      return;
    }

    // 걷기 + 1
    if(current.second - 1 >= 0 && !visit[current.second - 1]) pq.push({current.first + 1, current.second - 1});
    // 걷기 - 1
    if(current.second + 1 <= 100000 && !visit[current.second + 1]) pq.push({current.first + 1, current.second + 1});
    // 순간이동 * 2
    if(current.second * 2 <= 100000 && !visit[current.second * 2]) pq.push({current.first, current.second * 2});
  }
}
