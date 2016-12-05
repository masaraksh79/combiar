/*
 ============================================================================
 Name        : combina.c
 Author      : Alex M.
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT	5
#define MAX_STR		64

double arr_a[MAX_INPUT] = {0}, arr_b[MAX_INPUT] = {0};
int indices[MAX_INPUT] = {0};
double s;

char* mystrsep(char** stringp, const char* delim)
{
  char* start = *stringp;
  char* p;

  p = (start != NULL) ? strpbrk(start, delim) : NULL;

  if (p == NULL)
  {
    *stringp = NULL;
  }
  else
  {
    *p = '\0';
    *stringp = p + 1;
  }

  return start;
}

void parse_input(const char *string, double num[])
{
	char *c, *s, *delim = " ,";
	int i = 0;

	s = (char *)string;
	while (NULL != (c = mystrsep(&s, delim)))
	{
		num[i++] = atof(c);
		if (i == MAX_INPUT)
			break;
	}
}

void print_combinations(const char *string)
{
    int i, j, k;
    int len = strlen(string);

    for (i = 0; i < len - 2; i++)
    {
        for (j = i + 1; j < len - 1; j++)
        {
            for (k = j + 1; k < len; k++)
                printf("%c%c%c\n", string[i], string[j], string[k]);
        }
    }
}

void get_3_n_indices(int *i, int *j, int *k, int n)
{
	static int begin = 0, exp_k = 0, exp_j = 0;

	if (!begin)
	{
		*i = 0;
		*j = 1 + (*i);
		*k = 1 + (*j);
		begin = 1;
		return;
	}

	if (!exp_k && *k < n - 1)
	{
		(*k)++;
		return;
	}

	exp_k = 1;

	if (!exp_j && *j < n - 2)
	{
		*j = 1 + (*i);
		(*j)++;
		*k = 1 + (*j);
		exp_k = 0;
		return;
	}

	exp_j = 1;

	if (*i < n - 3)
	{
		(*i)++;
		*k = 1 + (*j);
		*j = 1 + (*i);
		exp_k = 0; exp_j = 0;
		return;
	}
}

void f(int *i, int *j, int *k, int n)
{
   for (*i = 0; *i < n - 2; (*i)++)
    {
        for (*j = (*i) + 1; *j < n - 1; (*j)++)
        {
            for (*k = *j + 1; *k < n; (*k)++)
            {

            }
        }
    }
}



int main(void)
{
	int i;
	char inp_a[MAX_STR] = "1 2 3 4 5";
	char inp_b[MAX_STR] = "1 2 3 4 5";

	int p = 0, q = 0, r = 0;

	parse_input(inp_a, arr_a);
	parse_input(inp_b, arr_b);

	printf("\n\narray1: ");
	for (i = 0; i < MAX_INPUT; i++)
		printf("%.1f ", arr_a[i]);
	printf("\n");
	printf("array2: ");
	for (i = 0; i < MAX_INPUT; i++)
		printf("%.1f ", arr_b[i]);
	printf("\n\n");

	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);
	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);
	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);
	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);
	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);
	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);
	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);
	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);
	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);
	get_3_n_indices(&p,&q,&r,MAX_INPUT);
	printf("%d %d %d\n", p, q, r);


	return EXIT_SUCCESS;
}
