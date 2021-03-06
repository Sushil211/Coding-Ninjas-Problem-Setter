/*
    Time Complexity - O(M log N)
    Space Complexity - O(1)

    Where M and N denote the number of rows and the number of columns in the matrix, respectively.
*/

#include <vector>
#include <algorithm>

int binarySearch(int row, int n) {

	int left = 0, right = n;

	while(left < right) {

		int mid = left + (right - left) / 2;
		int element = get(row, mid);

		if(element != 1) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	return left;
}

int leftmostColumn() {

	vector<int> dim = dimensions();
	int m = dim[0];
	int n = dim[1];

	int leftmost = n;

	for(int i = 0; i < m; i++) {

		int currColumn = binarySearch(i, n);
		leftmost = min(leftmost, currColumn);
	}

	// If leftmost == n, then no such column exists. So we return -1, else return leftmost.
	return leftmost == n ? -1 : leftmost;
}