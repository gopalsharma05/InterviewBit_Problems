/*
    problem-> subset(good).cpp

        Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]


            */



vector<vector<int> > Solution::subsets(vector<int> &a) {

    int n=a.size();
    vector<vector<int> > ans;
    vector<int> v;

    for(int i=0;i<pow(2,n);i++)
    {
         v.clear();
        for(int j=0;j<n;j++)
        {
            if(i&1<<j)
            {
                v.push_back(a[j]);
            }
        }
        sort(v.begin(),v.end());
        ans.push_back(v);
    }

    sort(ans.begin(),ans.end());

    return ans;


}
