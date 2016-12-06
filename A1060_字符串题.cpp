#include <iostream>
#include <string>

using namespace std; 

int n, e1 = 0, e2 = 0;
string s1, s2, d1, d2;

string deal(string str, int &e){
	while (str[0] == '0'){
		str.erase(str.begin());
	}
	if (str[0] == '.'){
		str.erase(str.begin());
		while (str[0] == '0'){
			str.erase(str.begin());
			e--;
		}

		if (str.length() == 0)
			e = 0;
	}

	else{
		if (str.find('.') != -1){
			int pos = str.find('.');
			e = pos;
			str.erase(pos, 1);
		}
		else
			e = str.length();
	}

	string res;
	for (int i = 1; i <= n; i++){
		if (str.length() >= i)
			res += str[i - 1];
		else
			res += '0';
	}

	return res;



}



int main(){
	cin >> n >> s1 >> s2;

	d1 = deal(s1, e1);
	d2 = deal(s2, e2);

	if (d1 == d2 && e1 == e2){
		cout << "YES 0." << d1 << "*10^" << e1 << endl;
	}
	else
		cout << "NO 0." << d1 << "*10^" << e1 << " 0." << d2 << "*10^" << e2 << endl;


	return 0;
}



