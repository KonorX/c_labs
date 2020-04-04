#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int m, n;

void pirog(int** a);

void eating(int **a)
{
	int ve, he;
	printf("choose a vertical point part  ");
	scanf_s("%i", &ve);
	printf("choose a horizontal point part  ");
	scanf_s("%i", &he);
	for ( int i = 0; i < ve ; i++)
	{
		if (he == 0)
		{
			a[i][he] = 0;
		}
		else 
		{
			a[i][he - 1] = 0;
		}
		
		
	}
	for ( int u = he;  u < n-1;  u++)
	{
		if (ve==0)
		{
			a[ve][u] = 0;
		}
		else 
		{
			a[ve - 1][u] = 0;
		}
		
	}
	pirog(a);
}

void pirog(int **a)
{
	for (int u = 0; u < m - 1; u++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			printf("\t %i", a[u][i]);
		}
		printf("\n");
	}
	
	if (a[m-2][0]==0)
	{
		system("cls");
		printf("game over");
		exit(0);
	}
	int t = 0;
	while (t==0)
	{
		printf("1)tutorial\n");
		printf("2)choose a part\n");
		printf("3)exit\n");
		scanf_s("%i", &t);
		switch (t)
		{
		case 1:
			system("cls");
			printf("if you choose a part(cell) you'll eat that part in the pie\n ");
			printf("also you'll eat & parts that are higher on that line & parts \n");
			printf("that are right to that part, if you'll eat the poisoned part you'll die\n");
			printf("parts that are not  eaten are displayed as 1, that are eaten as 0\n");
			Sleep(3000);
			pirog(a);
			break;
		case 2:
			eating(a);
			break;
		case 3:
			exit(0);
			break;
		default:
			system("cls");
			printf("try again\n");
			pirog(a);
			break;
		}
	}
}

int main()
{
	printf("enter vertical parts  \n");
	scanf_s("%i", &m);
	printf("enter horizontal parts  \n");
	scanf_s("%i", &n);
	m = m + 1;
	n = n + 1;
	int** pir;
	
	pir = new int* [m];
	for (int u = 0; u < m - 1; u++)
	{
		
			pir[u] = new int [n];
			
		
	}

	
	for (int u = 0; u < m - 1; u++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			pir[u][i] = 1;
		}
		
	}
	pirog(pir);
	return 0;
}