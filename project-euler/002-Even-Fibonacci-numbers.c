#include <stdio.h>

/* Project Euler #2: Even Fibonacci numbers
Constraints
1 ≤ T ≤ 10^5
10 ≤ N ≤ 4×10^16
Sample Input
2
10
100
Sample Output
10
44
*/

#define MAX_SIZE 81

void calculate_fibonacci(unsigned long long int *fibonacci, int size) {
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    for (int i = 2; i < size; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
}

int main() {
    
    int test_cases;
    unsigned long long int value, sum, fibonacci[MAX_SIZE];
    
    calculate_fibonacci(fibonacci, MAX_SIZE);

    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%llu", &value);
        
        sum = 0;
        for (int i = 0; i < MAX_SIZE && fibonacci[i] <= value; i++)
            if (fibonacci[i] % 2 == 0)
                sum += fibonacci[i];
        
        printf("%llu\n", sum);
    }
    return 0;
}

