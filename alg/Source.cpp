#include <iostream>
#include <string>

using namespace std;

int stringToInt(string str) {
	int ret=0;
	for (int i=0;i<str.length();++i) {
		ret*=10;
		int a = str[i] - '0';
		ret += a;
	}
	return ret;
}

int main() {

	int T;
	cin>>T;

	int ts=1;
	while(T--) {
		string s;
		cin>>s;

		int minn = 999999999;
		for (int i=1;i<s.length(); ++i) {
			string s1 = s.substr(0, i);
			string s2 = s.substr(i,s.length());

			int a1 = stringToInt(s1);
			int a2 = stringToInt(s2);
			
			minn = minn > a1 + a2 ? a1 + a2 : minn;
		}

		cout <<"#"<<ts++<< " "<<minn<<"\n";
	}

	return 0;
}