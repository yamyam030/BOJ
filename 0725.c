#include <stdio.h>
int combination(int n, int r) {
	int rslt = 1;
	for (int i = 1; i <= r; i++)
		rslt = rslt * (n - i + 1) / i;
	return rslt;
}
int main(void)
{
	int t, n, m, i, a[30];
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		printf("%d\n", combination(m, n));
	}
}