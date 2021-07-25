#include <stdio.h>
#include <math.h>
int x[2], y[2], x3[2], y3[2];
int f(int r1, int r2)
{
	int d = (pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2));
	if ((x[0] == x[1]) && (y[0] == y[1]))
	{
		if (r1 == r2)return -1;
		return 0;
	}
	if (pow((r1 - r2), 2) == d)return 1;
	else if (pow((r1 - r2), 2) < d)
	{
		if (pow((r1 + r2), 2) == d)return 1;
		else if (pow((r1 + r2), 2) < d)return 0;
		else return 2;
	}
	else return 0;
}
int main(void)
{
	int n, i, r1, r2, a, b;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d %d %d", &x[0], &y[0], &a, &x[1], &y[1], &b);
		r1 = (a > b) ? a : b;
		r2 = (a < b) ? a : b;
		printf("%d\n", f(r1, r2));
	}
}//0725