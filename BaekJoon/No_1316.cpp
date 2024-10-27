#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isGroup(string word);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  int cnt = 0;
  for (int i = 0; i < n; ++i){
    string word;
    cin >> word;

    if (isGroup(word)) {
      cnt++;
    }
  }

  cout << cnt << "\n";

  return 0;
}

bool isGroup(string word){
  set<char> seen;
  char prev = ' ';

  for (char ch : word) {
    if (ch != prev) {
      if (seen.count(ch) > 0) {
        return false;
      }

      seen.insert(ch);
    }
    
    prev = ch;
  }
  return true;
}