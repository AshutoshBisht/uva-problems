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
    int count = 1;
    while (1)
    {
        string str;
        getline(cin, str);

        if (str.length() == 0)
            break;

        string left = "``";
        string right = "''";
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '"' && count == 1)
            {
                count = 2;
                cout << left;
            }
            else if (str[i] == '"' && count == 2)
            {
                count = 1;
                cout << right;
            }
            else
            {
                cout << str[i];
            }
        }
        cout << "\n";
    }

    /* #################### CODE END ################### */
#ifdef DEBUG
    cin.rdbuf(bkp_in);
    cout.rdbuf(bkp_out);
#endif
}