/*
    Time Complexity: O(N). 
    Space Complexity: O(1).

    Where N is the size of the array "arr".
*/


vector<int> findTheRange(int arr[], int n, int key){

	//Create an array "res" of size 2 and initialize its elements to -1.
	vector<int> res(2, -1);

	for(int i=0;i<n;i++){

		//If arr[i] > key, then break the loop.
		if(arr[i] > key){
			break;
		}

		else if(arr[i] == key){

			//If arr[i] == key and res[0] == -1, then res[0] = i.
			if(res[0] == -1){
				res[0] = i;
			}

			//Make res[1] = i.
			res[1] = i;
		}
	}

	return res;
}