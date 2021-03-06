/*
    Time Complexity: O((N^2)^K). 
    Space Complexity: O(N*K).

    Where N and K denotes the number of subjects and number of friends respectively.
*/


#include<algorithm>

//Calculate the sum of the array from left index to right index.
long long int sum(int subjects[], int left, int right) 
{ 
    long long int sum = 0; 

    for (int i = left; i <= right; i++){
    	sum += subjects[i];
    }  

    return sum; 
} 

long long int minimumRequiredTime(int subjects[], int n, int k){
	
	//If the value of k is 1, then we simply return the sum of the array "subjects".
	if (k == 1) {
        return sum(subjects, 0, n - 1);     
	}

	//If the value of n is 1, then we return subjects[0].
    if (n == 1) {
    	return subjects[0];
    }  
  
  	//Initialize ans variable to 10^18 (Any value which is greater than the sum of the array).
    long long int ans = 1e18; 
  
  	//Do the recursive steps for each i from 1 to n.
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max(minimumRequiredTime(subjects, i, k - 1), sum(subjects, i, n - 1))); 
    }
  
    return ans; 
}