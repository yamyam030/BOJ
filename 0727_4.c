#include <stdio.h>
char text[1000000];
int main(void)
{
	int num = 666, count = 1, n;
	scanf("%d", &n);
	while (count <= n)
	{
		sprintf(text, "%d", num);
		for (int i = 0; text[i + 2] != '\0'; i++)
		{
			if ((text[i] == '6') && (text[i + 1] == '6') && (text[i + 2] == '6')) 
			{ count++; break; }
		}
		num++;
	}
	printf("%s", text);
}