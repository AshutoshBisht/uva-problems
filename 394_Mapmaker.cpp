#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define DEBUG

struct ndarr {
  string name;
  int size;
  int base;
  int d;
  vector<int> l, u, c;
  ndarr() {}
  ndarr(string name, int size, int base, int d) {
    this->name = name;
    this->size = size;
    this->base = base;
    this->d = d;
    l = vector<int>(d);
    u = vector<int>(d);
    c = vector<int>(d + 1);
  }
};

int calcAddr(ndarr &arr, vector<int> &idx) {
  int addr = arr.c[0];
  for (int i = 1; i <= arr.d; ++i) {
    addr += arr.c[i] * idx[i - 1];
  }
  return addr;
}

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
  int n, r;
  cin >> n >> r;

  vector<ndarr> vec(n);
  for (int i = 0; i < n; i++) {
    string name;
    int base, size, d;
    cin >> name >> base >> size >> d;
    vec[i] = ndarr(name, base, size, d);

    vector<int> &c = vec[i].c;
    vector<int> &l = vec[i].l;
    vector<int> &u = vec[i].u;

    for (int j = 0; j < d; j++) {
      cin >> l[j] >> u[j];
    }

    c[d] = size;
    for (int j = d - 1; j > 0; --j) {
      c[j] = c[j + 1] * (u[j] - l[j] + 1);
    }
    c[0] = base;
    for (int j = 1; j <= d; ++j) {
      c[0] -= c[j] * l[j - 1];
    }
  }

  /*Processing*/
  while (r--) {
    string name;
    cin >> name;
    for (int i = 0; i < n; ++i) {
      if (name == vec[i].name) {
        vector<int> idx(vec[i].d);
        for (int j = 0; j < idx.size(); ++j) {
          cin >> idx[j];
        }

        int addr = calcAddr(vec[i], idx);
        cout << name << "[";
        for (int k = 0; k < idx.size(); k++) {
          cout << idx[k];
          if (k < idx.size() - 1)
            cout << ", ";
        }
        cout << "] = " << addr << "\n";
      }
    }
  }
/* #################### CODE END ################### */
#ifdef DEBUG
  cin.rdbuf(bkp_in);
  cout.rdbuf(bkp_out);
#endif
}