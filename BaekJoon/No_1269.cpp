#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  set<int> numSet;

  int a, b;
  cin >> a >> b;

  for(int i = 0; i < a + b; i++){
    int temp;
    cin >> temp;

    auto result = numSet.insert(temp);
    if(!result.second){
      numSet.erase(temp);
    }
  }

  cout << numSet.size();

  return 0;
}
