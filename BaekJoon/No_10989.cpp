#include <iostream>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  int max = 0;
  int arr[10001] = {0};

  for(int i = 0; i < n; i++){
    int temp;

    cin >> temp;

    if(temp > max) max = temp;

    arr[temp - 1] ++;
  }

  for(int i = 0; i < max; i++){
    for(int j = 0; j < arr[i]; j++){
      cout << i + 1<< "\n";
    }
  }

  return 0;
}