/*

    prolbem-> shortest_unique_prefix(good).cpp

    LINK-> https://www.interviewbit.com/problems/shortest-unique-prefix/

    Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov




            */


// FASTEST SOLUTION IS TO USE TRIE DATA STRUCTURE, YOU CAN ALSO USE MAP TO SOLVE THIS, THAT WILL ALSO GET ACCEPTED AT INTERVIEWBIT PLATFORM.


struct Trie
{
    int cnt;
    Trie* children[26];
    Trie()
    {
        cnt=0;
        for(int i=0;i<26;i++)
        children[i]=NULL;
    }


};

void insert(Trie *root,string s)
{
    Trie *p=root;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int ind=s[i]-'a';
        if(!p->children[ind])
        {
            p->children[ind]=new Trie();
        }

        p=p->children[ind];
        p->cnt++;

    }
}

int find(Trie *root,string s)
{
    int n=s.length();
    Trie *p=root;
    for(int i=0;i<n;i++)
    {
        int ind=s[i]-'a';
        if(p->children[ind]->cnt==1)
        return i;
        p=p->children[ind];
    }

    return 0;
}
vector<string> Solution::prefix(vector<string> &a) {

     Trie *root=new Trie();

     for(int i=0;i<a.size();i++)
     {
         insert(root,a[i]);
     }

     vector<string > ans;
     for(int i=0;i<a.size();i++)
     {
         int j=find(root,a[i]);
         ans.push_back(a[i].substr(0,j+1));
     }

     return ans;

}
