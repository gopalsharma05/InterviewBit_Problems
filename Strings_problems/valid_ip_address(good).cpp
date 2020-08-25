/*

    problem->valid_ip_address(good).cpp


    Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given �25525511135�,

return [�255.255.11.135�, �255.255.111.35�]. (Make sure the returned strings are sorted in order)




                    */




bool isvalid(string s)
{
    int n=s.length();
    if(n>1 && s[0]=='0')
    return false;

    if(n>=1 &&stoi(s)<=255)
    return true;

    return false;
}

vector<string> Solution::restoreIpAddresses(string s) {

    int n=s.length();
     vector<string> ans;
    if(n<4||n>12)
    return ans;



   for(int i=1;i<=3;i++)
   {
       string first=s.substr(0,i);
       if(isvalid(first))
       {
           for(int j=1;i+j<n&&j<=3;j++)
           {
               string second=s.substr(i,j);
               if(isvalid(second))
               {
                   for(int  k=1;i+j+k<n&&k<=3;k++)
                   {
                       string third=s.substr(i+j,k);
                       string fourth=s.substr(i+j+k);
                       if(isvalid(third)&& isvalid(fourth))
                       {
                           ans.push_back(first+'.'+second+'.'+third+'.'+fourth);
                       }

                   }
               }
           }
       }
   }

   return ans;



}
