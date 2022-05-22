//cypher text
//problem set 2
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int key;
char str[50];
char c[50];
gets_s(str);
printf("%s", str);
printf("\n");
printf("enter a single digit key : \n");
scanf("%i", &key);
printf("\n");
int n = strlen(str);
		for (int i = 0; i < n; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z'  || str[i]>='a' && str[i]<='z')
			{
				c[i] = str[i] + key;
			}
			else if (str[i] == 32)
			{
				c[i] = 32;
			}
			else
			{
				str[i] = c[i];
			}
		  }
		for (int i = 0; i < n; i++)
		{
			printf("%c ",c[i]);
			}
		return 0;
}