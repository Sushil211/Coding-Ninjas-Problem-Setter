/*
    Time Complexity: O(N). 
    Space Complexity: O(1).

    Where N is the length of the string s.
*/

#include<string>
#include<algorithm>

int powerOf(string s){
	
	int n = s.length();

	//Create a frequency array of size 26 and initialize all the elements to 0.
	int frequency[26] = {0};

	for(int i=0;i<n;i++){

		char c = s[i];

		//If "c" is a lowercase character then increase frequency[c-'a'] by 1.
		if(c >= 97 && c <= 122){
			frequency[c - 'a']++;
		}

		//If "c" is an uppercase character then increase frequency[c-'A'] by 1.
		else if(c >= 65 && c <= 90){
			frequency[c - 'A']++;
		}
	}

	//Sort the frequency array in the decreasing order of the frequency of the characters.
	sort(frequency, frequency+26, greater<int>());

	//Create an ans variable to store the maximum power of the string "s" and initialize it to 0.
	int ans = 0;

	//Create a power variable and initialize it to 26.
	int power = 26;

	for(int i=0;i<26;i++){

		//If the frequency of the current character is 0, then break the loop.
		if(frequency[i] == 0){
			break;
		}

		//Else, multiply the frequency with power and add it to the ans. Decrease power by 1.
		else{
			ans = ans + frequency[i] * power;
			power--;
		}
	}

	//Finally, return the ans variable.
	return ans;
}