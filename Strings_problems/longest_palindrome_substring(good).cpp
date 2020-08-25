/*

    problem-> longest_palindrome_substring(good).cpp

    Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"



                    */

string Solution::longestPalindrome(string s) {

    int n=s.length(),len=1,start=0;
    for(int i=1;i<n;i++)
    {
        // for odd length substring
        int l=i-1,r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {
             if(len<r-l+1)
             {
                 start=l;
                 len=r-l+1;
             }
             l--;
             r++;

        }

        // for even length substring

        l=i-1,r=i;
         while(l>=0 && r<n && s[l]==s[r])
        {
             if(len<r-l+1)
             {
                 start=l;
                 len=r-l+1;
             }
             l--;
             r++;

        }

    }

    return s.substr(start,len);

}
