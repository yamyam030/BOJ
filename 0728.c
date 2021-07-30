#include <stdio.h>
int a[1000][1001];
double average(int index, int studentNumber)
{
	int i;
	double sum = 0, average = 0, count = 0, x, y;
	for (i = 1; i <= studentNumber; i++)
		sum += a[index][i];
	average = sum / studentNumber;
	for (i = 1; i <= studentNumber; i++)
		if (a[index][i] > average)count++;
	x = 100 / (double)studentNumber;
	y = x * count;
	return y;
}
int main(void)
{
	int c, i, j;
	scanf("%d", &c);
	for (i = 0; i < c; i++)
	{
		scanf("%d", &a[i][0]);
		for (j = 1; j <= a[i][0]; j++)
			scanf("%d", &a[i][j]);
		printf("%.3f%%\n", average(i, a[i][0]));
	}
}