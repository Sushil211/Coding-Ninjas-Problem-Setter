/*
    Time Complexity - O(N ^ 2)
    Space Complexity - O(N)

    Where N is the size of the array "nums".
*/

#include <vector>
#include <algorithm>

int longestSubsequence(vector<int> &nums){
	
	int n = nums.size();
	int dp[n];

	// Initialize all the elements of the dp array to 1.
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
	}

	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {

			if(abs(nums[j] - nums[i]) == 1) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}

	int maximum = 0;

	for(int i = 0; i < n; i++) {
		maximum = max(maximum, dp[i]);
	}

	return maximum;
}