#include <iostream>
#include <string>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  bool isPalindrome = true;

  while(true){
    cin >> s;

    if(s == "0") return 0;

    isPalindrome = true;

    for(int i = 0; i < s.length() / 2; i++){
      if(s[i] != s[s.length() - i - 1]){
        isPalindrome = false;
      }
    }

    if(isPalindrome) cout << "yes\n";
    else cout << "no\n";
  }

  return 0;
}
