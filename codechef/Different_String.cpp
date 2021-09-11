#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char c[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> c[i][j];
            }
        }
        string ans;
        for (int i = 0; i < n; i++)
        {
            int flag = c[i][i] - '0';
            flag = 1 - flag;
            ans += '0' + flag;
        }
        cout << ans << endl;
    }
    return 0;
}