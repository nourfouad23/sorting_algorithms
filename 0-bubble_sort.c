#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
* bubble_sort - sorting function
* @array: param
* @size: param
**/

void bubble_sort(int *array, size_t size)
{
size_t x, y;
int temp;
for (x = 0; x < size; x++)
{
for (y = 0; y < size - 1; y++)
{
if (array[y] > array[y + 1])
{
temp = array[y];
array[y] = array[y + 1];
array[y + 1] = temp;
print_array(array, size);
}
}
}
}