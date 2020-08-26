/*

        problem-> rotated_sorted_array_search(good).cpp

        Given an array of integers A of size N and an integer B.

array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value B to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return index of B in array A, otherwise return -1
Constraints

1 <= N <= 1000000
1 <= A[i] <= 10^9
all elements in A are disitinct.
For Example

Input 1:
    A = [4, 5, 6, 7, 0, 1, 2, 3]
    B = 4
Output 1:
    0
Explanation 1:
 Target 4 is found at index 0 in A.


Input 2:
    A = [5, 17, 100, 3]
    B = 6
Output 2:
    -1


                */

int BS(int l,int r,const vector<int> &a,int k)
{
    while(l<=r)
    {

        int mid=l+(r-l)/2;
        if(a[mid]==k)
        {
            return mid;

        }
        else if(a[mid]>k)
        r=mid-1;
        else
        l=mid+1;

    }

    return -1;
}


int Solution::search(const vector<int> &a, int k) {

    int n=a.size();
    int l=0,r=n-1;
    // first find the index of minm element so that we can apply then binary search to
    // both the side
    int minind=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(l==r)
        {
            minind=0;
            break;
        }
        else if(mid<r && a[mid]>a[mid+1])
        {
            minind= mid;
            break;
        }
        else if(mid>l && a[mid-1]>a[mid])
        {
            minind=mid-1;
            break;
        }
        else if(a[mid]>a[0])
        l=mid+1;
        else
        r=mid-1;
    }

        if(minind==-1)
        {
            int g=BS(0,n-1,a,k);
            return g;
        }

     if(a[minind]==k)
    return minind;
    int g=BS(minind+1,n-1,a,k);
    if(g!=-1)
   return g;

   g=BS(0,minind-1,a,k);
   if(g!=-1)
   return g;

   return -1;





}
