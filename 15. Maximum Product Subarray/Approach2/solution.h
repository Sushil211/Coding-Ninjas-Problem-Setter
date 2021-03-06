/*
    Time Complexity - O(N^2)
    Space Complexity - O(1)

    Where N is size of the array "arr".
*/

#include<algorithm>

int maximumProduct(vector<int> &arr){
	
	int ans = INT_MIN;
	int n = arr.size();

	for(int i = 0; i < n; i++){
		int currentProduct = arr[i];
		ans = max(ans, currentProduct);

		// Find all possible subarrays starting from this current index. 
		for(int j = i + 1; j < n; j++){
			currentProduct = currentProduct * arr[j];
			ans = max(ans, currentProduct);
		}
	}

	return ans;
}