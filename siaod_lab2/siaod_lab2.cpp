#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>

struct elem {
	char date[11];
	int temp;
	struct elem* next;
};

int hesh(char date[11])
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum += date[i];
	sum = sum % 100;

	return sum;
}

int main()
{
	char enter;
	struct elem* wether[100];

	for (int i = 0; i < 100; i++)
	{
		wether[i] = (struct elem*)malloc(sizeof(struct elem));
		wether[i]->next = NULL;
	}

	while (1)
	{
		int choose = 0;
		printf("(1) add (2) find (3) delete ");
		scanf("%d%c", &choose, &enter);
		switch (choose)
		{
		case 1:
		{
			//////////////////////////////////////////////добавление элемента
			char newdate[11] = { '\0' };
			printf("Enter date: ");
			gets_s(newdate);
			int newtemp;
			printf("Enter tempriture: ");
			scanf("%d%c", &newtemp, &enter);
			int sum = hesh(newdate);

			struct elem* current = wether[sum];
			while (current->next != NULL)
				current = current->next;

			current->next = (struct elem*)malloc(sizeof(struct elem));
			current = current->next;
			for (int i = 0; i < 11; i++)
				current->date[i] = newdate[i];
			current->temp = newtemp;
			current->next = NULL;
		}
		//////////////////////////////////////////////добавление элемента
		break;

		case 2:
		{
			//////////////////////////////////////////////поиск элемента
			char finddate[11] = { '\0' };
			printf("Enter date: ");
			gets_s(finddate);

			int findsum = hesh(finddate);

			struct elem* findcurr = wether[findsum];
			if (findcurr!=NULL)
			while ((findcurr->next != NULL) && (strcmp(findcurr->date, finddate) != 0))
				findcurr = findcurr->next;
			if (findcurr != NULL)
			if (strcmp(findcurr->date, finddate) == 0)
				printf("tempriture: %d\n", findcurr->temp); else
				printf("No such day\n"); else
				printf("No such day\n");
			//////////////////////////////////////////////поиск элемента
		}
		break;

		case 3:
		{
			//////////////////////////////////////////////удаление элемента
			char deldate[11] = { '\0' };
			printf("Enter date: ");
			gets_s(deldate);

			int delsum = hesh(deldate);

			struct elem* delcurr = wether[delsum];
			while ((delcurr->next != NULL) && (strcmp(delcurr->next->date, deldate) != 0))
				delcurr = delcurr->next;

			if (delcurr->next != NULL)
			if (strcmp(delcurr->next->date, deldate) == 0)
				delcurr->next = delcurr->next->next; else
				printf("No such day\n"); else
				printf("No such day\n");
			//////////////////////////////////////////////удаление элемента
		}
		}
	}
}