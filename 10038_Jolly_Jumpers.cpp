#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define DEBUG

int main() {
#ifdef DEBUG
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  ifstream in("input.txt");
  ofstream out("output.txt");
  auto bkp_in = cin.rdbuf();
  auto bkp_out = cout.rdbuf();
  cin.rdbuf(in.rdbuf());
  cout.rdbuf(out.rdbuf());
#endif
  /* #################### CODE START ################## */
  while (1) {
    int n;
    cin >> n;
    if (cin.fail())
      break;

    vector<int> vect(n);
    for (int i = 0; i < n; i++) {
      cin >> vect[i];
    }

    vector<bool> present(n);
    for (int i = 0; i < n - 1; ++i) {
      int diff = abs(vect[i] - vect[i + 1]);
      if (diff < n)
        present[diff] = true;
    }

    bool isJolly = true;
    for (int i = 1; i < n; ++i) {
      if (!present[i]) {
        isJolly = false;
        break;
      }
    }

    if (isJolly) {
      cout << "Jolly"
           << "\n";
    } else {
      cout << "Not jolly"
           << "\n";
    }
  }
  /* #################### CODE END ################### */
#ifdef DEBUG
  cin.rdbuf(bkp_in);
  cout.rdbuf(bkp_out);
#endif
}