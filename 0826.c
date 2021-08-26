#include <stdio.h>
long long int M[100001];
int main(void)
{
	long long int n, i;
	scanf("%lld", &n);
	M[1] = 3, M[2] = 7;
	for (i = 3; i <= n; i++)
		M[i] = (2 + (M[i - 1] - M[i - 2]) + (M[i - 2] - 1) * 2 + M[i - 1]) % 9901;
	printf("%lld", M[n]);
}