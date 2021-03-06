/*
    Time Complexity: O(N + M). 
    Space Complexity: O(M).
    
    Where M and N are the lengths of string a and b respectively.
*/

#include<vector>
#include<string>

vector<int> kmpPreProcess(string a, int m){

    int i = 1, j = 0;

    //Create lps array of size m, which stores the longest prefix suffix for each index.
    vector<int> lps(m,0);

    while(i < m) {

        //If the ith index of a matches with the jth index of a, then store the value j+1 at lps[i] and increment both i and j.
        if(a[i] == a[j]) {
            lps[i] = j+1;
            i++; j++;
        } 

        //If the ith index of a doesnâ€™t match with the jth index of a and j > 0, then j redirects to lps[j-1].
        else if (j > 0) {
            j = lps[j-1];
        }

        //If none of the above condition matches then make lps[i] as 0 and increment i.
        else {
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

int findIndexOf(string a, string b){
    int n = b.length();
    int m = a.length();

    //If the length of b is less than the length of a, then we simply return -1.
    if(n < m){
        return -1;
    }

    //Calculate the lps array.
    vector<int> lps = kmpPreProcess(a, m);
    int i = 0, j = 0;

    while(i < n && j < m) {

        //If the ith character of b matches with the jth character of a, then increment both i and j.
        if(b[i] == a[j]) {
            i++;
            j++;
        } 

        //If the above characters do not match and j > 0, then j redirects to lps[j-1]. 
        else if(j > 0) {
            j = lps[j - 1];
        } 

        //If none of the above mentioned condition matches, then increment i.
        else {
            i++;
        }
    }

    //If j is equal to m, then return i - j as it is the index of the first occurrence of a in b, else reutrn -1.
    return j == m ? i - j : -1;
}