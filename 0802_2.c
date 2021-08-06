#include <stdio.h>
int main(void)
{
	int i, d = 10, c = 26, sum = 1;
	char a[5];
	scanf("%s", a);
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i - 1] == a[i])
		{
			if (a[i] == 'd') sum *= (d - 1);
			if (a[i] == 'c') sum *= (c - 1);
		}
		else
		{
			d = 10; c = 26;
			if (a[i] == 'd') sum *= d;
			if (a[i] == 'c') sum *= c;
		}
	}
	printf("%d", sum);
}