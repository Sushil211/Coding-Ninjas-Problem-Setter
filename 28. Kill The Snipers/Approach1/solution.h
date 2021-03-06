/*
    Time Complexity - O(N + M)
    Space Complexity - O(N + M)

    Where N and M denote the number of snipers and the number of elements in the "defense" array respectively.
*/

#include<vector>

bool isCyclePresentUtil(vector<int> graph[], int src, vector<bool> &visited, vector<bool> &stack){

	visited[src] = stack[src] = true;

	for(int i = 0; i < graph[src].size(); i++){

		// Already in the recursion stack.
		if(stack[graph[src][i]] == true){
			return true;
		}

		if(visited[graph[src][i]] == false){
			bool checkFuture = isCyclePresentUtil(graph, graph[src][i], visited, stack);
			if(checkFuture == true){
				return true;
			}
		}
	}

	// Remove the src from the recursion stack.
	stack[src] = false;

	return false;
}

bool isCyclePresent(int n, vector<int> graph[]) {

	vector<bool> visited(n);
	vector<bool> stack(n);

	for(int i = 0; i < n; i++){
		visited[i] = stack[i] = false;
	}

	for(int i = 0; i < n; i++){

		if(visited[i] == false){

			// If this node is not visited yet, we can start the DFS from this node to check for the presence of cycle.
			if(isCyclePresentUtil(graph, i, visited, stack) == true){
				return true;
			}
		}
	}

	// No cycle is present.
	return false;
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