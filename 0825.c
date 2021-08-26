#include <stdio.h>
int main(void)
{
	char a[8][9];
	int i, j, cnt = 0;
	for (i = 0; i < 8; i++)
		for (j = 0; j <= 8; j++)
			scanf("%c", &a[i][j]);
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if ((j % 2 == 0) && (a[i][(i + j) % 8] == 'F'))	cnt++;
	printf("%d", cnt);
}