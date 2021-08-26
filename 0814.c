#include <stdio.h>
int a[5][5], list[100000], x[4] = { -1,0,1,0 }, y[4] = { 0,1,0,-1 }, index = 0;
void f(int i, int j, int num, int count)
{
	int k, add;
	num = num * 10 + a[i][j];
	if (count == 6)
	{
		add = 1;
		for (k = 0; k < index; k++)
			if (num == list[k]) { add = 0; break; }
		if (add == 1) list[index++] = num;
		return;
	}
	for (k = 0; k < 4; k++)
		if ((i + x[k] >= 0) && (i + x[k] < 5) && (j + y[k] >= 0) && (j + y[k] < 5))
			f(i + x[k], j + y[k], num, count + 1);
}
int main(void)
{
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			f(i, j, 0, 1);
	printf("%d", index);
}