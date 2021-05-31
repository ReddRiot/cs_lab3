#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
// C++ implementation of Comb Sort
using namespace std;

// To find gap between elements
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

// Function to sort a[0..n-1] using Comb Sort
void combSort(int a[], int n)
{
    // Initialize gap
    int gap = n;

    // Initialize swapped as true to make sure that
    // loop runs
    bool swapped = true;

    // Keep running while gap is more than 1 and last
    // iteration caused a swap
    while (gap != 1 || swapped == true)
    {
        // Find next gap
        gap = getNextGap(gap);

        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false;

        // Compare all elements with current gap
        for (int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

// Driver program
int main()
{
    const int N = 100000000;
    int* arr = new int[N];
    srand(1);
    for (int i = 0;i < N; i++)
        arr[i] = rand();
    combSort(arr, N);
    return 0;
}