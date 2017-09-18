#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s1, s2;
	    cin>>s1>>s2;
	    int n = s1.size(); int m = s2.size();
	    if(s1.compare(s2) == 0)
	    {
	      cout<<"0"<<endl; continue;
	    }
	    int p = min(n , m);
	    for(int i  = 0; i < p ; i++)
	    {
	        char ch1 = s1[i] ; char ch2 = s2[i];
	        if(ch1 != 'n' && ch2 != 'n')
	        {
	           if(ch1 == ch2)
	               continue;
	           else
	              {ch1 > ch2 ? cout<<"1"<<endl : cout<<"-1"<<endl ; break;}
	        }
	        else if(ch1 == 'n' && ch2 != 'n' && i+1 < n)
	        {
	            char nextChar = s1[i+1];
	            if(nextChar == 'g')
	              {'n' > ch2 ? cout<<"1"<<endl : cout<<"0"<<endl; break;}
	            else
	             {ch1 > ch2 ? cout<<"1" <<endl : cout<<"0" << endl; break;}

	        }
	        else if(ch2 == 'n' && ch1 != 'n' && i + 1 < n)
	        {
	            char nextChar = s2[i+1];
	            if(nextChar == 'g')
	            {
	                ch1 > 'n' ? cout<<"1"<<endl : cout<<"0"<<endl; break;
	            }
	            else
	            {
	                ch1 > ch2 ? cout<<"1" <<endl : cout<<"0" << endl; break;
	            }
	        }
	        else if(i+1 < n)
	        {
	            char nextChar1 = s1[i+1];
	            char nextChar2 = s2[i + 1];
	            if(nextChar1 != 'g' && nextChar2 != 'g')
	              continue;
	            if(nextChar1 == nextChar2)
	              continue;
	            else if(nextChar1 == 'g')
	            {  'n' > nextChar2 ? cout<<"1"<<endl : cout<<"-1"<<endl; break;}
	            else if(nextChar2 == 'g')
	            { nextChar1 > 'n' ? cout<<"1" << endl : cout<<"-1"<<endl; break; }

	        }
	        else
	        {
	            ch1 < ch2 ? cout<<"1"<<endl : cout<<"-1"<<endl; break;
	        }
	    }

	}
	return 0;
}
