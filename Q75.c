/*Q:Largest subarray with zero sum
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray*/

#include <stdio.h>

int maxLenZeroSum(int arr[], int n) {
    int max_len = 0;
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            
            if(sum == 0) {
                int len = j - i + 1;
                if(len > max_len)
                    max_len = len;
            }
        }
    }
    
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int result = maxLenZeroSum(arr, n);
    
    printf("%d\n", result);
    
    return 0;
}
 