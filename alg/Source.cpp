#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

char arr[10][17] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

const int INF = 9999;

int calc(int cur[17], int count, int start) {
	if (start == 10) {
		bool complete = true;
		for (int i = 0; i < 16; ++i) {
			if (cur[i] != 12) {
				complete = false;
				break;
			}
		}

		if (complete) {
			return count;
		} else {
			return INF;
		}
	}

	int ret = INF;
		for (int k = 1; k <= 4; ++k) {
			for (int j = 0; j < 16; ++j) {
				if (arr[start][j] == 'x') {
					cur[j] += 3;
					if (cur[j] >= 15) {
						cur[j] -= 12;
					}
				}
			}

			int cand = calc(cur, count + (k%4), start + 1);
			ret = ret < cand ? ret : cand;
		}

	return ret;
}


int main() {
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int cur[17];
		for (int i = 0; i < 16; ++i) {
			cin >> cur[i];
		}

		int ans = calc(cur, 0, 0);
		if (ans == INF) {
			ans = -1;
		}
		cout << ans << '\n';
	}

	return 0;
}