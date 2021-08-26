#include <stdio.h>
int main(void)
{
	int i, n, b[100][3], old = 0, young = 0;
	char name[100][16];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", name[i]);
		scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
		if (b[i][2] <= b[old][2])
		{
			if (b[i][2] == b[old][2])
			{
				if (b[i][1] == b[old][1])
				{
					if (b[i][0] < b[old][0])old = i;
				}
				if (b[i][1] < b[old][1])old = i;
			}
			else old = i;
		}
		if (b[i][2] >= b[young][2])
		{
			if (b[i][2] == b[young][2])
			{
				if (b[i][1] == b[young][1])
				{
					if (b[i][0] > b[young][0])young = i;
				}
				if (b[i][1] > b[young][1])young = i;
			}
			else young = i;
		}
	}
	printf("%s\n%s", name[young], name[old]);
}