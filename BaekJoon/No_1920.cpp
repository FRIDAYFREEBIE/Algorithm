#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;


  set<int> s;

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;

    s.insert(temp);
  }

  int m;
  cin >> m;

  vector<int> v;

  for(int i = 0; i < m; i++){
    int temp;
    cin >> temp;

    v.push_back(temp);
  }

  for(auto & a : v){
    cout << s.count(a) << "\n";
  }
  
  return 0;
}
