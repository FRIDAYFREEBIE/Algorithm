#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;

  int arr[128] = {0};
  for(char s : str) arr[s]++;

  string odd = "", even = "";
  for(char i = 'A'; i <= 'Z'; i++){
    if(arr[i] % 2) odd += i;

    even += string(arr[i] / 2, i);
  }

  if(odd.size() >  1) cout << "I'm Sorry Hansoo" << "\n";
  else{
    cout << even << odd;

    reverse(even.begin(), even.end());

    cout << even << "\n";
  }

  return 0;
}