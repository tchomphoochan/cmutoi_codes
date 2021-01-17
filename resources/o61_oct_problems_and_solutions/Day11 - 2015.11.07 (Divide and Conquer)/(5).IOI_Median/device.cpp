#include "device.h"
#include <stdio.h>

#define UNINITIALIZED 0
#define GOT_N 1
#define INVALID 2

#define MAX_N 1500

#define FOR(__i, __times) for(int __i=0; __i<__times; __i++)

int __state = UNINITIALIZED;
int __data[MAX_N];
int __n;
int __call_count = 0;

int GetN()
{
	if (__state == UNINITIALIZED)
	{
		scanf("%d", &__n);
		FOR(i, __n)
		{
			int x;
			scanf("%d", &x);
			__data[i+1] = x;
		}
		__state = GOT_N;
		return __n;
	}
	else
	{
		__state = INVALID;
		return __n;
	}
}

void Answer(int m)
{
	if (__state != GOT_N)
		printf("-1\n");
	else
	{
		printf("%d\n", m);
		__state = INVALID;
	}
}

int Med3(int x, int y, int z)
{
	if (__state != GOT_N)
	{
		__state = INVALID;
		return 0;
	}
	else if (x < 1 || y < 1 || z < 1 || x > __n || y > __n || z > __n)
	{
		__state = INVALID;
		return 0;
	}
	else if (__call_count >= 7777)
	{
		__state = INVALID;
		return 0;
	}
	else
	{
		__call_count++;
		if (__data[x] < __data[y] && __data[x] > __data[z])
			return x;
		else if (__data[x] > __data[y] && __data[x] < __data[z])
			return x;
		else if (__data[y] < __data[x] && __data[y] > __data[z])
			return y;
		else if (__data[y] > __data[x] && __data[y] < __data[z])
			return y;
		else if (__data[z] < __data[x] && __data[z] > __data[y])
			return z;
		else
			return z;
	}
}
