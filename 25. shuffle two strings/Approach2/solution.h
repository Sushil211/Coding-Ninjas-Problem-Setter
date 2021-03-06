/*
    Time Complexity: O(N * M). 
    Space Complexity: O(N * M).

    Where N is the length of the string a and M is the length of string b.
*/

#include<vector>
#include<string>

bool isInterleaveUtil(string a, string b, string c, int n1, int n2, int n3, vector<vector<int>> &dp){

    // If all the strings become empty, then return true.
    if(n1==0 && n2==0 && n3==0) {
        return true;
    }

	// If the length of "c" is not equal to the sum of the length of "a" and "b", then return false.
    if(n1 + n2 != n3) {
        return false;
    }

    if(dp[n1][n2] != -1) {
        return dp[n1][n2];
    }
  
    if(n1 > 0 && n2 > 0 && n3 > 0 && a[n1-1] == c[n3-1] && b[n2-1] == c[n3-1]){
        return dp[n1][n2] = (isInterleaveUtil(a, b, c, n1-1, n2, n3-1, dp) || isInterleaveUtil(a, b, c, n1, n2-1, n3-1, dp));
    }

    else if(n1 > 0 && n3 > 0 && a[n1-1] == c[n3-1]){
        return dp[n1][n2] = isInterleaveUtil(a, b, c, n1-1, n2, n3-1, dp);
    }

    else if(n2 > 0 && n3 > 0 && b[n2-1] == c[n3-1]){
        return dp[n1][n2] = isInterleaveUtil(a, b, c, n1, n2-1, n3-1, dp);
    }

    // If the last character of "c" matches neither with the last character of "a" nor with the last character of "b", then we simply return false.
    else{
    	return dp[n1][n2] = false;
    }
}

bool isInterleave(string a, string b, string c){

	int n1 = a.length(), n2 = b.length(), n3 = c.length();

	// Create a dp array of size (n1+1)*(n2+1) and initialise it to -1.
	vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1));

	// Call the util function passing each string along with their lengths as arguments.
    return isInterleaveUtil(a, b, c, n1, n2, n3, dp);
}