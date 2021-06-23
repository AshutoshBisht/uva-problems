#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;
#define DEBUG

#define ignore_lines(n)                                                        \
  for (int i = 0; i < n; ++i)                                                  \
  cin.ignore(numeric_limits<streamsize>::max(), '\n')

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
  int t;
  cin >> t;
  ignore_lines(1);

  while (t--) {
    ignore_lines(1);
    string index;

    getline(cin, index);
    stringstream ss(index);
    vector<int> idx;
    while (1) {
      int temp;
      ss >> temp;
      if (ss.fail())
        break;
      idx.push_back(temp);
    }

    vector<string> values(idx.size());
    for (int i = 0; i < idx.size(); i++) {
      cin >> values[i];
    }
    ignore_lines(1);

    for (int i = 1; i <= idx.size(); i++) {
      for (int j = 0; j < idx.size(); j++) {
        if (i == idx[j])
          cout << values[j] << "\n";
      }
    }
    if (t)
      cout << "\n";
  }
/* #################### CODE END ################### */
#ifdef DEBUG
  cin.rdbuf(bkp_in);
  cout.rdbuf(bkp_out);
#endif
}