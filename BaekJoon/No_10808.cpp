#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string str;
  cin >> str;

	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << count(str.begin(), str.end(), i) << ' ';
  }

  return 0;
}