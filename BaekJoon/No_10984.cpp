#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int t;

  cin >> t;

  cout << fixed;
  cout.precision(1);
  
  for(int i = 0; i < t; i++)
  {
    int n;

    cin >> n;
    
    int score = 0;
    double grade = 0.0;

    for(int j = 0; j < n; j++)
    {
      int tempScore;
      double tempGrade;

      cin >> tempScore >> tempGrade;

      score += tempScore;
      grade += tempGrade * tempScore;
    }

    cout << score << " " << grade / score << "\n";
  }
}