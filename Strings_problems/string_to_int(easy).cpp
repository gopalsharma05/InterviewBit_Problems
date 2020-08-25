/*

    problem->string_to_int(easy).cpp


    There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using �See Expected Output�.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise.




                */




int Solution::atoi(const string s) {

    bool flag=false;
    int n=s.length();

    int k=0;
    for( k=0;k<s.length();k++)
    {
        if(s[k]!=' ')
        break;
    }
    int i=k;
    string ans="";
    while(i<n)
    {
        if(s[i]>57 || s[i]<48 && flag==false && s[i]!='-'&& s[i]!='+')
        {
            return 0;
        }

        else if(isdigit(s[i]))
        {
          while(i<n &&isdigit(s[i]))
          {
              ans+=s[i];
              i++;
          }
          break;
        }
        i++;



    }


        // cout<<ans<<" is the stirng ";

    n=ans.length();
    long long int  end=ans[n-1]-48,ten=10,p=end;
     for(int i=n-2;i>=0;i--)
     {
         p=((ans[i]-48)*ten)+end;
         end=p;
         ten*=10;
     }
     if(s[0]=='-')
     p=-p;

    if(ans.length()>10)
    {
        if(s[0]=='-')
        return INT_MIN;
        else
        return INT_MAX;
    }

     if(p>INT_MAX && s[0]!='-')
     return INT_MAX;
    else if(p>INT_MAX)
     return INT_MIN;
     else
     return p;

}
