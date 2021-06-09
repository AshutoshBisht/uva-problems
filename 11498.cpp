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
    int k;
    do
    {

        cin >> k;
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x == N || y == M)
            {
                cout << "divisa"
                     << "\n";
            }
            else if (x < N && y > M)
            {
                cout << "NO"
                     << "\n";
            }
            else if (x > N && y > M)
            {
                cout << "NE"
                     << "\n";
            }
            else if (x < N && y < M)
            {
                cout << "SO"
                     << "\n";
            }
            else
            {
                cout << "SE"
                     << "\n";
            }
        }
    } while (k);

    /* #################### CODE END ################### */
#ifdef DEBUG
    cin.rdbuf(bkp_in);
    cout.rdbuf(bkp_out);
#endif
}