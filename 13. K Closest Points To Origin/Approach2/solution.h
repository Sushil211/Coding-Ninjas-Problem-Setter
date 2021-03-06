/*
    Time Complexity: O(N log K). 
    Space Complexity: O(1).

    Where N denotes size of the points array and K is the number of closest points to be found.
*/

#include<algorithm>
#include<queue>
#include <utility>

vector<vector<int>> KClosestPoints(vector<vector<int>> &points, int k){

	//Cerate an empty "res" array to store the k closest points.
	vector<vector<int>> res;

	//This is a max heap that stores a pair of integers.
	//The first integer represents the distance and the second integer represents the index.
	priority_queue<pair<int, int>> pq;

	for(int i=0;i<points.size();i++){

		//Find distance of each point from the origin.
		int distance = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);

		//Push this point to the heap.
		pq.push({distance, i});

		//If the size of the heap exceeds k, then pop an element from the heap.
		if(pq.size() > k){
			pq.pop();
		}
	}

	for(int i=0;i<k;i++){

		//Find the index of top element of the heap and pop the top element.
		int index = pq.top().second;
		pq.pop();

		//Push the points[index] to the "res" array.
		res.push_back(points[index]);
	}

	return res;
};
