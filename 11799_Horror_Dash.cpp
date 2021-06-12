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
    int x = 1;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int max_speed = 0;
        for (int i = 0; i < n; i++)
        {
            if (max_speed < arr[i])
                max_speed = arr[i];
        }
        cout << "Case " << x << ": " << max_speed << "\n";
        x++;
    }
    /* #################### CODE END ################### */
#ifdef DEBUG
    cin.rdbuf(bkp_in);
    cout.rdbuf(bkp_out);
#endif
}