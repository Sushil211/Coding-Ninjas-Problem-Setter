/*
    Time Complexity - O(N * log max(N, maxDeadline))
    Space Complexity - O(maxDeadline)

    Where N is size of the array "jobs" and maxDeadline is the maximum among all the deadlines.
*/

#include<algorithm>
#include<set>

// Custom Comparator function to sort the jobs in the decreasing order of their profit.
bool compare(vector<int> &job1, vector<int> &job2){
    return job1[1] > job2[1];
}

int jobScheduling(vector<vector<int>> &jobs){
	
	sort(jobs.begin(), jobs.end(), compare);

	int maxProfit = 0;
	int maxDeadline = 0;

	// Find the maximum deadline among all the jobs.
	for(int i = 0; i < jobs.size(); i++){
		maxDeadline = max(maxDeadline, jobs[i][0]);
	}

	// Create a set "slots".
	set<int, greater<int>> slots;

	// Insert all the elements from maxDeadline to 1 into the set.
	for(int i = maxDeadline; i > 0; i--){
        slots.insert(i);
    }


	for(int i = 0; i < jobs.size(); i++){

		// If the set is empty or the deadline is less than the last element of the set, then ignore this job.
		if(slots.size() == 0 || jobs[i][0] < *slots.rbegin()){
			continue;
		}

		int availableSlot = *slots.lower_bound(jobs[i][0]);
		maxProfit = maxProfit + jobs[i][1];
		slots.erase(availableSlot);
	}

	return maxProfit;
}