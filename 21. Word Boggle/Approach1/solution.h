/*
    Time Complexity: O(N*M * (8 ^ (N*M))). 
    Space Complexity: O(N * M).

	Where N and M are the number of rows and columns in the matrix “mat” respectively.
*/

#include<set>
#include<vector>
#include<string>
#include<algorithm>

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

void possibleWordsUtil(vector<vector<char>> mat, vector<string> arr, vector<vector<bool>> &visited, int i, int j, int n, int m, string curr, set<string> &st){

	//Mark visited[i][j] as true.
	visited[i][j] = true;

	curr.push_back(mat[i][j]);

	//If the curr string matches with any of the word from the array arr, then add this to st.
	for(int k=0;k<arr.size();k++){
		if(arr[k] == curr){
			st.insert(curr);
			break;
		}
	}

	//Move in all 8 possible directions in the matrix mat recursively.
	for(int index=0;index<8;index++){

		int x = i + dx[index];
		int y = j + dy[index];

		//Check for the validity of this new cell.
		if(x < n && x >= 0 && y < m && y >= 0 && visited[x][y] == false){
			possibleWordsUtil(mat, arr, visited, x, y, n, m, curr, st);
		}
	}

	//Remove the last character from the string curr and mark visited[i][j] as false.
	curr.pop_back();
	visited[i][j] = false;
}

vector<string> findPossibleWords(vector<string> arr, vector<vector<char>> mat){
	
	int n = mat.size();
	int m = mat[0].size();

	//We use a set, so that we do not store the same word again and again. 
	set<string> st;

	//Create a boolean visited matrix of size n x m and initialize all the cells to false.
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	string curr = "";

	//Run a nested loop with the outer loop running from i = 0 to n and the inner loop running from j = 0 to m.
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			possibleWordsUtil(mat, arr, visited, i, j, n, m, curr, st);
		}
	}

	//This will store the desired result.
	vector<string> res;

	//Add all the words from st to the res array.
	for(string str: st){
		res.push_back(str);
	}
	
	return res;
}