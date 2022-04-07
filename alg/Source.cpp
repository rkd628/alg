#include <iostream>
#include <time.h>

using namespace std;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w+", stdout);

	clock_t start, end;
	int temp;

	start = clock();
	for (int i = 0; i < 10000000; ++i) {
		//scanf("%d", &temp);
		cin >> temp;
	}
	end = clock();

	double result = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("%f", result);
	cout << result;

	return 0;
}