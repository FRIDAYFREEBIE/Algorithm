#include <iostream>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

	int num;

	cin >> num;

	for (int i = 1; i < num; i++) {
		int temp = i;
		int sum = i;

		while (temp != 0) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == num) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << 0 << '\n';

  return 0;
}