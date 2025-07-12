#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

/**
   Merges two adjacent ranges in an array.
   @param a the array with the elements to merge
   @param from the start of the first range
   @param mid the end of the first range
   @param to the end of the second range
*/
void merge(int a[], int from, int mid, int to)
{
    int n = to - from + 1; // Size of the range to be merged 
    int* b = new int[n];   // Temporary array for merging

    int i1 = from;       // Index for left subarray
    int i2 = mid + 1;    // Index for right subarray
    int j = 0;           // Index for temp array

    // Merge elements from both halves into b[]
    while (i1 <= mid && i2 <= to)
    {
        if (a[i1] < a[i2])
        {
            b[j++] = a[i1++];
        }
        else
        {
            b[j++] = a[i2++];
        }
    }

    // Copy remaining elements of the first half
    while (i1 <= mid)
    {
        b[j++] = a[i1++];
    }

    // Copy remaining elements of the second half
    while (i2 <= to)
    {
        b[j++] = a[i2++];
    }

    // Copy merged result back into original array
    for (int k = 0; k < n; k++)
    {
        a[from + k] = b[k];
    }

    delete[] b; // Free temporary array
}

/**
   Iteratively sorts the elements in a range of an array using merge sort.
   @param a the array with the elements to sort
   @param from start of the range to sort
   @param to end of the range to sort
*/
void merge_sort(int a[], int from, int to)
{
    int n = to - from + 1;

    for (int size = 1; size < n; size *= 2)
    {
        for (int start = from; start <= to; start += 2 * size)
        {
            int mid = min(start + size - 1, to);
            int end = min(start + 2 * size - 1, to);

            if (mid < end)
            {
                merge(a, start, mid, end);
            }
        }
    }
}

/**
   Prints all elements in an array.
   @param a the array to print
   @param size the number of elements in a
*/
void print(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    const int SIZE = 20;
    int values[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        values[i] = rand() % 100;
    }

    cout << "Before sorting:\n";
    print(values, SIZE);

    merge_sort(values, 0, SIZE - 1);

    cout << "After sorting:\n";
    print(values, SIZE);

    return 0;
}
