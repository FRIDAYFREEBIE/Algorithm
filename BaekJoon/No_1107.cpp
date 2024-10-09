#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool isInclude(vector<int>& v, int n) {
  for (auto& a : v) {
    if (a == n) return true;
  }

  return false;
}

bool canPress(int channel, vector<int>& wrongButtons) {
  string s = to_string(channel);
  for (char c : s) {
    if (isInclude(wrongButtons, c - '0')) return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int m;
  cin >> m;

  vector<int> wrongButtons;
  for (int i = 0; i < m; i++) {
  int temp;
    cin >> temp;
    wrongButtons.push_back(temp);
  }

  int minButtonPress = abs(n - 100);

  for (int i = 0; i <= 1000000; i++) {
    if (canPress(i, wrongButtons)) {
      int buttonPress = to_string(i).length() + abs(i - n);
      minButtonPress = min(minButtonPress, buttonPress);
    }
  }

  cout << minButtonPress << "\n";

  return 0;
}