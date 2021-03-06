/*
    Time Complexity - O(N * log3(high - low))
    Space Complexity - O(1)

    Where N is size of the array "points".
*/

#include <cmath>

double findSumOfDistances(vector<int> &line, vector<vector<int>> &points, double x){

	double sum = 0;

	// The Y-Coordinate of the point on the line corresponding to x.
	double y = -(x * line[0] + line[2]) / line[1];

	int n = points.size();

	for(int i = 0; i < n; i++){
		double distance = (x - points[i][0]) * (x - points[i][0]) + (y - points[i][1]) * (y - points[i][1]); 
		sum = sum + sqrt(distance);
	}

	return sum;
}

double optimumDistance(vector<int> &line, vector<vector<int>> &points){
	
	double low = -1e6;
	double high = 1e6;

	// Run the loop until the difference between low and high is negligible.
	while((high - low) > 1e-6){

		double mid1 = low + (high - low) / 3; 
		double mid2 = high - (high - low) / 3;

		double distance1 = findSumOfDistances(line, points, mid1);
		double distance2 = findSumOfDistances(line, points, mid2);

		if(distance1 < distance2){
			high = mid2;
		}
		else{
			low = mid1;
		}
	}

	// The X-Coordinate of the optimum point.
	double x = (low + high) / 2;

	return findSumOfDistances(line, points, x);
}