#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int calculate(queue<pair<int, int>> q, int documentOrder);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int documentsNumber, documentOrder;
    cin >> documentsNumber >> documentOrder;

    queue<pair<int, int>> orderQueue;

    for (int j = 0; j < documentsNumber; j++) {
      int importance;
      cin >> importance;

      orderQueue.push({importance, j}); // (중요도, 위치)
    }

    int result = calculate(orderQueue, documentOrder);
    cout << result << "\n";
  }

  return 0;
}

int calculate(queue<pair<int, int>> q, int documentOrder) {
  int printOrder = 0;

  priority_queue<int> importanceQueue;
  queue<pair<int, int>> tempQueue = q;

  while (!tempQueue.empty()) {
    importanceQueue.push(tempQueue.front().first);
    tempQueue.pop();
  }

  while (!q.empty()) {
    int importance = q.front().first;
    int index = q.front().second;

    if (importance == importanceQueue.top()) {
      printOrder++;
      q.pop();
      importanceQueue.pop();

      if (index == documentOrder) {
        return printOrder;
      }
    }
    else {
      q.push(q.front());
      q.pop();
    }
  }

  return -1;  // (논리적으로 여기에 도달하지 않음)
}
