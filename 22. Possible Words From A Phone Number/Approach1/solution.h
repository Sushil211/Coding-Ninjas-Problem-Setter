/*
    Time Complexity: O((N+M) * (3^N * 4^M)). 
    Space Complexity: O((N+M) * (3^N * 4^M)).

	where N denotes the number of digits in the string "s", that maps to 3 letters such as {2, 3, 4, 5, 6, 8} and M denotes the number of digits in the string "s", that maps to 4 letters such as {7, 9}.
*/

#include<vector>
#include<string>
#include<unordered_map>

void possibleWordsUtil(string &s, vector<string> &res, string &curr, int index, unordered_map<char, string> &mp){

	//If index == s.length, then add curr string to the res array and return.
	if(index == s.size()){
		res.push_back(curr);
		return;
	}

	for(int i=0;i<mp[s[index]].size();i++){

		//Add mp[s[index]][i] to the curr string.
		curr.push_back(mp[s[index]][i]);

		//Call the backtrack function recursively by increasing the index by 1.
		possibleWordsUtil(s, res, curr, index+1, mp);

		//Remove the last element from the curr string.
		curr.pop_back();
	}
}

vector<string> findPossibleWords(string s){
	
	//Create an empty array of strings to store the result
	vector<string> res;

	//Create an unordered_map to store the corresponding letters that map to the digits in T9 Keypad.
	unordered_map<char, string> mp;

	//Store all the corresponding letters.
	mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

	//Create an empty string let’s say curr and an index variable, which is initialized to 0.
	string curr = "";
	int index = 0;

	//Call the backtrack function.
	possibleWordsUtil(s, res, curr, index, mp);

	//Finally, return the res array.
	return res;
}