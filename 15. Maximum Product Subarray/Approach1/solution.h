/*
    Time Complexity - O(N^3)
    Space Complexity - O(1)

    Where N is size of the array "arr".
*/

#include<algorithm>

int maximumProduct(vector<int> &arr){
	
	int ans = INT_MIN;
	int n = arr.size();

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){

			int currentProduct = 1;
			for(int k = i; k <= j; k++){
				currentProduct = currentProduct * arr[k];
				ans = max(ans, currentProduct);
			}
		}
	}

	return ans;
}