/*
    problem-> kth_permutation_sequence(good).cpp


    The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

 Good questions to ask the interviewer :
What if n is greater than 10. How should multiple digit numbers be represented in string?
 In this case, just concatenate the number to the answer.
so if n = 11, k = 1, ans = "1234567891011"
Whats the maximum value of n and k?
 In this case, k will be a positive integer thats less than INT_MAX.
n is reasonable enough to make sure the answer does not bloat up a lot.




                        */



int findind(int n,int &k)
{
    if(n==1)
    return 0;
    n--;
    int fact=n;
    while(k>=fact&&n>1)
    {
        fact*=(n-1);
        n--;
    }
    int ind=k/fact;
    k=k-(k/fact)*fact;
    return ind;

}

string Solution::getPermutation(int n, int k) {

  vector<string> v;
  for(int i=1;i<=n;i++)
  {
      v.push_back(to_string(i));
  }
  k--;
  string s="";
  vector<string> :: iterator itr;
  itr=v.begin();
  for(int i=0;i<n;i++)
  {

      int ind=findind(n-i,k);
      s+=v[ind];

      advance(itr,ind);
      v.erase(itr);
      itr=v.begin();

  }

  return s;



}
