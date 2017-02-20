//A1071

//切分单词 + 记录次数，以前也做过一道类似的题，
//这里用string + map

#include <cstdio>
#include <string>
#include <iostream>//string类只能这样输入输出
#include <map>
using namespace std;

bool check(char c){
	if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

int main(){
	string str;
	getline(cin, str);//c++版gets
	map<string, int> count;

	string word;
	for (int i = 0; i < str.length(); i++){//length()时间复杂度是1，很棒		
		while (check(str[i])){//合理字符
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';//变为小写
			word += str[i];//可以用“+”，在后面直接加上字符
			i++;
		}

		if (word != ""){//本来想用一个flag来判断，但是没必要
			if (count.find(word) == count.end()) count[word] = 1;
			else count[word]++;	
			word.clear();
		}
	}
	string ans;
	int max = 0;
	for (map<string, int>::iterator it = count.begin(); it != count.end(); it++){
		if (it->second > max){
			max = it->second;
			ans = it->first;
		}
	}

	cout << ans << " " << max;

	return 0;
}