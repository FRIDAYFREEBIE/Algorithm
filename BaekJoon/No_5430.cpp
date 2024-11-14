#include <iostream>
#include <deque>
#include <cctype>
#include <string>

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;

  while (t--) {
    string str, numStr;
    int n;
    cin >> str >> n >> numStr;

    deque<int> d;
    string temp = "";

    for (int i = 0; i < numStr.size(); i++) {
      if (isdigit(numStr[i])) {
        temp += numStr[i];
      } else if (numStr[i] == ',' || numStr[i] == ']') {
        if (!temp.empty()) {
          d.push_back(stoi(temp));
          temp = "";
        }
      }
    }

    bool isReverse = false;
    bool isError = false;

    for (char c : str) {
      if (c == 'D') {
        if (d.empty()) {
          isError = true;
          break;
        }
        if (isReverse) {
          d.pop_back();
        } else {
          d.pop_front();
        }
      } else if (c == 'R') {
        isReverse = !isReverse;
      }
    }

    if (isError) {
      cout << "error\n";
    } else {
      cout << "[";
      if (!isReverse) {
        for (int i = 0; i < d.size(); i++) {
          cout << d[i];
          if (i < d.size() - 1) cout << ",";
        }
      } else {
        for (int i = d.size() - 1; i >= 0; i--) {
          cout << d[i];
          if (i > 0) cout << ",";
        }
      }
      cout << "]\n";
    }
  }

  return 0;
}
