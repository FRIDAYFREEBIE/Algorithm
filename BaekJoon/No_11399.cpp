 #include <iostream>
 #include <vector>
 #include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> timeVector(n);
  for(int i = 0; i < n; i++){
    cin >> timeVector[i];
  }

  sort(timeVector.begin(), timeVector.end());

  int time = 0, result = 0;
  for(int i = 0; i < n; i++){
    result += time + timeVector[i];
    time += timeVector[i];
  }

  cout << result << "\n";

  return 0;
}