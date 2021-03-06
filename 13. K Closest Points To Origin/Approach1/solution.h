/*
    Time Complexity: O(N log N). 
    Space Complexity: O(1).

    Where N denotes size of the points array.
*/

#include<algorithm>

//Custom comparator function to sort the array according to their distances from the origin.
bool compare(vector<int> &point1, vector<int> &point2){
	return (point1[0] * point1[0] + point1[1] * point1[1]) <= (point2[0] * point2[0] + point2[1] * point2[1]);
}

vector<vector<int>> KClosestPoints(vector<vector<int>> &points, int k){

	//Sort the points in the increasing order of their distances from the origin.
	sort(points.begin(), points.end(), compare);

	//Cerate an empty "res" array to store the k closest points.
	vector<vector<int>> res;

	//Add first k points to the "res" array.
	for(int i=0;i<k;i++){
		res.push_back(points[i]);
	}

	return res;
};
