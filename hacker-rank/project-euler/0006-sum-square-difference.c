#include <stdio.h>
/* Project Euler #6: Sum square difference
Constraints
1 ≤ T ≤ 10^3
1 ≤ N ≤ 10^3
Sample Input
2
3
10
Sample Output
22
2640
*/

int main() {
    
    int test_cases;
    int n;
    unsigned long long int sum_of_squares, sum_squared;
    long long int difference;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &n);
        
        sum_of_squares = 0;
        sum_squared = 0;
        for (int i = 1; i <= n; i++) {
            sum_of_squares += i * i;
            sum_squared += i;
        }
        sum_squared = sum_squared * sum_squared;
        difference = sum_squared - sum_of_squares;

        printf("%lld\n", difference);
    }
    return 0;
}
