#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/* partial credit, 5 test cases out of 6 */

/* String Function Calculation
 Constraints
 1 ?|T|? 10^5
 Sample Input #00
 aaaaaa
 Sample Output #00
 12
 Sample Input #01
 abcabcddd
 Sample Output #01
 9
 */

long occurrences(string s, string sub) {
    
    long total = 0, i;
    while ((i = s.find(sub, i)) != string::npos) {
        total++;
        i += 1;
    }
    return total;
}

int main() {
    
    string s, sub;
    int l, i, length;
    long value, max, total;
    
    cin >> s;
    length = (int) s.length();
    
    max = 0;
    for (l = length; l >= 1; l--) {
        
        if (max >= (length - l + 1) * l)
            continue;
        
        for (i = 0; i < length - l + 1; i++) {
            cout << s.substr(i, l) << endl;
            total = occurrences(s, s.substr(i, l));
            value = total * l;
            
            if (value > max) {
                max = value;
            }
            
            if (max > (length - i + 1) * i)
                break;
        }
    }
    cout << max << endl;
    
    return 0;
}
