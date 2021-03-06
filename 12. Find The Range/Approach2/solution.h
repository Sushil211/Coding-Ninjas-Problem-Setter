/*
    Time Complexity: O(log N). 
    Space Complexity: O(1).

    Where N is the size of the array "arr".
*/

int findStartPosition(int arr[], int n, int key){

	//Create an index variable and initialize it to -1.
	int index = -1;

	//Take two pointers left and right with left pointing to 0 and right pointing to N-1 initially.
	int left = 0, right = n-1;

	while(left <= right){

		//Create a mid variable and mid = (left + right) / 2
		int mid = (left + right) / 2;

		//If arr[mid] >= key, then right points to mid - 1.
		if(arr[mid] >= key){
			right = mid - 1;
		}

		//Else, left points to mid + 1.
		else{
			left = mid + 1;
		}

		//If arr[mid] == key, then index = mid.
		if(arr[mid] == key){
			index = mid;
		}
	}

	//Finally, return the index.
	return index;
}

int findLastPosition(int arr[], int n, int key){

	//Create an index variable and initialize it to -1.
	int index = -1;

	//Take two pointers left and right with left pointing to 0 and right pointing to N-1 initially.
	int left = 0, right = n-1;

	while(left <= right){

		//Create a mid variable and mid = (left + right) / 2
		int mid = (left + right) / 2;

		//If arr[mid] <= key, then left points to mid + 1.
		if(arr[mid] <= key){
			left = mid + 1;
		}

		//Else, right points to mid - 1.
		else{
			right = mid - 1;
		}

		//If arr[mid] == key, then index = mid.
		if(arr[mid] == key){
			index = mid;
		}
	}

	//Finally, return the index.
	return index;
}


vector<int> findTheRange(int arr[], int n, int key){

	//Create an array "res" of size 2 and initialize its elements to -1.
	vector<int> res(2, -1);

	//Store the first position in res[0].
	res[0] = findStartPosition(arr, n, key);

	//If res[0] == -1, then return res;
	if(res[0] == -1){
		return res;
	}

	//Store the last position in res[1].
	res[1] = findLastPosition(arr, n, key);

	return res;
}