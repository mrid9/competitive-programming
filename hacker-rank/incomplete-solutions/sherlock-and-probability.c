#include <stdio.h>
#include <math.h>

/* Sherlock and Probability
 Constraints
 1 ≤ T ≤ 10^5
 1 ≤ N ≤ 10^5
 1 ≤ K ≤ N
 Sample input
 2
 4 3
 1011
 4 1
 1011
 Sample output
 9/16
 5/16
3
 */

long int gcd(long int a, long int b) {
    
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    
    long int i, j, test_cases, N, K, total, valid, M;
    char s[100002];
    int ones[100002];
    
    scanf("%ld", &test_cases);
    
    while (test_cases--) {
        
        scanf("%ld %ld\n", &N, &K);
        scanf("%s", s);
        
        total = N * N;
        valid = 0;
        M = 0;
        
        for (int i = 0; i < N; i++) {
            if (s[i] == '1')
                ones[M++] = i;
        }
        valid += M;
        
        for (i = 0; i < M; i++) {
            for (j = i + 1; j < M; j++) {
                if (ones[j] - ones[i] <= K) {
                    valid += 2;
                }
            }
        }
        
        if (valid == 0)
            printf("0/1\n");
        else {
            long int d = gcd(valid, total);
            printf("%ld/%ld\n", valid/d, total/d);
        }
    }
    return 0;
}

/* extra case, explanation
 1
 6 3
 111101
 6^2 = 36 (x, x)
 
 | 1 - 1 | <= 3   1
 | 1 - 2 | <= 3   3
 | 1 - 3 | <= 3   5
 | 1 - 4 | <= 3   7
 
 | 2 - 2 | <= 3   8
 | 2 - 3 | <= 3   10
 | 2 - 4 | <= 3   12
 
 | 3 - 3 | <= 3   13
 | 3 - 4 | <= 3   15
 | 3 - 6 | <= 3   17
 
 | 4 - 4 | <= 3   18
 | 4 - 6 | <= 3   20
 
 | 6 - 6 | <= 3   21
 21/36
*/
