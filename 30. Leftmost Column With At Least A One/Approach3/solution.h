/*
    Time Complexity - O(M + N)
    Space Complexity - O(1)

    Where M and N denote the number of rows and the number of columns in the matrix, respectively.
*/


#include <vector>

int leftmostColumn() {

	vector<int> dim = dimensions();
	int m = dim[0];
	int n = dim[1];

	int leftmost = -1;
	int i = 0, j = n-1;

	while(i < m && j >= 0) {
		
		int element = get(i, j);

		if(element == 1) {
			leftmost = j;
			j--;
		} 
		else {
			i++;
		}
	}

	return leftmost;
}