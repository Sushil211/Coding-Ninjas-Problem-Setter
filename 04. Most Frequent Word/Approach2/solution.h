/*
    Time Complexity: O(N + M). 
    Space Complexity: O(N + M).
    
    Where N and M are the lengths of the string a and b respectively.
*/

#include<string>
#include <unordered_map>
#include <unordered_set>


string mostFrequentWord(string a, string b){
    
    //If the string a is empty or both the strings are equal, then we simply return an empty string. 
    if(a == "" || a == b) return "-1";

    //Initialise ans and temp variable to empty string, temp variable will be used to separate words from string a. 
    string ans = "", temp = "";

    //max variable will store the frequency of the ans variable. 
    int max = 0;

    //Insert all the words of string b, into an unordered_set called banned.
    unordered_set<string> banned;

    for(int i=0;i<b.length();i++){

        //If the current character is not a space character, then add it to the temp string.
        if(b[i] != ' '){
            temp.push_back(b[i]);
        }
        else{

            //Insert the temp string to the banned set.
            banned.insert(temp);

            //Make the temp string empty again.
            temp = "";
        }
    }

    //Take care of the last word in the string b as well.
    banned.insert(temp);

    //Make the temp string empty again.
    temp = "";

    //Store the frequency of each word in string a in an unordered_map called mp. 
    unordered_map<string, int> mp;

    for(int i=0;i<a.length();i++){

        //If the current character is not a space character, then add it to the temp string.
        if(a[i] != ' '){
            temp.push_back(a[i]);
        }
        else{

            //Check whether the temp string is present in the banned set or not.
            if(banned.find(temp) == banned.end()){

                //If it is not present in the banned set, then increse its frequency by 1 in the mp map.
                mp[temp]++;

                //Then store the value of temp in ans, if the following two condition holds.
                // 1) Frequency of the current word exceeds the max frequency.
                // 2) Frequency of the current word is equal to the max frequency and the temp string is lexicographically smaller than ans or the ans.

                if(mp[temp] > max || (mp[temp] == max && temp < ans)){
                    ans = temp;
                    max = mp[temp];
                }
            }

            //Make the temp string empty again.
            temp = "";
        }
    }

    //Follow the same procedure for the last word in the string a as well.
    if(banned.find(temp) == banned.end()){

        //If it is not present in the banned set, then increse its frequency by 1 in the mp map.
        mp[temp]++;

        //Then store the value of temp in ans, if the following two condition holds.
        // 1) Frequency of the current word exceeds the max frequency.
        // 2) Frequency of the current word is equal to the max frequency and the temp string is lexicographically smaller than ans or the ans.

        if(mp[temp] > max || (mp[temp] == max && temp < ans)){
            ans = temp;
            max = mp[temp];
        }
    }

    return ans == "" ? "-1" : ans;
}