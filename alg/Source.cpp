#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int N;
double distArr[9][9];

double calc(vector<int>& path, vector<bool> visited, double dist) {
	bool allVisited = true;
	for (int i = 0; i < visited.size(); ++i) {
		if (!visited[i]) {
			allVisited = false;
			break;
		}
	}

	if (allVisited) {
		return dist;
	}


	double ret = 15000;
	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			int here = path.back();

			visited[i] = true;
			path.push_back(i);

			double cand = calc(path, visited, dist + distArr[here][i]);
			ret = ret < cand ? ret : cand;

			path.pop_back();
			visited[i] = false;
		}
	}

	return ret;
}


int main() {
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> distArr[i][j];
			}
		}

		vector<int> path;
		vector<bool> visited;
		for (int i = 0; i < N; ++i) {
			visited.push_back(false);
		}

		double ans = 15000;

		for (int i = 0; i < N; ++i) {
			path.push_back(i);
			visited[i] = true;
			double cand = calc(path, visited, 0);
			ans = ans < cand ? ans : cand;
			path.pop_back();
			visited[i] = false;
		}


		cout << fixed;
		cout.precision(10);

		cout << ans << '\n';
	}

	return 0;
}