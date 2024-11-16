#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> lectures(n);
  for(int i = 0; i < n; ++i)
    cin >> lectures[i].first >> lectures[i].second;

  sort(lectures.begin(), lectures.end());

  priority_queue<int, vector<int>, greater<int>> pq;

  for(const auto& lecture : lectures){
    int start = lecture.first;
    int end = lecture.second;

    if(!pq.empty() && pq.top() <= start) pq.pop();
    
    pq.push(end);
  }

  cout << pq.size() << "\n";

  return 0;
}
