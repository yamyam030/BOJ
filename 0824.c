#include <stdio.h>
int main(void)
{
	int a[10001], n, M[10001], i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &a[i]);
	M[1] = a[1], M[2] = a[1] + a[2];
	for (i = 3; i <= n; i++)
	{
		M[i] = (M[i - 2] + a[i] > M[i - 3] + a[i - 1] + a[i]) ? M[i - 2] + a[i] : M[i - 3] + a[i - 1] + a[i];
		M[i] = M[i] > M[i - 1] ? M[i] : M[i - 1];
	}
	printf("%d", M[n]);
}