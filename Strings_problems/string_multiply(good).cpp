/*

    problem-> string_multiply(good).cpp



    Given two numbers as stings s1 and s2 your task is to multiply them.

Example 1:

Input:
s1 = 33
s2 = 2
Output: 66
Example 2:

Input:
s1 = 11
s2 = 23
Output: 253
Your Task:

You are required to complete the function multiplyStrings() which takes two strings s1 and s2 as its only argument and returns their product as strings.

Constraints:
1 <= length of s1 and s2 <= 103

Expected time complexity: O( n1 * n2 )
Expected auxiliary space: O( n1 + n2 ) ; where n1 and n2 are sizes of strings s1 and s2 respectively.


                */

string multiplyStrings(string a, string b) {

    int al=a.length(),bl=b.length();
    if(a=="0" || b=="0")
    return "0";

    int sign=1;
    if(a[0]=='-' && b[0]=='-')
    {
        sign=1;
        a=a.substr(1);
        b=b.substr(1);
        al--;
        bl--;

    }
    else if(a[0]=='-')
    {
        sign=-1;
        a=a.substr(1);
        al--;
    }
    else if(b[0]=='-')
    {
        sign=-1;
        b=b.substr(1);
        bl--;
    }

    int ans[al+bl]={0},i,j,carry=0;
    for(i=al-1;i>=0;i--)
    {
        for( j=bl-1;j>=0;j--)
        {
            int r=ans[i+j+1]+(a[i]-48)*(b[j]-48)+carry;
            carry=r/10;
            ans[i+j+1]=r%10;
            // cout<<r<<" "<<ans[i+j+1]<<" "<<i+j+1<<"\n";

        }

        ans[i+j+1]+=carry;
        carry=0;
    }

   string str="";
   if(sign==-1)
   str+='-';
   int cnt=0;
    for(int i=0;i<al+bl;i++)
    if(ans[i]==0 && cnt==0)
    continue;
    else
    {
        cnt=1;
        str+=ans[i]+'0';
    }

    return str;

   //Your code here
}
