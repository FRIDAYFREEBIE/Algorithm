#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  priority_queue<int> pq;
  for(int i = 0; i < n - 1; i++){
    int temp;
    cin >> temp;

    pq.push(temp);
  }

  int ans = 0;
  while(!pq.empty()){
    int current = pq.top();
    pq.pop();

    if(current < m) break;
    else{
      pq.push(current - 1);
      m++;
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}