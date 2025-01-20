#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, arr[1001];
vector<pair<int, int>> v;

bool cmp(pair<int, int> & a, pair<int, int> & b)
{
  if (a.second == b.second) return a.first > b.first;
  else return a.second > b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++){
    int d, w;
    cin >> d >> w;

    v.push_back({d, w});
  }

  sort(v.begin(), v.end(), cmp);

  for(int i = 0; i < n; i++){
    for(int j = v[i].first; j > 0; j--){
      if(arr[j] == 0){
        arr[j] = v[i].second;
        break;
      }
    }
  }

  int result = 0;
  for(int i = 1; i <= 1000; i++) result += arr[i];

  cout << result << "\n";

  return 0;
}