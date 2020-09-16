/*
    problem-> Combinations(good).cpp

    Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]



                */





void backtrack(int n,int k,vector<vector<int> > &ans,vector<int> v,int i)
{


    if(k==0)
    {
        ans.push_back(v);
        return ;
    }

    if(i>n)
    return ;




        v.push_back(i);
        backtrack(n,k-1,ans,v,i+1);
        v.pop_back();
        backtrack(n,k,ans,v,i+1);



}

vector<vector<int> > Solution::combine(int A, int k) {


    vector<vector<int> > ans;
    if(k==0 || k>A)
    return ans;
    vector<int> v;
    backtrack(A,k,ans,v,1);

    return ans;

}
