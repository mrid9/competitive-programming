#include <stdio.h>

/* Project Euler #4: Largest palindrome product
Constraints
1 ≤ T < 100
101101 < N < 1000000
Sample Input
2
101110
800000
Sample Output
101101
793397
*/

#define N 10000

void merge(int a[], int begin, int end, int mid) {
    
    int b[N], c[N];
    int i, j, k, m, index;
    
    for (i = 0; begin + i <= mid; i++)
        b[i] = a[begin + i];
    
    for (j = 0; mid + 1 + j <= end; j++)
        c[j] = a[mid + 1 + j];
    
    k = 0, m = 0, index = begin;
    while (k < i && m < j) {
        if (b[k] < c[m])
            a[index++] = b[k++];
        else
            a[index++] = c[m++];
    }
    while (k < i)
        a[index++] = b[k++];
    while (m < j)
        a[index++] = c[m++];
}

void merge_sort(int a[], int begin, int end) {
    
    int mid = (end + begin) / 2;
    
    if (end - begin > 0) {
        merge_sort(a, begin, mid);
        merge_sort(a, mid + 1, end);
        merge(a, begin, end, mid);
    }
    return;
}

int is_palindrome(int n) {
    
    int reminder, reverse = 0, number = n;
    
    while (n > 0) {
        reminder = n % 10;
        reverse = reverse * 10 + reminder;
        n = n / 10;
    }
    return (reverse == number);
}

int generate_plindromes(int *palindromes) {
    
    int total = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (is_palindrome(i * j)) {
                palindromes[total++] = i * j;
            }
        }
    }
    return total;
}

int main() {
    
    int i, test_cases, n, total, palindromes[N];
    
    total = generate_plindromes(palindromes);
    merge_sort(palindromes, 0, total - 1);
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &n);
        
        for (i = total - 1; i >= 0; i--) {
            if (n > palindromes[i]) {
                break;
            }
        }
        printf("%d\n", palindromes[i]);
    }
    return 0;
}

