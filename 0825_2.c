#include <stdio.h>
int main(void)
{
	char str[256];
	int ans;
	scanf("%[^\n]s", str);
	while (str[0] != '#')
	{
		ans = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if ((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u'))ans++;
			if ((str[i] == 'A') || (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U'))ans++;
		}
		printf("%d\n", ans);
		while (getchar() != '\n');
		scanf("%[^\n]s", str);
	}
}