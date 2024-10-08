#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  char arr[50][50];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  int maxCandy = 0;

  for (int i = 0; i < n; i++) {
    int count = 1;
    for (int j = 1; j < n; j++) {
      if (arr[i][j] == arr[i][j - 1]) {
        count++;
      } else {
        maxCandy = max(maxCandy, count);
        count = 1;
      }
    }
    maxCandy = max(maxCandy, count);
  }

  for (int j = 0; j < n; j++) {
    int count = 1;
    for (int i = 1; i < n; i++) {
      if (arr[i][j] == arr[i - 1][j]) {
        count++;
      } else {
        maxCandy = max(maxCandy, count);
        count = 1;
      }
    }
    maxCandy = max(maxCandy, count);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j + 1 < n) {
        swap(arr[i][j], arr[i][j + 1]);

        int count = 1;
        for (int k = 1; k < n; k++) {
          if (arr[i][k] == arr[i][k - 1]) {
            count++;
          } else {
            maxCandy = max(maxCandy, count);
            count = 1;
          }
        }
        maxCandy = max(maxCandy, count);

        for (int k = 0; k < n; k++) {
          count = 1;
          for (int l = 1; l < n; l++) {
            if (arr[l][k] == arr[l - 1][k]) {
              count++;
            } else {
              maxCandy = max(maxCandy, count);
              count = 1;
            }
          }
          maxCandy = max(maxCandy, count);
        }

        swap(arr[i][j], arr[i][j + 1]);
      }

      if (i + 1 < n) {
        swap(arr[i][j], arr[i + 1][j]);

        for (int k = 0; k < n; k++) {
          int count = 1;
          for (int l = 1; l < n; l++) {
            if (arr[k][l] == arr[k][l - 1]) {
              count++;
            } else {
              maxCandy = max(maxCandy, count);
              count = 1;
            }
          }
          maxCandy = max(maxCandy, count);
        }

        for (int k = 0; k < n; k++) {
          int count = 1;
          for (int l = 1; l < n; l++) {
            if (arr[l][k] == arr[l - 1][k]) {
              count++;
            } else {
              maxCandy = max(maxCandy, count);
              count = 1;
            }
          }
          maxCandy = max(maxCandy, count);
        }

        swap(arr[i][j], arr[i + 1][j]);
      }
    }
  }

  cout << maxCandy << "\n";

  return 0;
}
