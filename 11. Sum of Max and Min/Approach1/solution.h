/*
    Time Complexity: O(N). 
    Space Complexity: O(1).

    Where N is the size of the array "arr".
*/


int sumOfMaxMin(int arr[], int n){
	
	int maximum, minimum;

	//If n == 1, then make maximum = minimum = arr[0]. Return maximum + minimum.
	if(n == 1){
		maximum = minimum = arr[0];
		return maximum + minimum;
	}

	//Else, store the maximum among arr[0] and arr[1] in the maximum and minimum among them in the minimum. 
	if(arr[0] > arr[1]){
		maximum = arr[0];
		minimum = arr[1];
	}

	else{
		maximum = arr[1];
		minimum = arr[0];
	}

	for(int i=2;i<n;i++){

		//If arr[i] > maximum, then make maximum = arr[i].
		if(arr[i] > maximum){
			maximum = arr[i];
		}

		//Else If arr[i] < minimum, then make minimum = arr[i].
		else if(arr[i] < minimum){
			minimum = arr[i];
		}
	}

	return maximum + minimum;
}