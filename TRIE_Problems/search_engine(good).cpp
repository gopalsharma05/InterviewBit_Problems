/*

    problem-> search_engine(good).cpp



    Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine
    automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.

Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes
the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.

INPUT

First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines
contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.

OUTPUT

Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.

CONSTRAINTS

1 ≤ n, weight, len(s), len(t) ≤ 106
1 ≤ q ≤ 105
total length of all strings in database entries ≤ 106
total length of all query strings ≤ 106

SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10





                        */




// FASTEST SOLUTION IS TO USE TRIE DATA STRUCTURE, YOU CAN ALSO USE MAP TO SOLVE THIS, THAT WILL ALSO GET ACCEPTED. In map maintain the max_len. same as that
// we maintian in TRIE using len variable for each node



#include<bits/stdc++.h>
using namespace std;


struct Trie
{
	int len;
	Trie* children[26];
	Trie()
	{
		len=0;
		for(int i=0;i<26;i++)
		children[i]=NULL;
	}
};


void insert(Trie *root,string s,int a)
{
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		int ind=s[i]-'a';
		if(!root->children[ind])
		{
			root->children[ind]=new Trie();
		}
		root=root->children[ind];
		root->len=max(a,root->len);
	}
}

int find(Trie *root,string s)
{
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		int ind=s[i]-'a';
		if(!root->children[ind])
		{
			return -1;
		}
		root=root->children[ind];

	}

	return root->len;

}
int main()
{
	int n,q;
	cin>>n>>q;
	Trie *root=new Trie();
	for(int i=0;i<n;i++)
	{
		string s;
		int a;
		cin>>s>>a;

		insert(root,s,a);


	}

	for(int i=0;i<q;i++)
	{
		string s;
		cin>>s;

		cout<<find(root,s)<<"\n";
	}
}
