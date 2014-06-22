//  494 - Kindergarten Counting Game

#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, const char * argv[])
{
    
    string line;
    int count=0;
    int sum=0;
    
    
    while (getline(cin, line)) {
        sum = 0;
        
        for (int i=0; i<line.length(); i++)
            if (toupper(line[i]) >= 'A' && toupper(line[i]) <= 'Z')
                count = 1;
            else
            {
                sum += count;
                count = 0;
            }
        sum += count;
        cout << sum << "\n";
    }
    
    return 0;
}
