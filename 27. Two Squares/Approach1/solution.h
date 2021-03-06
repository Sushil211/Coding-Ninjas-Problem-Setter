/*
    Time Complexity - O(1)
    Space Complexity - O(1)

*/

vector<double> findLine(vector<vector<int>> &s1, vector<vector<int>> &s2){
	
	double s1x, s1y, s2x, s2y;

	s1x = ((s1[0][0] + s1[1][0] + s1[2][0] + s1[3][0]) / (double)4);
	s1y = ((s1[0][1] + s1[1][1] + s1[2][1] + s1[3][1]) / (double)4);
	s2x = ((s2[0][0] + s2[1][0] + s2[2][0] + s2[3][0]) / (double)4);
	s2y = ((s2[0][1] + s2[1][1] + s2[2][1] + s2[3][1]) / (double)4);

	vector<double> res(2);

	// Both the squares have the same center.
	if(s1x == s2x && s1y == s2y) {
		res[0] = (double) -1;
		res[1] = (double) -1;
		return res;
	}

	// If the line is parallel to the Y-axis.
	if(s1x == s2x && s1y != s2y) {
		res[0] = (double) 0;
		res[1] = (double) 0;
		return res;
	}

	double slope, intercept;

	slope = (s2y - s1y) / (s2x - s1x);
	intercept = slope * (-s1x) + s1y;

	res[0] = slope;
	res[1] = intercept;

	return res;
}