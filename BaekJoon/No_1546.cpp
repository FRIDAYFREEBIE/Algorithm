#include <iostream>
#include <string>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  double score[1000], correctionScore[1000], max = 0;
  
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> score[i];

    if(score[i] > max)
      max = score[i];
  }

  double avg = 0.0, sum = 0.0;;

  for(int i = 0; i < n; i++){
    correctionScore[i] = score[i] / max * 100;

    sum += correctionScore[i];
  }

  avg = sum / n;

  cout << avg << "\n";

  return 0;
}
