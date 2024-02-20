#include "sort.h"

/**
* swap_ele - swaps elements
* @x: element to be swapped
* @y: element to be swapped
* Return: nothing
*/
void swap_ele(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - creates order of element based on lomuto partition scheme
 * @array: array of integers
 * @size: size of the array
 * @left: The start index of the first set of element
 * @right: The end index of the second set of element
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ele(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ele(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}


/**
 * lomuto_sort - sorts elements based on lomuto scheme
 * @array: array of integers
 * @size: size of the array
 * @left: The start index of the first set of element
 * @right: The end index of the second set of element
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}



/**
 * quick_sort - Sort an array of integers using quick sort
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
