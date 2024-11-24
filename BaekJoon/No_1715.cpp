#include <iostream>
#include <queue>

using namespace std;

// 10 20 40
// 1. 10 + 20 + 30 + 40 = 100
// 2. 40 + 20 + 60 + 10 = 130
// 가장 먼저 더해지는 수가 작아야 함

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 우선순위 큐

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;

    pq.push(temp);
  }

  int sum = 0, a = 0, b = 0;
  while(pq.size() != 1){
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();

    sum += a + b;
    pq.push(a + b);
  }

  cout << sum << "\n";

  return 0;
}