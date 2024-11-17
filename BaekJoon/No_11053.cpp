#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;
vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;

  v.reserve(t);


  for(int i = 0; i < t; i++){
    int temp;
    cin >> temp;

    auto a = lower_bound(v.begin(), v.end(), temp);

    // 존재 안 함
    if(a == v.end()) v.push_back(temp);
    else *a = temp;
  }

  cout << v.size() << "\n";

  return 0;
}