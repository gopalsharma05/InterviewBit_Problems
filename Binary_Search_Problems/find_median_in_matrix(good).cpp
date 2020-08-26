/*

    problem-> find_median_in_matrix(good).cpp

    Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.



Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.
Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2



                */




    // APPROACH -> USING_BINARY_SEARCH(good).cpp


int Solution::findMedian(vector<vector<int> > &a) {

    vector<int> v;
    int n=a.size(),m=a[0].size();

    int minm=INT_MAX;
    for(int i=0;i<n;i++)
    {
        minm=min(minm,a[i][0]);
    }
    int maxm=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxm=max(a[i][m-1],maxm);
    }

    int l=minm,r=maxm;
    int kth=(m*n)/2;
    kth++;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
        }

        if(cnt<kth)
        l=mid+1;
        else
        r=mid;
    }


    return l;


}
