#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr, int k);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  
  bubbleSort(arr, k);

  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

  cout << "\n";

  return 0;
}

void bubbleSort(vector<int> &arr, int k){ 
  int n = arr.size();
  for (int i = 0; i < k; i++){
    for (int j = 0; j < n - i - 1; j++){
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}
