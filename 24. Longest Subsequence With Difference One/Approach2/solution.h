/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the size of the array "nums".
*/

#include <vector>
#include <algorithm>
#include <unordered_map>

int longestSubsequence(vector<int> &nums){
	
	int n = nums.size();
	unordered_map<int, int> map;

	for(int i = 0; i < n; i++) {
		map[nums[i]] = max(map[nums[i] - 1], map[nums[i] + 1]) + 1;
	}

	int maximum = 0;

	for(int i = 0; i < n; i++) {
		maximum = max(maximum, map[nums[i]]);
	}

	return maximum;
}