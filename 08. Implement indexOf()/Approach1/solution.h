/*
    Time Complexity: O(N*M). 
    Space Complexity: O(1).

    Where M and N are the lengths of string a and b respectively.
*/

#include<vector>
#include<string>

int findIndexOf(string a, string b){

    int n = b.length();
    int m = a.length();

    //If the length of b is less than the length of a, then we simply return -1.
    if(n < m){
        return -1;
    }
    
    int i,j;

    for(i=0;i<=n-m;i++)
    {

        //For each index of i, we check for the next m characters.
        for(j=0;j<m;j++)
        {

            //If (i+j)th index of b, doesn't match with jth index of a, then we break the inner loop.
            if(b[i+j] != a[j]){
                break;
            }
        }

        //If j is equal to m, that means all the characters of a matches. So we return the value of i as the answer.
        if(j==m){
            return i;
        }
    }
      
    //If we reach at the end of the outer loop, then it means a is not present in b, so we return -1. 
    return -1;
}