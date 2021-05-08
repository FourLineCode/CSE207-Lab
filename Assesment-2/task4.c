#include <stdio.h>

void bin(int k, int n, char* str)
{
	if(n == k)
	{
		str[n] = '\0';
		printf("%s ", str);
		return;
	}

	if(str[n-1] == '1')
	{
		str[n] = '0';
		bin(k, n+1, str);
	}
	else
	{
		str[n] = '0';
		bin(k, n+1, str);

		str[n] = '1';
		bin(k, n+1, str);
	}
}

int main()
{
	int k;
	scanf("%d", &k);

	char str[k];

	str[0] = '0';
	bin(k, 1, str);

	str[0] = '1';
	bin(k, 1, str);

	printf("\n");
	return 0;
}