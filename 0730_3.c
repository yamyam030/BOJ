#include <stdio.h>
#include <string.h>
int main(void)
{
	char text1[10001], text2[100][101], * word[100], * sound[100], * p, s[20000];
	int r1 = 0, r2 = 0, check = 0, i, j, t, k;
	scanf("%d", &t);
	for (k = 0; k < t; k++)
	{
		while (getchar() != '\n');
		scanf("%[^\n]s", text1);
		p = strtok(text1, " ");
		while (p != NULL)
		{
			word[r1] = p; r1++; p = strtok(NULL, " ");
		}
		while (1)
		{

			while (getchar() != '\n');
			scanf("%[^\n]s", s);
			if (strcmp(s, "what does the fox say?") == 0)break;
			strcpy(text2[r2], s);
			p = strtok(text2[r2], " ");
			while (p != NULL)
			{
				sound[r2] = p; p = strtok(NULL, " ");
			}
			r2++;
		}
		for (i = 0; i < r1; i++)
		{
			check = 0;
			for (j = 0; j < r2; j++)
			{
				if (strcmp(word[i], sound[j]) == 0) { check = 1; break; }
			}
			if (check == 0)printf("%s ", word[i]);
		}
		printf("\n");
		r1 = 0; r2 = 0;
	}
}//0731