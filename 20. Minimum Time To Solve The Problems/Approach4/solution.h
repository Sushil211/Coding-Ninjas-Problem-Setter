/*
    Time Complexity: O(N * log(Sum of the Array A)). 
    Space Complexity: O(1).

    Where N and K denotes the number of subjects and number of friends respectively.
*/

//Function to check whether it is possible to do k partitions such that maximum time <= mid.
bool checker(int k, int subjects[], int n, long long int mid){

    long long int temp = mid;
    int i = 0, count = 1;

    while(i<n){

    	//If at any point count exceeds k, then simply return false. As it is not possible to do k partitions.
        if(count > k){
        	return false;
        }

        //If i th value of array "subjects" is greater than temp, then increment count by 1 and make temp equal to mid again.
        if(subjects[i] > temp){
            count++;
            temp = mid;
        }

        //Else, decrement temp by i th value of "subjects" and increment i by 1.
        else{
            temp = temp - subjects[i];
            i++;
        }
    }

    //Finally if we get out of the loop, then return true.
    return true;
}

long long int minimumRequiredTime(int subjects[], int n, int k){
	
	long long int sum=0;
    
    //Calculate the sum of the array "subjects".
    for(int i=0;i<n;i++) {
    	sum = sum + subjects[i];
    }

    //If the value of k is 1, then we simply return the sum of the array "subjects".
    if(k == 1){
    	return sum;
    }
    
    //If the value of n is 1, then we simply return subjects[0].
    if(n == 1){
    	return subjects[0];
    }
    
    //Take two variables left and right. Initialize them to 0 and sum initially.
    long long int left = 0, right = sum;

    //The ans variable is being used to store the desired answer.
    long long int ans = sum;

    while(left <= right){

        long long int mid = left + (right - left) / 2;

        //If it is possible to do k partitions, then update the ans as mid and meke right point to mid-1.
        if(checker(k, subjects, n, mid)){
            right = mid - 1;
            ans = mid;
        }

        //If it is not possible to do k partitions, then make left point to mid + 1.
        else{
            left = mid + 1;
        }

    }

    return ans;
}