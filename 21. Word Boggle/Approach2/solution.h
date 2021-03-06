/*
    Time Complexity: O(N*M * (8 ^ (N*M))). 
    Space Complexity: O(N * M).
    
    Where N and M are the number of rows and columns in the matrix “mat” respectively.
*/

#include<set>
#include<vector>
#include<string>
#include<algorithm>

class Trie{

public:

	//26 children as there are 26 alphabets.
    Trie* children[26];

    //This variable is used to check whether the current node is a leaf or not.
    bool isLeaf;

    Trie() {
    	this->isLeaf = false;
        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }
    }
    
    void insert(string word){

        Trie* curr = this;
        for(char c: word){

        	//If the current node doesn't have a child of character c, then create this node and make this node as curr.
            if(curr->children[c-'a'] == NULL) {
            	curr->children[c - 'a'] = new Trie();
            }
            curr = curr->children[c-'a'];
        }

        curr->isLeaf = true;
    }
};

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

void possibleWordsUtil(Trie *root, vector<vector<char>> mat, vector<vector<bool>> visited, int i, int j, int n, int m, string curr, set<string> &st){

	//If the current root is a leaf of the trie, then add the curr string to the res array. 
	if(root->isLeaf == true){
		st.insert(curr);
	}

	//Mark visited[i][j] as true.
	visited[i][j] = true;

	//Move in all 8 possible directions in the matrix mat recursively.
	for(int index=0;index<8;index++){

		int x = i + dx[index];
		int y = j + dy[index];

		//Check for the validity of this new cell.
		if(x < n && x >= 0 && y < m && y >= 0 && visited[x][y] == false){

			int c = mat[x][y] - 'a';

			//If the character is present as the child of the root, then call recursively.
			if(root->children[c]){
				possibleWordsUtil(root->children[c], mat, visited, x, y, n, m, curr+mat[x][y], st);
			}
		}
	}

	//Finally, mark visited[i][j] as false.
	visited[i][j] = false;
}

vector<string> findPossibleWords(vector<string> arr, vector<vector<char>> mat){

    Trie *root = new Trie();
	//Trie trie;

	//Insert all the words in the array arr in to the trie.
    for(string str: arr){
        root->insert(str);
    }
	
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
			
			//If the current character exists as a children of the root in the trie, then do the following task.
			if(root->children[mat[i][j] - 'a']){
				curr.push_back(mat[i][j]);
				possibleWordsUtil(root->children[mat[i][j] - 'a'], mat, visited, i, j, n, m, curr, st);
				curr = "";
			}
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