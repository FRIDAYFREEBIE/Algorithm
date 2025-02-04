#include <iostream>

using namespace std;

int arr[100000];

void swap(int a, int b){
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  cin >> n;

  arr[1]=1;
  for(int i = 2; i <= n;i++){
    arr[i] = i;
        
    swap(i-1, i);

    for(int j = i - 1; j > 1; j /= 2){
      swap(j, j / 2);
    }
   }


  for(int i=1;i<=n;i++){
    cout<< arr[i]<<" ";
  }

  return 0;
}