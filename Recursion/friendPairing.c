// Given n friends, each one can remain single or can be paired up with
// some other friend. Each friend can be paired only once. Find out the
// total number of ways in which friends can remain single or can be
// paired up.

// Examples :

// Input: n = 3
// Output: 4
// Explanation:
// {1}, {2}, {3} : All single
// {1}, {2,3} : 2 and 3 paired but 1 is single.
// {1,2}, {3} : 1 and 2 are paired but 3 is single.
// {1,3}, {2} : 1 and 3 are paired but 2 is single.
// Note that {1,2} and {2,1} are considered same.

#include <stdio.h>

int countWays(int n) {
    if (n==0 || n==1)
        return 1;
    
    return countWays(n - 1) + (n - 1) * countWays(n - 2);
}

int main() {
    int n;
    printf("Enter the number of friends: ");
    scanf("%d", &n);
    
    printf("Total number of ways: %d\n", countWays(n));
    return 0;
}
