#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  map<string, bool> stringMap;
  int result = 0;

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    string temp;
    cin >> temp;

    stringMap[temp] = true;
  }

  for(int i = 0; i < m; i++){
    string temp;
    cin >> temp;

    if(stringMap[temp]){
      result++;
    }
  }

  cout << result << "\n";

  return 0;
}
