#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  set<string> nameSet;
  for (int i = 0; i < n; i++){
    string name, work;
    cin >> name >> work;

    if (work == "enter"){
      nameSet.insert(name);
    }
    else{
      nameSet.erase(name);
    }
  }

  // reverse begin 역방향 시작
  // reverse end 역방향 끝
  for (auto i = nameSet.rbegin(); i != nameSet.rend(); ++i){
    cout << *i << "\n";
  }

  return 0;
}
