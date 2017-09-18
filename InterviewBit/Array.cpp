#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void sortStrings(string s[] , int N)
{

    for(int i = 1 ; i < N ; i++)
    {
      for(int j = 0 ; j < N - 1 ; j++)
      {
        if(s[j].length() == s[j+1].length())
        {
          if(s[j].compare(s[j+1]) < 0)
          {
             string temp = s[j]; s[j] = s[j+1]; s[j+1] = temp;
          }
        }

        else
        {
            string p = s[j];
            string q = s[j+1];
            int len = p.length() < q.length() ? p.length() : q.length();
            int k = 0;
            while(k < len && p[k] == q[k])
                k++;
            if(k == p.length())
            {
               if(q[k] != '0')
               {
                  string temp = s[j]; s[j] = s[j+1]; s[j+1] = temp;
               }
            }
        }

      }
    }
}
string largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string temp;
    int N = A.size();
    string arr[N];
    for(int i = 0 ; i < N ; i++)
    {
        temp = "";
        int no = A[i];
        while(no != 0)
        {
            int rem = no % 10;
            temp = char(rem + 48) + temp;
            no = no / 10;
        }
        arr[i] = temp;
    }
    sortStrings(arr , N);
    for(int i = 0 ; i < N ;i++)
       cout<<arr[i]<<endl;
    string result = "";
    for(int i = 0 ; i < N ;i++)
    {
        result = result + arr[i];
    }
    return result;
}

int main()
{

   vector<int> A ;
   A.push_back(8);
   A.push_back(89);

   string B = largestNumber(A);
   cout<<B;
   return 0;

}
