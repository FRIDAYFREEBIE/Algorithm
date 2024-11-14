#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> timeArray[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> timeArray[i].second >> timeArray[i].first;
  }

  sort(timeArray, timeArray + n);

  int current = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(current <= timeArray[i].second){
      cnt++;
      current = timeArray[i].first;
    }
  }

  cout << cnt << "\n";

  return 0;
}