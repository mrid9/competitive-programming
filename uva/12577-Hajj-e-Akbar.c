#include <stdio.h>
#include <string.h>

/* 12577 - Hajj-e-Akbar
 Sample Input
 Hajj
 Umrah
 Hajj
 Umrah
 *
 Sample Output
 Case 1: Hajj-e-Akbar
 Case 2: Hajj-e-Asghar
 Case 3: Hajj-e-Akbar
 Case 4: Hajj-e-Asghar
 */
int main() {
    
    char word[10];
    char choice1[15] = "Hajj-e-Akbar";
    char choice2[15] = "Hajj-e-Asghar";
    int counter = 0;
    
    while (scanf("%s", word) == 1) {
    
        counter++;
        
        if (word[0] == '*')
            break;
        
        if (!strcmp (word, "Hajj"))
            printf("Case %d: %s\n", counter, choice1);
        else
            printf("Case %d: %s\n", counter, choice2);
    }
    return 0;
}