#include "sort.h"
void swap_int(int *a, int *b);
/**
* selection_sort - sort function
* @array: array param
* @size: size param
**/
void selection_sort(int *array, size_t size)
{
	size_t x, y;
	int *temp;

	temp = NULL;
	for (x = 0; array && x < size - 1; x++)
	{
		temp = NULL;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[x])
			{
				if (temp && array[y] < *temp)
					temp = &array[y];
				if (!temp)
					temp = &array[y];
			}
		}
		if (temp)
		{
			swap_int(temp, &array[x]);
			print_array(array, size);
		}
	}
}
/**
* swap_int - func to swap
* @a: param
* @b: param
**/
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}