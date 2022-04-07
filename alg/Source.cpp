#include <iostream>

using namespace std;

string str;
int indx;

string rev() {
	int cur = indx;
	indx++;

	if (str[cur] == 'w' || str[cur] == 'b') {
		return string(1, str[cur]);
	}

	string leftUpper = rev();
	string rightUpper = rev();
	string leftLower = rev();
	string rightLower = rev();

	return 'x' + leftLower + rightLower + leftUpper + rightUpper;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		cin >> str;
		indx = 0;
		
		cout << rev() << '\n';
	}

	return 0;
}