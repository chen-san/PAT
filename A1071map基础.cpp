//A1071

//�зֵ��� + ��¼��������ǰҲ����һ�����Ƶ��⣬
//������string + map

#include <cstdio>
#include <string>
#include <iostream>//string��ֻ�������������
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
	getline(cin, str);//c++��gets
	map<string, int> count;

	string word;
	for (int i = 0; i < str.length(); i++){//length()ʱ�临�Ӷ���1���ܰ�		
		while (check(str[i])){//�����ַ�
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';//��ΪСд
			word += str[i];//�����á�+�����ں���ֱ�Ӽ����ַ�
			i++;
		}

		if (word != ""){//��������һ��flag���жϣ�����û��Ҫ
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