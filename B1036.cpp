//B1036

//图形输出题 唯一的难点就是row是行，col是列，我下面好像都写反了，算了不改了

#include<cstdio>

int main(){
	int row, col;
	char c;

	scanf("%d %c", &row, &c);

	col = (row + 1) / 2;//除以二后的四舍五入的快捷方法

	for (int i = 1; i <= col; i++){
		if (i == 1 || i == col){
			for (int j = 0; j < row; j++){
				printf("%c", c);
			}
			printf("\n");
		}
		else{
			printf("%c", c);
			for (int j = 1; j < row - 1; j++){
				printf(" ");
			}
			printf("%c\n", c);
		}
	}
	return 0;
}
