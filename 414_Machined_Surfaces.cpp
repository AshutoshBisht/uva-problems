#include <bits/stdc++.h>
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
    if (n == 0)
      break;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int maxcount = 0;
    vector<int> vect(n);
    for (int i = 0; i < n; i++) {
      int count = 0;
      string temp;
      getline(cin, temp);
      for (int j = 0; j < 25; j++) {
        count += temp[j] == 'X';
      }
      vect[i] = count;
      maxcount = max(maxcount, count);
    }

    int spaces = 0;
    for (int i = 0; i < n; i++) {
      spaces += (maxcount - vect[i]);
    }

    cout << spaces << "\n";
  }
  /* #################### CODE END ################### */
#ifdef DEBUG
  cin.rdbuf(bkp_in);
  cout.rdbuf(bkp_out);
#endif
}