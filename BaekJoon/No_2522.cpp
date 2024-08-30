#include <iostream>

using namespace std;

void Star(int star);
void Space(int space);

int main()
{
  ios :: sync_with_stdio(false);

  int n;

  cin >> n;

  // 별과 공백 개수 연산 n번 반복
  for(int i = 0; i < n; i++)
  {
    int star, space;

    star = i + 1;
    space = n - star;

    Space(space);
    Star(star);

    cout << "\n";
  }

  // 별과 공백 개수 연산 n번 반복
  for(int i = n; i > 0; i--)
  {
    int star, space;

    star = i - 1;
    space = n - star;

    Space(space);
    Star(star);

    cout << "\n";
  }
}

// 별 출력 매서드
void Star(int star)
{
  for(int i = 0; i < star; i++)
  {
    cout << "*";
  }
}

// 공백 출력 매서드
void Space(int space)
{
  for(int i = 0; i < space; i++)
  {
    cout << " ";
  }
}