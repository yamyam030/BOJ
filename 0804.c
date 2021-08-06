#include <stdio.h>
int main(void)
{
	long long int n, i, j, a[100], b[100][2], rslt[100], check[100];
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		check[i] = -1;
		b[i][0] = a[i] * 3; 
		if (a[i] % 2 == 0)b[i][1] = a[i] / 2; 
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if ((b[j][0] == a[i]) || (b[j][1] == a[i])) { check[i] = j; break; }
		}
	}
	long long int s, index = n - 1;
	for (i = 0; i < n; i++)
		if (check[i] == -1) { s = i; break; }
	rslt[index] = a[s];
	while (index > 0)
	{
		for(i = 0 ; i < n ; i++)
			if (check[i] == s) { rslt[--index] = a[i]; s = i; break; }
	}
	for (i = 0; i < n; i++)
		printf("%lld ", rslt[i]);
}