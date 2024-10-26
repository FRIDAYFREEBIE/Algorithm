#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(true){
    int n;
    cin >> n;

    if(n == -1){
      break;
    }

    int sum = 0;
    vector<int> numVector;
    for(int i = 1; i <= n; i++){
      if(n % i == 0 && i != n){
        numVector.push_back(i);
        sum += i;
      }
    }

    if(sum == n){
      cout << n << " = ";
      for(int i = 0; i < numVector.size(); i++){
        cout << numVector[i] << " ";
        if(i != numVector.size() - 1){
          cout << "+ ";
        }
      }
    }
    else{
      cout << n << " is NOT perfect.";
    }
    
    cout << "\n";
  }

  return 0;
}