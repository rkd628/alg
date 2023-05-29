#include <iostream>
#include <string>

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	int ts = 1;
	while (T--)
	{
		int N;
		cin >> N;

		int cnt = 0;
		for (int i = 0; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i * i + j * j <= N * N)
				{
					cnt++;
				}
			}
		}

		cout << "#" << ts++ << " " << cnt * 4 + 1 << "\n";
	}

	return 0;
}