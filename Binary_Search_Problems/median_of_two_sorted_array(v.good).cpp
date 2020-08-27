/*
    problem>=median_of_two_sorted_array(v.good).cpp

    There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be     O(log (M+N)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.


            */




            // can be easily done in O(n+m) ... but try to do in O(log(min(n,m))) using binary search


double Solution::findMedianSortedArrays(const vector<int> &a, const vector<int> &b) {



  There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.  int n=a.size(),m=b.size();
    if(n>m)
    return findMedianSortedArrays(b,a);







    int pos=(n+m+1)/2;
    int l=0,r=min(n,m);

    while(l<=r)
    {
        int xpos=l+(r-l)/2;
        int ypos=pos-xpos;
        int leftx,rightx,lefty,righty;
        leftx=xpos==0 ? INT_MIN:a[xpos-1];
        rightx=xpos==n ? INT_MAX:a[xpos];
        lefty=ypos==0 ? INT_MIN:b[ypos-1];
        righty=ypos==m ? INT_MAX:b[ypos];



        if(leftx<=righty && lefty<=rightx)
        {

            if((m+n)%2==0)
            {
                return (double)((max(leftx,lefty)+min(rightx,righty))*0.5);
            }
            else
           {

                return (double)max(leftx,lefty);

           }

        }
            else if(leftx>righty)
            {
                r=xpos-1;
            }
            else
            l=xpos+1;

    }

    return 0.0;




}
