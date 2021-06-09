#include <bits/stdc++.h>
using namespace std;
#define DEBUG

int main()
{
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
    while (t--)
    {
        long int a, b;
        cin >> a >> b;
        if (a > b)
        {
            cout << ">"
                 << "\n";
        }
        else if (a < b)
        {
            cout << "<"
                 << "\n";
        }
        else
        {
            cout << "="
                 << "\n";
        }
    }

    /* #################### CODE END ################### */
#ifdef DEBUG
    cin.rdbuf(bkp_in);
    cout.rdbuf(bkp_out);
#endif
}