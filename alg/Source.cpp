#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int H, W;
char arr[21][21];

int dy[][2] = { { -1, -1 }, { -1, -1 }, { -1, 0 }, { 0, -1 } };
int dx[][2] = { { 0, -1 }, { 0, 1 }, { 0, 1 }, { 1, 1 } };

int count(char arr[21][21]) {
	int startY = -1, startX = -1;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (arr[i][j] == '.') {
				startY = i;
				startX = j;
				break;
			}
		}
	}

	if (startY == -1) {
		return 1;
	}

	int ret = 0;
	for (int n = 0; n < 4; ++n) {
		int y1 = startY + dy[n][0];
		int x1 = startX + dx[n][0];

		int y2 = startY + dy[n][1];
		int x2 = startX + dx[n][1];

		if (y1 >= 0 && y1 < H && x1 >= 0 && x1 < W
			&& y2 >= 0 && y2 < H && x2 >= 0 && x2 < W) {
			if (arr[y1][x1] == '.' && arr[y2][x2] == '.') {
				arr[y1][x1] = '#';
				arr[y2][x2] = '#';
				arr[startY][startX] = '#';

				ret += count(arr);

				arr[y1][x1] = '.';
				arr[y2][x2] = '.';
				arr[startY][startX] = '.';
			}
		}
	}
	return ret;
}



int main() {
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		cin >> H >> W;

		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> arr[i][j];
			}
		}

		cout << count(arr) << '\n';

	}

	return 0;
}