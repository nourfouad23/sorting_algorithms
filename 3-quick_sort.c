#include "sort.h"

void divide(int beg, int pivot, int *i, size_t size);
int partition(int beg, int pivot, int *i, size_t size);
void swap_int(int *a, int *b);
/**
 * quick_sort - sort func
 * @array: array param
 * @size: size param
 */
void quick_sort(int *array, size_t size)
{
	int begin = 0, pivot;

	if (array && size > 1)
	{
		pivot = (size - 1);
		divide(begin, pivot, array, size);
	}
}
/**
* divide - divide func
* @beg: param
* @pivot: param
* @i: param
* @size: param
**/
void divide(int beg, int pivot, int *i, size_t size)
{
	int first, second, res;

	if (beg < pivot)
	{
		second = partition(beg, pivot, i, size);
		first = beg;
		res = second - 1;
		if (first != res && second != pivot)
			res--;
		divide(first, res, i, size);
		divide(second, pivot, i, size);
	}
}
/**
* partition - divides an array
* @beg: beginning of array separated
* @pivot: end of array separated
* @i: the beginning of array
* @size: size of array
* Return: the new beginning
**/
int partition(int beg, int pivot, int *i, size_t size)
{
	int temp;

	temp = beg;
	while (temp != pivot)
	{
		if (i[temp] < i[pivot])
		{
			if (temp != beg)
			{
				swap_int(i + temp, i + beg);
				print_array(i, size);
			}
			temp++;
			beg++;
		}
		else
			temp++;
	}
	if (beg != pivot)
	{
		if (i[beg] > i[pivot])
		{
			swap_int(i + pivot, i + beg);
			print_array(i, size);
		}
		beg++;
	}
	return (beg);
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