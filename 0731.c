#include <stdio.h>
int main(void)
{
	int n, i, j, count = 0, check = 0;
	char word[101], alpha[26], c;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		while (getchar() != '\n');
		scanf("%s", word);
		for (int k = 0; k < 26; k++)
			alpha[k] = 0;
		check = 0;
		for (j = 0; word[j] != '\0'; j++)
		{
			if (alpha[word[j] - 'a'] == 0)
			{
				c = word[j];
				alpha[c - 'a'] = 1;
				while (word[j + 1] == c)j++;
			}
			else { check = 1; break; }
		}
		if (check == 0)count++;
	}
	printf("%d", count);
}