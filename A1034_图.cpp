#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 2010;

map<string, int> str2int;
map<int, string> int2str;
map<string, int> Gang; //头目名和成员人数

int n, w;
int totalPerson = 0;

int G[maxn][maxn] = { 0 };
int weight[maxn] = { 0 };
bool isVis[maxn] = { false };


int strToInt(string str){
	if (str2int.find(str) != str2int.end()){ //没找到
		return str2int[str];
	}
	else{
		str2int[str] = totalPerson;
		int2str[totalPerson] = str;
		return totalPerson++;
	}
}

void DFS(int index, int& head, int& gangNum, int& gangVal){
	gangNum++;
	isVis[index] = true;

	if (weight[index] > weight[head]){
		head = index;
	}

	for (int i = 0; i < totalPerson; i++){
		if (G[index][i] > 0 && isVis[i] == false){
			gangVal += G[index][i];
			DFS(i, head, gangNum, gangVal);
		}
	}
	cout << head << " " << gangNum <<" " <<" "<< gangVal << endl;
}

void DFSTrave(){
	for (int i = 0; i < totalPerson; i++){
		if (isVis[i] == false){
			int head = i, gangNum = 0, gangVal = 0;
			DFS(i, head, gangNum, gangVal);
			if (gangNum > 2 && gangVal > w){
				Gang[int2str[head]] = gangNum;
			}
		}
	}
}

int main(){
	cin >> n >> w;
	int k;
	string str1, str2;
	for (int i = 0; i < n; i++){
		cin >> str1 >> str2 >> k;
		int id1 = strToInt(str1), id2 = strToInt(str2);
		G[id1][id2] += k;
		G[id2][id1] += k;
		weight[id1] += k;
		weight[id2] += k;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << G[i][j] << " ";
		}
		cout << endl;
	}

	DFSTrave();
	
	cout << Gang.size() << endl;

	map<string, int> ::iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	

	return 0;
}