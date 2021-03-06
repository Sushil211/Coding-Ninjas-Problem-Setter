/*
    Time Complexity - O(log N)
    Space Complexity - O(1)

    Where N is the given number.
*/

int findMSB(int n){
    
    int ans = 1;

    while(n != 1){
        n = n / 2;
        ans = ans * 2;
    }

    return ans;
}