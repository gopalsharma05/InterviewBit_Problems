/*

    problem-> subset-2(contain_duplicates).cpp

        Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]


                */







void backtrack(vector<int> a,int i,set<vector<int> > &ans,vector<int> v)
{

    ans.insert(v);
    for(int j=i;j<a.size();j++)
    {
        v.push_back(a[j]);
        backtrack(a,j+1,ans,v);
        v.pop_back();


    }


}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &a) {

    sort(a.begin(),a.end());

    set<vector<int> > ans;
    vector<int> v;

    backtrack(a,0,ans,v);

    vector<vector<int> > ans1(ans.begin(),ans.end());
    return ans1;


}
