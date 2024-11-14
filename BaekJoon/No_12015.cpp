#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, cnt, previous;
vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  while(n--){
    int temp;
    cin >> temp;

    auto a = lower_bound(v.begin(), v.end(), temp);

    if(a == v.end()){
      v.push_back(temp);
    }
    else{
      *a = temp;
    }
  }

  cout << v.size() << "\n";

  return 0;
}