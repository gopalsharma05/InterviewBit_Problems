/*
    problem-> insertion_and_deletion_in_TRIE(good).cpp

    Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use the TRIE data structure and search the given string A. If found print 1 else 0.

Expected Time Complexity: O(N * WORD_LEN + A_LEN).
Expected Auxiliary Space: O(N * WORD_LEN).

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of a integer N, denoting the number of element in a Trie to be stored.
Second line of each test case consists of N space separated strings denoting the elements to be stored in the trie.
Third line of each test case consists of a String A to be searched in the stored elements.

Output:
Print the respective output in the respective line.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
1
8
the a there answer any by bye their
the
Output:
1



                */






#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    bool isEnd;
    Trie *children[26];
    Trie()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
        children[i]=NULL;
    }
};

void insert(Trie *root,string s)
{
    Trie *p=root;
    for(int i=0;i<s.length();i++)
    {
        int ind=s[i]-'a';
        if(!p->children[ind])
        {
            p->children[ind]=new Trie();
        }

        p=p->children[ind];
    }

    p->isEnd=true;
}

bool search_string(Trie *root,string s)
{
    Trie *p=root;
    for(int i=0;i<s.length();i++)
    {
        int ind=s[i]-'a';
        if(!p->children[ind])
        {
            return false;
        }

        p=p->children[ind];


    }

    return (p!=NULL && p->isEnd);
}

int main() {
	//code
	int t;
	cin>>t;

	while(t--)
	{
	    int n;
	    cin>>n;

	  string a[n];
	  Trie *root=new Trie();
	  for(int i=0;i<n;i++)
	  {
	      cin>>a[i];
	      insert(root,a[i]);
	  }



	    string to_search;
	    cin>>to_search;

	    cout<< search_string(root,to_search)<<"\n";


	}

	return 0;
}
