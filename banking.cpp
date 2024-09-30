#include <iomanip>
#include <iostream>

using namespace std;

void printSpace(int amount) {
  while (amount > 0) {
    cout << " ";

    amount -= 1;
  }
}

void printTab(int amount) {
  while (amount > 0) {
    printSpace(4);

    amount -= 1;
  }
}

void getValues(double &balance, double &interestPercent, int &initialYear,
               int &finalYear) {
  printTab(3);

  cout << "Input balance: ";
  cin >> balance;

  printTab(3);

  cout << "Input Interest: ";
  cin >> interestPercent;

  printTab(3);

  cout << "Enter Initial year: ";
  cin >> initialYear;

  printTab(3);

  cout << "Enter Final Year: ";
  cin >> finalYear;
}

string formatStringNumWithCommas(const string &numStr) {
  int n = numStr.find('.');

  // If n == npos, this means that there's no decimal in numStr.
  string wholeNumber = (n == string::npos) ? numStr : numStr.substr(0, n);
  string decimalNumber = (n == string::npos) ? "" : numStr.substr(n);

  for (int i = wholeNumber.length() - 3; i > 0; i -= 3) {
    wholeNumber.insert(i, ",");
  }

  return wholeNumber + decimalNumber;
}

string formatNumToString(double num, int decimalLimit = -1) {
  if (decimalLimit >= 0) {
    stringstream ss;

    ss << fixed << setprecision(decimalLimit) << num;

    return ss.str();
  }

  return to_string(num);
}

int main() {
  double originalBalance, interestPercent;
  int initialYear, finalYear;

  cout << endl;

  getValues(originalBalance, interestPercent, initialYear, finalYear);

  cout << endl;

  cout << " Year";

  printTab(4);

  cout << "Interest";

  printTab(4);
  printSpace(3);

  cout << " Balance";

  cout << endl << endl;

  double prevYearBalance = originalBalance;

  for (int accumulatorYear = initialYear; accumulatorYear <= finalYear;
       ++accumulatorYear) {
    double interest =
        prevYearBalance -
        (prevYearBalance - prevYearBalance * (interestPercent / 100));
    double balance = (prevYearBalance + interest);

    cout << accumulatorYear;

    printTab(4);

    if (accumulatorYear == initialYear) {
      cout << "P ";
    } else {
      printSpace(2);
    }

    cout << formatStringNumWithCommas(formatNumToString(interest, 2));

    printTab(4);

    if (accumulatorYear == initialYear) {
      cout << "P ";
    } else {
      printSpace(2);
    }

    cout << formatStringNumWithCommas(formatNumToString(balance, 2));

    prevYearBalance = balance;

    cout << endl;
  }

  cout << endl;

  return 0;
}
