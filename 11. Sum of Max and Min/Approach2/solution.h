/*
    Time Complexity: O(N). 
    Space Complexity: O(log N).

    Where N is the size of the array "arr".
*/

#include <utility>
#include <algorithm>

pair<int, int> findMaxMin(int arr[], int left, int right){

	//Base case.
	if(left == right){
		return {arr[left], arr[right]};
	}

	//If only two elements are present in the array "arr", then compare arr[left] with arr[right] directly. 
	else if(right == left+1){

		//If arr[left] > arr[right], then return {arr[left], arr[right]}
		if(arr[left] > arr[right]){
			return {arr[left], arr[right]};
		}

		//Else, return {arr[right], arr[left]}.
		else{
			return {arr[right], arr[left]};
		}
	}

	int mid = (left + right) / 2;

	//Call the function recursively in the left helf and right half of the array.
	pair<int, int> leftAns = findMaxMin(arr, left, mid);
	pair<int, int> rightAns = findMaxMin(arr, mid+1, right);

	//Finally, return the maximum among the maximum of leftAns and rightAns and minimum among the minimum of leftAns and rightAns.
	return {max(leftAns.first, rightAns.first), min(leftAns.second, rightAns.second)};
}

int sumOfMaxMin(int arr[], int n){
	
	//Create a pair of integers maxMin. The first integer stores the maximum and the second integer stores the minimum element.
	pair<int, int> maxMin;

	//Call the recursive function to get the result.
	maxMin = findMaxMin(arr, 0, n-1);

	//Return the sum of maximum and minimum.
	return maxMin.first + maxMin.second;
}