#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--)
	{
		int r, c, x;
		cin >> r >> c >> x;
		int a[r][c], b[r][c];
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> b[i][j];
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j <= c - x; j++)
			{
				if (a[i][j] != b[i][j])
				{
					int diff = b[i][j] - a[i][j];
					for (int k = 0; k < x; k++)
					{
						a[i][j + k] += diff;
					}
				}
			}
		}
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j <= r - x; j++)
			{
				if (a[j][i] != b[j][i])
				{
					int diff = b[j][i] - a[j][i];
					for (int k = 0; k < x; k++)
					{
						a[j + k][i] += diff;
					}
				}
			}
		}
		bool equal = true;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (a[i][j] != b[i][j])
				{
					equal = false;
					break;
				}
			}
			if (!equal)
				break;
		}
		if (equal)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
		cout << "\n";
	}
	return 0;
}