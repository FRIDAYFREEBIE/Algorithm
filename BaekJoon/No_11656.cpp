#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;
  cin >> str;
  
  vector <string> strVector;
  for(int i = 0; i < str.length(); i++){
    string temp = "";
    for(int j = i; j < str.length(); j++){
      temp += str[j];
    }
    strVector.push_back(temp);
  }

  sort(strVector.begin(), strVector.end());

  for(string s : strVector){
    cout << s << "\n";
  }

  return 0;
}
