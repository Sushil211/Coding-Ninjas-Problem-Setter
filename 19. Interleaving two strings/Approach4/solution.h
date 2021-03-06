/*
    Time Complexity: O(N*M). 
    Space Complexity: O(min(M, N)).
    
    Where N is the length of the string a and M is the length of string b.
*/

#include<vector>
#include<string>

bool isInterleave(string a, string b, string c){

	//We want to reduce the space complexity to O(min(N,M)). 
	//We swap the two strings if b.length() > a.length(), so that we can make a dp array of size b.length()+1.
	if(a.length() < b.length()){
		swap(a,b);
	}

	int n1 = a.length(), n2 = b.length(), n3 = c.length();

	//Create a dp array of size n2 and initialise it to false.
	vector<bool> dp(n2 + 1, false);

	//If the length of "c" is not equal to the sum of the length of "a" and "b", then return false.
    if(n1 + n2 != n3) {
        return false;
    }

    int i,j;

    for(i=0;i<=n1;i++){
    	for(j=0;j<=n2;j++){

    		//Mark dp[j] as true, if the values of i and j are both zeroes.
    		if(i==0 && j==0){
    			dp[j] = true;
    		}

    		//If the value of i is zero and j is non zero and the (j-1)th character of "b" matches with (j-1)th character of "c", then assign dp[j] as dp[j-1].
    		else if(i == 0){
    			dp[j] = dp[j-1] && (b[j-1] == c[j-1]);
    		}

    		//If the value of j is zero and i is non zero and the (i-1)th character of "a" matches with (i-1)th character of "c", then dp[j] remains unchanged.
    		else if(j == 0){
    			dp[j] = dp[j] && (a[i-1] == c[i-1]);
    		}

    		//Check for both the cases.
    		else{
    			dp[j] = (dp[j] && a[i-1] == c[i+j-1]) || (dp[j-1] && b[j-1] == c[i+j-1]);
    		}
    	}
    }

    return dp[n2];
}