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
  int set = 1;
  while (1) {
    int n;
    cin >> n;
    if (n == 0)
      break;
    vector<int> h(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> h[i];
      sum = sum + h[i];
    }

    int bricks = 0;
    int height = sum / n;
    for (int i = 0; i < n; i++) {
      if (h[i] > height) {
        bricks = bricks + (h[i] - height);
      }
    }

    cout << "Set #" << set << "\n";
    cout << "The minimum number of moves is " << bricks << ".\n";
    cout << "\n";

    set++;
  }

  /* #################### CODE END ################### */
#ifdef DEBUG
  cin.rdbuf(bkp_in);
  cout.rdbuf(bkp_out);
#endif
}