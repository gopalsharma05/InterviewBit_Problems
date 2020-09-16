.*

    problem-> grey_code(good).cpp

    The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.


                */




vector<int> Solution::grayCode(int n) {

    vector<int> v;
    v.push_back(0);
    for(int i=0;i<n;i++)
    {

        int sz=v.size()-1;
        for(int j=sz;j>=0;j--)
        {
            v.push_back(v[j]+(1<<i));
        }


    }

    return v;

 }
