/*
    problem-> compare_version(good).cpp


If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4



                    */


int find_next_num(string A, int i, string &num){

    while(i < A.length() && A[i] == '0') i++;

    //Find the number till the next dot
    while(i < A.length() && A[i] != '.'){
      num += A[i];
      i++;
    }

    //If the entire number consisted of zeroes, the string would be empty.
    if(num.empty()) num = "0";

    return i;
}

int compare_strings(string A, string B){
    if(A == B) return 0;
    int i = 0, j = 0;
    while(i < A.length() && j < B.length()){
        string num_a, num_b;
        //Find numbers till the next dot (or the last number)
        i = find_next_num(A, i, num_a);
        j = find_next_num(B, j, num_b);

        //compare the first and the second number
        if(num_a.length() > num_b.length()) return 1;
        if(num_b.length() > num_a.length()) return -1;
        if(num_a > num_b) return 1;
        if(num_a < num_b) return -1;

        //As the two numbers are equal, proceed to the next number after dot
        i++;
        j++;
    }
    //Check if any part of A is remaining and if it is greater than zero
    while(i < A.length()){
        if(A[i] != '0' && A[i] != '.') return 1;
        i++;
    }
    //Check if any part of B is remaining and if it is greater than zero
    while(j < B.length()){
        if(B[j] != '0' && B[j] != '.') return -1;
        j++;
    }
    //Both the strings are equivalent so return 0
    return 0;
}

int Solution::compareVersion(string A, string B) {
    return compare_strings(A, B);
}
