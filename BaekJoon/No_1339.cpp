#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    string str;
    cin >> str;

    int pow = 1;
    for(int j = str.size() - 1; j >= 0; j--){
      arr[str[j] - 'A'] += pow;
      pow *= 10;
    }
  }

  sort(arr, arr + 26, greater<>());

  int temp = 9;
  int result = 0;
  for(int i = 0; i < 26; i++){
    if(arr[i] == 0) break;

    result += arr[i] * temp;
    temp--;
  }

  cout << result << "\n";

  return 0;
}