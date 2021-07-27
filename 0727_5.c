#include <stdio.h>
int main(void)
{
	int i, j, count = 0;
	char text[101], special[4] = "dz=", a[7][3] = { "c=","c-","d-","lj","nj","s=","z=" };
	scanf("%s", text);
	for (i = 0; text[i + 2] != '\0'; i++)
	{
		if ((text[i] == special[0]) && (text[i + 1] == special[1]) && (text[i + 2] == special[2]))
		{
			text[i] = '0'; text[i + 1] = '0'; text[i + 2] = '0'; count++; j + 2;
		}
	}
	for (i = 0; i < 7; i++)
	{
		for (j = 0; text[j + 1] != '\0'; j++)
		{
			if((text[j]==a[i][0])&&(text[j+1]==a[i][1]))
			{
				text[j] = '0'; text[j + 1] = '0'; count++; j++;
			}
		}
	}
	for (i = 0; text[i] != '\0'; i++)
	{
		if ((text[i] >= 'a') && (text[i] <= 'z'))count++;
	}
	printf("%d", count);
}