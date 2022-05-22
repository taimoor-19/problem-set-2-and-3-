//problem set 3
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
//#define MAX_VOTERS 100
//#define MAX_CANDIDATES 9
int preferences[4][3];
//voter//canditate
typedef struct {
	char name[50];
	int votes = 0;
	bool elminated = false;
}canditate;
canditate canditates[3];
int votercount;
int canditatecount;


//functions
bool vote(int voter, int rank, char name[50]);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
int main()
{
	printf("enter number of voters(1-4) \n");
	scanf("%i", votercount);
	printf("enter number of canditates(1-3) \n");
	scanf("%i", canditatecount);
	if (votercount > 4)
	{
		return 1;
	}



	for (int i = 0; i < votercount; i++)
	{
		for (int j = 0; j < canditatecount; j++)
		{
			char name[50];
			printf("rank %i :", j + i);
			scanf("%s", name);
			if (!vote(i, j, name))
			{
				printf("invalid vote  \n");
			}
			return 3;
		}
		printf("\n");
	}
	while (true)
	{
		tabulate();
		bool win = print_winner();
		if (win)
		{
			break;
		}
	}
	int min = find_min();

	bool tie = is_tie(min);
	if (tie)
	{
		for (int i = 0; i < canditatecount; i++)
		{
			if (!canditates[i].elminated)
			{
				printf("%s \n", canditates[i].name);
			}

		}

	}
	eliminate(min);
	for (int i = 0; i < canditatecount; i++)
	{
		canditates[i].votes = 0;
	}
	return 0;

}
bool vote(int voter, int rank, char name[50])
{
	for (int i = 0; i < canditatecount; i++)
	{
		if (strcmp(canditates[i].name, name) == 0)
		{
			preferences[voter][rank] == i;
			return true;
		}


	}
	return false;
}
void tabulate()
{
	for (int i = 0; i < votercount; i++)
	{
		for (int j = 0; j < canditatecount; j++)
		{
			if (!canditates[preferences[i][j]].elminated)
			{
				canditates[preferences[i][j]].votes++;
				break;
			}
		}
	}
	return;
}
bool print_winner()
{
	int votwin = votercount / 2;
	for (int i = 0; i < canditatecount; i++)
	{
		if (canditates[i].votes > votwin)
		{
			printf("%s  \n", canditates[i].name);
			return true;
		}
	}
	return false;
}
int find_min(void)
{
	int leastvotes = votercount;
	for (int i = 0; i < canditatecount; i++)
	{
		if (!canditates[i].elminated && canditates[i].votes < leastvotes)
		{
			canditates[i].votes = leastvotes;
		}
	}
	return leastvotes;
}
bool istie(int min)
{
	for (int i = 0; i < canditatecount; i++)
	{
		if (canditates[i].votes > min)
		{
			return false;

		}
	}
	return true;
}
void eliminate(int min)
{
	for (int i = 0; i < canditatecount; i++)
	{
		if (canditates[i].votes == min)
		{
			canditates[i].elminated = true;
		}
	}
	return;
}