#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> lecture;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  lecture.resize(n);

  for(int i = 0; i < n; i++){
    int num, start, end;
    cin >> num >> start >> end;

    lecture[i] = {start, end};
  }

  sort(lecture.begin(), lecture.end());

  priority_queue<int, vector<int>, greater<int>> pq;

  for(auto a : lecture){
    int start = a.first;
    int end = a.second;

    if(!pq.empty() && pq.top() <= start) pq.pop();

    pq.push(end);
  }

  cout << pq.size() << "\n";

  return 0;
}