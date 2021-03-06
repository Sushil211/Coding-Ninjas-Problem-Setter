/*
    Time Complexity - O(N + M)
    Space Complexity - O(N + M)

    Where N and M denote the number of snipers and the number of elements in the "defense" array respectively.
*/

#include<vector>
#include<queue>

bool isCyclePresent(int n, vector<int> graph[]) {

	int indegree[n];
	for(int i = 0; i < n; i++){
		indegree[i] = 0;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < graph[i].size(); j++){
			indegree[graph[i][j]]++;
		}
	}

	queue<int> q;

	// Push all the nodes to the queue that have a 0 indegree.
	for(int i = 0; i < n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	int count = 0;
	while(!q.empty()) {
		int curr = q.front();
		q.pop();

		count++;

		for(int i = 0; i < graph[curr].size(); i++){
			indegree[graph[curr][i]]--;

			// If indegree of the neighbor becomes 0, then push it to the queue.
			if(indegree[graph[curr][i]] == 0){
                q.push(graph[curr][i]);
            }
		}
	}

	// If count == n, then we return false as there is no cycle present in the graph. Return true otherwise.
	return count != n;
}

bool canWin(int n, int m, vector<vector<int>> &edges){

	// Create a graph of n nodes.
	vector<int> graph[n];

	// Draw directed edges from each sniper who is defending to the one who is being defended.
	for(int i = 0; i < edges.size(); i++){
		graph[edges[i][0]].push_back(edges[i][1]);
	}

	// If cycle is present, then return false. Otherwise return true.
	return !isCyclePresent(n, graph);
}