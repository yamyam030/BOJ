#include <stdio.h>
int main(void)
{
	int a, b[42] = { 0 }, i, ans = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a);
		b[a % 42] = 1;
	}
	for (i = 0; i < 42; i++)
		if (b[i] == 1) ans++;
	printf("%d", ans);
}