/*
    Time Complexity - O(N + M)
    Space Complexity - O(N + M)

    Where N and M denote the number of snipers and the number of elements in the "defense" array respectively.
*/

#include<vector>
#include<queue>

vector<int> minTime(int n, int m, vector<vector<int>> &edges){

	// Create a graph of n nodes.
	vector<int> graph[n];

	// Draw directed edges from each sniper who is defending to the one who is being defended.
	for(int i = 0; i < edges.size(); i++){
		graph[edges[i][0]].push_back(edges[i][1]);
	}

	int indegree[n];
	for(int i = 0; i < n; i++){
		indegree[i] = 0;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < graph[i].size(); j++){
			indegree[graph[i][j]]++;
		}
	}

	vector<int> ans(n);
	queue<int> q;

	// Push all the nodes to the queue that have a 0 indegree and make ans[i] = 1.
	for(int i = 0; i < n; i++){

		if(indegree[i] == 0){
			ans[i] = 1;
			q.push(i);
		}
	}

	while(!q.empty()) {
		int curr = q.front();
		q.pop();

		for(int i = 0; i < graph[curr].size(); i++){
			indegree[graph[curr][i]]--;

			if(indegree[graph[curr][i]] == 0){
				ans[graph[curr][i]] = ans[curr] + 1;
                q.push(graph[curr][i]);
            }
		}
	}

	return ans;
}