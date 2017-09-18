#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>

using namespace std;

bool valid(int hashTable[] , int limit)
{
    if(hashTable['A'] <= limit && hashTable['C'] <= limit && hashTable['T'] <= limit && hashTable['G'] <= limit)
        return true;
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    //cin>>N;
    string s;
    //cin>>s;
    ifstream inf;
    inf.open("BearAndSteadyGene.txt");
    inf >> N;

    string line;
    getline(inf, s);
    getline(inf,s);
    cout<<N<<endl<<s;

    int limit = N / 4;
    int hashTable[91];
    hashTable['A'] = 0 ; hashTable['C'] = 0 ; hashTable['T'] = 0 ; hashTable['G'] = 0;
    int rightIndex = 0;
    for(int i = N - 1 ; i >= 0 ;i--)
    {
        hashTable[s[i]]++;
        if(!valid(hashTable , limit))
        {
            hashTable[s[i]]--;
            break;
        }
        rightIndex = i;
    }
    rightIndex--;
    if(rightIndex == 0)
    {
        if(hashTable['A'] == limit && hashTable['C'] == limit && hashTable['G'] == limit && hashTable['T'] == limit)
        {
            cout<<"0";
            return 0;
        }
    }
    int leftIndex = 0;
    for(int i = 0 ; i < N && leftIndex < rightIndex;i++)
    {

        hashTable[s[i]]++;
        if(!valid(hashTable , limit))
        {
            hashTable[s[i]]--;
            break;
        }
        leftIndex = i;
    }
    //if((leftIndex + 1) == rightIndex)
    leftIndex++;
    int dist = rightIndex - leftIndex + 1;
    while(rightIndex < N-1)
    {
        rightIndex++;
        hashTable[s[rightIndex]]--;
        while(leftIndex <= rightIndex )
        {
            hashTable[s[leftIndex]]++;
            if(!valid(hashTable , limit))
            {
              hashTable[s[leftIndex]]--;
                break;
            }
            leftIndex++;
        }

        int d = rightIndex - leftIndex + 1;
        if(dist > d)
            dist = d;
    }
    //cout<<rightIndex<<"  ";
    //cout<<leftIndex<<"  ";
    cout<<dist;

    return 0;
}
