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

    while (1)
    {
        int n, budget, nh, nw;
        cin >> n >> budget >> nh >> nw;
        if (cin.fail())
            break;
        int price[nh];
        int beds[nh][nw];
        for (int i = 0; i < nh; i++)
        {
            cin >> price[i];
            for (int j = 0; j < nw; j++)
            {
                cin >> beds[i][j];
            }
        }
        // for (int i = 0; i < nh; i++)
        // {
        //     cout << price[i] << "\n";
        //     for (int j = 0; j < nw; j++)
        //     {
        //         cout << beds[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        int cost = INT_MAX;
        int h_price = 0;
        for (int i = 0; i < nh; i++)
        {
            for (int j = 0; j < nw; j++)
            {

                if (beds[i][j] >= n)
                {
                    h_price = n * price[i];
                    if (h_price <= budget)
                    {
                        if (h_price < cost)
                        {
                            cost = h_price;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }
        }

        if (cost == INT_MAX)
        {
            cout << "stay home"
                 << "\n";
        }
        else
        {
            cout << cost << "\n";
        }
    }

    /* #################### CODE END ################### */
#ifdef DEBUG
    cin.rdbuf(bkp_in);
    cout.rdbuf(bkp_out);
#endif
}