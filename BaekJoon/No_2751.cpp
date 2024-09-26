#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  vector<int> v;

  for(int i = 0; i < n; i++){
    int temp;

    cin >> temp;

    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  for(int num : v){
    cout << num << "\n";
  }

  return 0;
}