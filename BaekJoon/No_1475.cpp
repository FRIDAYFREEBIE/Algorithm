#include <iostream>
#include <vector>

using namespace std;

// 6 = 9 9 = 6
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string n;
  cin >> n;

  vector<int> count(10, 0);

  for(char c : n) {
    int num = c - '0';
    count[num]++;
  }

  int temp = (count[6] + count[9] + 1) / 2;
  count[6] = count[9] = temp;

  int setCnt = 0;
  for(int a : count){
    if(a > setCnt){
      setCnt = a;
    }
  }

  cout << setCnt << "\n";

  return 0;
}