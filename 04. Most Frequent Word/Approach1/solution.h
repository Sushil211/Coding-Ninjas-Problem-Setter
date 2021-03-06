/*
    Time Complexity: O(N^2 * M). 
    Space Complexity: O(1).
    
    Where N and M are the lengths of the string a and b respectively.
*/

#include<string>

bool isPresent(string temp, string b){

    string wordInB = "";

    //Run a loop to check for each word in the string b.
    for(int j=0;j<b.length();j++){

        //If the current character is not a space character, then add it to the wordInB string.
        if(b[j] != ' '){
            wordInB.push_back(b[j]);
        }

        else{

            //If wordInB is equal to temp, then return true.
            if(wordInB == temp){
                return true;
            }

            //Make wordInB empty again.
            wordInB = "";
        }
    }

    //Check for the last word in string b.
    if(wordInB == temp){
        return true;
    }

    //Finally return false.
    return false;
}

int countFrequencyInRemainingString(string a, string temp, int i){

    string otherWordsInA = "";

    int count = 0;

    //Run a loop in the remaining part of string a.
    for(int k=i+1;k<a.length();k++){

        //If the current character is a white space, then add it to the otherWordsInA string.
        if(a[k] != ' '){
            otherWordsInA.push_back(a[k]);
        }

        else{

            //If otherWordsInA matches with the temp string, then increase the count by 1.
            if(otherWordsInA == temp){
                count++;
            }

            //Make the otherWordsInA string empty again.
            otherWordsInA = "";
        }
    }

    //Check for the last word in string a.
    if(otherWordsInA == temp){
        count++;
    }

    return count;
}

string mostFrequentWord(string a, string b){
    
    //If the string a is empty or both the strings are equal, then we simply return an empty string. 
    if(a == "" || a == b) return "-1";

    //Initialise ans and temp variable to empty string, temp variable will be used to separate words from string a. 
    string ans = "", temp = "";

    //max variable will store the frequency of the ans variable and count variable will store the frequency of temp string. 
    int max = 0, count = 1;
    
    int n = a.length();
    
    for(int i=0;i<n;i++){

        //If the current character is not a space character, then add it to the temp string.
        if(a[i] != ' '){
            temp.push_back(a[i]);
        }

        else{

            //isPresentInB variable is being used to check whether the temp string is present in string b or not.
            bool isPresentInB = isPresent(temp, b);

            //If isPresentInB is false, that means the temp string is not present in the string b.
            //So we count the frequency of the temp string in string a.

            if(isPresentInB == false){

                int frequencyInTheRemaining = countFrequencyInRemainingString(a, temp, i);

                count = count + frequencyInTheRemaining;
                
                //If count exceeds the max variable, then store the value of count in max and the value of temp in ans.
                if(count > max){
                    max = count;
                    ans = temp;
                }

                //Else if count is equal to max, but the temp is lexicographically smaller than ans, then store the value of temp in ans.
                else if(count == max && temp < ans){
                    ans = temp;
                }
            }

            //Finally make temp string empty again and make the count 1.
            temp = "";
            count = 1;
        }
    }
    
    //Do the above process for the last word in the string a as well, i.e. first check for its existence in the string b.
    bool isPresentInB = isPresent(temp, b);

    //If it is not present in the string b, then we don't need to further count its freuqncy in the string a, as it is the last word itself.
    if(isPresentInB == false){

        //Then store the value of temp in ans, if the following two condition holds.
        // 1) The maximum frequency is <= 1.
        // 2) The temp string is lexicographically smaller than ans or the ans string is empty.
        
        if(max <= 1 && (temp < ans || ans == "")){
            ans = temp;
        }
    }

    return ans == "" ? "-1" : ans;
}