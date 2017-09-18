#include<iostream>

using namespace std;

int commonPrefix(string left , string right)
{
    int len = min(left.length() , right.length());
    int i;
    for(i = 0 ; i < len ; i++)
    {
       if(left[i] != right[i])
         return i;
    }
    return i;
}
string findLongestPrefix(string arr[] , int low , int high)
{
    if(low == high)
       return arr[low];
    int mid = (low + high) / 2;
    string left = findLongestPrefix(arr , low , mid);
    string right = findLongestPrefix(arr , mid + 1 , high);
    return left.substr(0 , commonPrefix(left , right));
}
int main()
{
    string arr[] = {"geeksforgeeks" , "geeks" , "geekpqr" , "geeker", "gertyu"};
    int n = sizeof(arr) / sizeof(string);
    cout<<findLongestPrefix(arr , 0, n-1);
    return 0;
}
