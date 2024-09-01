#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  string s;
  int arr[26];

  // 배열 초기화
  for(int i = 0; i < 26; i++)
  {
    arr[i] = -1;
  }

  cin >> s;

  // 분류
  for(int i = 0; i < s.length(); i++)
  {
    if(arr[s[i] - 97] == -1)
      arr[s[i] - 97] = i;
  }

  // 배열 출력
  for(int i = 0; i < 26; i++)
  {
    cout << arr[i] << " ";
  }

  cout << "\n";

  return 0;
}