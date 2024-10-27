#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string str;
  cin >> str;

  set<string> strSet;
  for(int i = 0; i < str.length(); i++){
    string temp = "";
    for(int j = i; j < str.length(); j++){
      temp += str[j];
      strSet.insert(temp);
    }
  }

  cout << strSet.size() << "\n";

  return 0;
}