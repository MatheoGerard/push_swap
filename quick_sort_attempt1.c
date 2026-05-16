/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_attempt1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:36:51 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/16 15:06:50 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



int partition(int arr[], int low, int high)
{
    int p = arr[low];
    int i = low;
    int j = high;

	while (i < j)
	{
		while (arr[i] <= p && i <= high - 1)
			i++;
		while (arr[j] > p && j >= low + 1)
			j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[low], &arr[j]);
	return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*int main() {
  
    int arr[] = { 4, 2, 5, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}*/

