#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int quarter = 0 , dime = 0, nickel = 0, penny = 0; // 25, 10, 5, 1

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    quarter = 0 , dime = 0, nickel = 0, penny = 0;
    
    int money;
    cin >> money;

    int sum = 0;
    while (true){
      if(money - sum >= 25){
        sum += 25;
        quarter++;
      }
      else if(money - sum >= 10){
        sum += 10;
        dime++;
      }
      else if(money - sum >= 5){
        sum += 5;
        nickel++;
      }
      else if(money - sum >= 1){
        sum += 1;
        penny++;
      }

      if(money == sum){
        break;
      }
    }

    cout << quarter << " " << dime << " " << nickel << " " << penny << "\n";
  }  

  return 0;
}