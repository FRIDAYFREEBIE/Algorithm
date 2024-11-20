#include <iostream>

using namespace std;

string str;
int q, sum[27][2000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> str >> q;
  sum[str[0]-  'a'][0] = 1;

  for(int i = 1; i < str.size(); i++){
    for(int j = 0; j < 27; j++) sum[j][i] = sum[j][i - 1];

    sum[str[i] - 'a'][i]++;
  }

  for(int i = 0; i < q; i++){
    char ch;
    int l, r;
    cin >> ch >> l >> r;

    int temp = ch - 'a';

    if(l == 0) cout << sum[temp][r] << "\n";
    else cout << sum[temp][r] - sum[temp][l - 1] << "\n";
  }

  return 0;
}