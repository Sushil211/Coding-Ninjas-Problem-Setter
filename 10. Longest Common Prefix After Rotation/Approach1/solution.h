/*
    Time Complexity: O(N*(N+M)). 
    Space Complexity: O(1).

    Where M and N are the lengths of string a and b respectively.
*/

#include<string>
#include<algorithm>

int lengthOfTheCommonPrefix(string a, string b){

	int n = b.length();
    int m = a.length();

    //Initialize a count variable to 0, which will store the length of the common prefix of "a" and "b".
    int count = 0;

    //Run a loop from 0 to min(n, m).
    for(int i=0;i<min(n, m); i++){

    	//If a[i] != b[i], then break out of the loop, else increase the count by 1.
    	if(a[i] != b[i]){
    		break;
    	}
    	else{
    		count++;
    	}
    }

    return count;
}

int minimumRequiredShifts(string a, string b){
	
	int n = b.length();
    int m = a.length();

    //The ans variable stores the minimum required shifts. 
    int ans = 0;

    //The max variable stores the length of the longest common prefix encountered so far.
    int max = lengthOfTheCommonPrefix(a, b);

    for(int i=1;i<n;i++){

    	//Perform the left shift on string b.
    	reverse(b.begin(), b.begin());
    	reverse(b.begin()+1, b.end());
    	reverse(b.begin(), b.end());

    	int currentLength = lengthOfTheCommonPrefix(a, b);

    	//If the length of the common prefix exceeds the max length so far, then update max to the currentLength and ans to i.
    	if(currentLength > max){
    		max = currentLength;
    		ans = i;
    	}
    }

    return ans;
}