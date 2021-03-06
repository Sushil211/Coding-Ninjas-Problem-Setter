/*
    Time Complexity - O(M * N)
    Space Complexity - O(1)

    Where M and N denote the number of rows and the number of columns in the matrix, respectively.
*/

#include <vector>

int leftmostColumn() {

	vector<int> dim = dimensions();
	int m = dim[0];
	int n = dim[1];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){

			int element = get(j, i);
			if(element == 1) {
				return i;
			}
		}
	}
	return -1;
}