#include <stdio.h>
int main(void)
{
	long long int n, m, ans = 0, i, n2 = 0, n5 = 0;
	scanf("%lld %lld", &n, &m);
	for (i = 2; i <= n; i *= 2)
		n2 += (n / i);
	for (i = 5; i <= n; i *= 5)
		n5 += (n / i);
	for (i = 2; i <= (n - m); i *= 2)
		n2 -= ((n - m)/ i);
	for (i = 5; i <= (n - m); i *= 5)
		n5 -= ((n - m) / i);
	for (i = 2; i <= m; i *= 2)
		n2 -= (m / i);
	for (i = 5; i <= m; i *= 5)
		n5 -= (m / i);
	ans = n2 < n5 ? n2 : n5;
	printf("%lld", ans);
}