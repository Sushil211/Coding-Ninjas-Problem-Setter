/*
    Time Complexity - O(log N)
    Space Complexity - O(1)

    Where N is the given number.
*/

#include<cmath>

int findMSB(int n){
    
    int x = (int) log2(n);
    return int(pow(2, x));
}