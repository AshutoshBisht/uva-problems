#include <iostream>
#include <cmath>
#include <fstream>
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
    while (1)
    {
        double h, u, d, f;
        cin >> h >> u >> d >> f;
        if (h == 0)
            break;

        //processing
        f /= 100;
        int day = 0;
        double c = 0;
        double redc = f * u;
        while (1)
        {
            c += u;
            if (c > h)
                break;

            c -= d;
            if (c < 0)
                break;

            u = max(0.0, u - redc);
            ++day;
        }

        //output
        if (c > h)
        {
            cout << "success on day " << day + 1 << "\n";
        }
        else
        {
            cout << "failure on day " << day + 1 << "\n";
        }
    }

    /*###### CODE END ################### */
#ifdef DEBUG
    cin.rdbuf(bkp_in);
    cout.rdbuf(bkp_out);
#endif
}