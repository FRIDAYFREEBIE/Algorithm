#include <iostream>
#include<string>

using namespace std;

bool arr[10005];

void func(int n){
  int temp = n;

  while(n > 0){
    temp += n % 10;
    n /= 10;
  }

  if(temp <= 10000) arr[temp] = true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 1;  i <= 10000; i++) func(i);

  for(int i = 1; i <= 10000; i++){
    if(!arr[i]) cout << i << "\n";
  }

  return 0;
}