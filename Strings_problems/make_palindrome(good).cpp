/*

        problem-> make_palindrome(good).cpp

    Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.



Input Format

The only argument given is string A.
Output Format

Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".



                */






int Solution::solve(string s) {


   int n=s.length();
   int l=0,r=n-1,ans=0,end1=n-1;
   while(l<=r)
   {
        while(s[l]!=s[r])r--;
        l++;
        r--;
        if(s[l]!=s[r])l=0;

   }

   if(r<0)
   return n-1;
   else
   return n-(l+r+1);



}
