/*
    Time Complexity - O(N + M)
    Space Complexity - O(N)

    Where N and M denote the number of nodes and the number of edges in the graph respectively.
*/

#include<vector>
#include<climits>
#include<algorithm>

int dfs(int src, int &minWeight, vector<int> &start, vector<int> &weights){

	if(start[src] == 0){
		return src;
	}

	minWeight = min(minWeight, weights[src]);
	return dfs(start[src], minWeight, start, weights);
}

vector<vector<int>> components(int n, int m, vector<vector<int>> &edges){
	
	vector<int> start(n+1, 0), end(n+1, 0), weights(n+1, 0);

	for(int i = 0; i < m; i++){
		int src = edges[i][0];
		int dest = edges[i][1];
		int weight = edges[i][2];

		start[src] = dest;
		weights[src] = weight;
		end[dest] = src;
	}

	vector<vector<int>> res;

	for(int i = 1; i <= n; i++){

		if(end[i] == 0 && start[i] != 0){
			int minWeight = INT_MAX;
			int last = dfs(i, minWeight, start, weights);

			vector<int> temp(3);
			temp[0] = i;
			temp[1] = last;
			temp[2] = minWeight;

			res.push_back(temp);
		}
	}

	return res;
}