/*
    Time Complexity: O(K*N^2). 
    Space Complexity: O(K*N).

    Where N and K denotes the number of subjects and number of friends respectively.
*/

#include<algorithm>
#include<vector>

long long int minimumRequiredTimeUtil(int subjects[], int n, int k, vector<vector<long long int>> dp, long long int prefixSum[]){

	//If the value of k is 1, then we simply return the sum of the array "subjects".
	if (k == 1) {
        return prefixSum[n-1];     
	}

	//If the value of n is 1, then we simply return subjects[0].
    if (n == 1) {
    	return subjects[0];
    }  

    //If dp[k][n] contains a value other than -1, then simply return that value.
    if(dp[k][n] != -1){
    	return dp[k][n];
    }
  
  	//Initialize ans variable to 10^18 (Any value which is greater than the sum of the array).
    long long int ans = 1e18; 
  
  	//Do the recursive case for each i from 1 to n.
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max(minimumRequiredTimeUtil(subjects, i, k - 1, dp, prefixSum), prefixSum[n-1] - prefixSum[i-1])); 
    }
  
    return dp[k][n] = ans;
}

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
	
	return minimumRequiredTimeUtil(subjects, n, k, dp, prefixSum);
}