#include <stdio.h>
int main(void)
{
	int a, b, v, n;
	scanf("%d %d %d", &a, &b, &v);
	n = (v - b) / (a - b);
	if (n * a - (n - 1) * b < v)n++;
	printf("%d", n);
}