/*
    Time Complexity:O(N). 
    Space Complexity:O(1).
    
    Where N is the length of the input string.
*/

bool isPalindrome(string s)
{

    if (s == "")
    {
        return false;
    }

    int i, n = s.length();

    for (i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }

    return true;
}

int countNumberOfPalindromeWords(string s)
{

    int i, n = s.length();
    string temp = "";
    int ans = 0;

    for (i = 0; i < n; i++)
    {

        //Check whether the current character is empty or not
        if (s[i] != ' ')
        {

            //If it is a uppercase character, then make it lowercase
            if (s[i] <= 90)
            {
                s[i] += 32;
            }

            //Add the current character to the temp string
            temp.push_back(s[i]);
        }

        else
        {

            //Ignore the empty strings
            if (temp == "")
            {
                continue;
            }

            //If it is a palindome, increase the answer by 1
            if (isPalindrome(temp))
            {
                ans++;
            }

            //Make the temp string empty again
            temp = "";
        }
    }

    //Check for the last word
    if (isPalindrome(temp))
    {
        ans++;
    }
    return ans;
}