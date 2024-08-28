#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n, lowYear = 1990, highYear = 2010, lowMonth = 1, highMonth = 12, lowDay = 1, highDay = 31;
  string lowName, highName;

  cin >> n;

  string tempName;
  int tempYear, tempMonth, tempDay;
  bool isUpdate = false;

  for(int i = 0; i < n; i++)
  {
    cin >> tempName >> tempDay >> tempMonth >> tempYear;
    
    // 어린 나이 갱신이 필요한지 검사
    if(tempYear > lowYear)
      isUpdate = true;
    else if(tempYear == lowYear)
    {
      if(tempMonth > lowMonth)
        isUpdate = true;
      else if(tempMonth == lowMonth)
      {
        if(tempDay > lowDay)
          isUpdate = true;
        else if(tempDay == lowDay)
          isUpdate = true;
      }
    }

  // 갱신
    if(isUpdate)
    {
      lowName = tempName;
      lowYear = tempYear;
      lowMonth = tempMonth;
      lowDay = tempDay;

      isUpdate = false;
    }

    // 많은 나이 갱신이 필요한지 검사
    if(tempYear < highYear)
      isUpdate = true;
    else if(tempYear == highYear)
    {
      if(tempMonth < highMonth)
        isUpdate = true;
      else if(tempMonth == highMonth)
      {
        if(tempDay < highDay)
          isUpdate = true;
        else if(tempDay == highDay)
          isUpdate = true;
      }
    }

    // 갱신
    if(isUpdate)
    {
      highName = tempName;
      highYear = tempYear;
      highMonth = tempMonth;
      highDay = tempDay;   

      isUpdate = false;
    }
  }

  cout << lowName << "\n" << highName << "\n";
}