#include <iostream>
#include <vector>

using namespace std;

long GCD(long long a, long long b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  for(int i = 0; i < t; i++){
    int n;
    cin >> n;

    vector<long long> numVector(n);
    for(int j = 0; j < n; j++){
      cin >> numVector[j];
    }

    long long sum = 0;
    for(int k = 0; k < n; k++){
      for(int l = k + 1; l < n; l++){
        sum += GCD(numVector[k], numVector[l]);
      }
    }

    cout << sum << "\n";
  }

  return 0;
}

long GCD(long long a, long long b){
  if(b == 0){
    return a;
  }
  else{
    return GCD(b, a % b);
  }
}