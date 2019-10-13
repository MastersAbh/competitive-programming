#include <iostream>
#include <algorithm>
using namespace std;


/*

In this solution we are have to give maximum sum subarray circular. So what we do here is we take normal karden algorithms for normal maximum sum subarray. Then we negate the array and take the maximum sum. Maximum negative mean minimum positive. So we subtract the minimum positive from the total sum to get the maximum total. Then we compare the both whichever is greater or smaller.

*/



// Function to find contiguous sub-array with the largest sum
// in given set of integers
int kadane(int arr[], int n)
{
    // stores maximum sum sub-array found so far
    int max_so_far = 0;

    // stores maximum sum of sub-array ending at current position
    int max_ending_here = 0;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // update maximum sum of sub-array "ending" at index i (by adding
        // current element to maximum sum ending at previous index i-1)
        max_ending_here = max_ending_here + arr[i];

        // if maximum sum is negative, set it to 0 (which represents
        // an empty sub-array)
        max_ending_here = max(max_ending_here, 0);

        // update result if current sub-array sum is found to be greater
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

// Function to find maximum sum circular subarray in a given array
int KadaneCircular(int arr[], int n)
{
    // negate all elements of the array
    for (int i = 0; i < n; i++)
        arr[i] = -arr[i];

    // run Kadane's algorithm on modified array
    int negMaxSum = kadane(arr, n);

    // restore the array
    for (int i = 0; i < n; i++)
        arr[i] = -arr[i];

    /*  return maximum of
    
	    1. sum returned by Kadane's algorithm on original array.
	       
	    2. sum returned by Kadane's algorithm on modified array + 
	       sum of all elements of the array.
    */

    return max(kadane(arr, n), accumulate(arr, arr + n, 0) + negMaxSum);
}

int main()
{
    int arr[] = { 2, 1, -5, 4, -3, 1, -3, 4, -1 };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "The sum of subarray with the largest sum is " <<
            KadaneCircular(arr, n);

    return 0;
}
