#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  for(int i = 0; i < t; i++){
    int n;
    cin >> n;

    map<string, int> clothMap; // <종류, 갯수>
    for(int j = 0; j < n; j++){
      string name, type;
      cin >> name >> type;

      clothMap[type]++;
    }

    int result = 1;
    for(auto &pair : clothMap){
      result *= pair.second + 1;
    }

    cout << result - 1 << "\n";
  }

  return 0;
}