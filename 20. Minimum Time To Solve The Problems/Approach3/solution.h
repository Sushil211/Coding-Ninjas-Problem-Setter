/*
    Time Complexity: O(K*N^2). 
    Space Complexity: O(K*N).

    Where N and K denotes the number of subjects and number of friends respectively.
*/

#include<algorithm>
#include<vector>

long long int minimumRequiredTime(int subjects[], int n, int k){

	//prefixSum array is being used to store the prefix sum of the array "subjects".
	long long int prefixSum[n];

	//Make the first element of the prefixSum array equal to the first element of "subjects".
	prefixSum[0] = subjects[0];

	//Run a loop from i = 1 to n and make prefixSum[i] = prefixSum[i-1] + subjects[i].
	for(int i=1;i<n;i++){
		prefixSum[i] = prefixSum[i-1] + subjects[i];
	}

	//Create a dp array of size (k+1)*(n+1) and initialise it to -1.
	vector<vector<long long int>> dp(k + 1, vector<long long int> (n + 1, -1));
	
	//If the value of k is 1, then we simply return the sum of the array "subjects".
	if (k == 1) {
        return prefixSum[n-1];     
	}

	//If the value of n is 1, then we return subjects[0].
    if (n == 1) {
    	return subjects[0];
    }  
  
  	//Run a loop from 1 to n and store the sum of 0 to i-1 th element of "subjects" in dp[1][i].
  	for (int i = 1; i <= n; i++) {
        dp[1][i] = prefixSum[i-1]; 
  	}
  
    //Run a loop from 1 to k and store the value of subjects[0] in dp[i][1].
    for (int i = 1; i <= k; i++) {
        dp[i][1] = subjects[0]; 
    }
  
    // 2 to k partitions 
    for (int i = 2; i <= k; i++) {

    	// Run the inner loop from 2 to n
        for (int j = 2; j <= n; j++) { 
  
            long long int ans = 1e18; 
  
            //If the maximum of the prefix sum from xth to j-1 th index and dp[i-1][x] is less than dp[i][j], then update dp[i][j] to this value.
            for (int x = 1; x <= j; x++) {
            	ans = min(ans, max(dp[i - 1][x], prefixSum[j-1] - prefixSum[x-1]));
            }       

            //Update the value of dp[i][j].
            dp[i][j] = ans; 
        } 
    } 
   
    return dp[k][n];
}