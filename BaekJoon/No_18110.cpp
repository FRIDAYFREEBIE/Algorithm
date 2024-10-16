#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v;

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;

    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  double cutAverage = round(n * 0.15), sum = 0;

  for (int i = cutAverage; i < n - cutAverage; i++) {
    sum += v[i];
  }

  double average = round(sum / (n - (cutAverage * 2)));

  if(n != 0){
    cout << average << "\n";
  }
  else{
    cout << 0 << "\n";
  }

  return 0;
}
