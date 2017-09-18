#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<string.h>


using namespace std;

struct point
{
   int x, y;
   int flag;
   point(int a, int b)
   {
      x = a ; y = b; flag = 0;
   }
};
int compare(point a, point b)
{
    //point *f = (point *)a;
    //point *s = (point *)b;
    point first = a;
    point second = b;
    if(first.x != second.x)
      return first.x < second.x;
    if(first.flag == 3 && second.flag == 3)
        return first.y > second.y;

    if(first.flag == 1 && second.flag == 3)
       return true;
    if(first.flag == 3 && second.flag == 1)
        return false;
    if(first.flag == 3 && second.flag == 2)
         return true;
    else
          return false;

}
void print(vector<point> v)
{
    cout<<"\n\t Vector is :";
    for(int i = 0 ; i < v.size() ; i++)
    {
       cout<<v[i].x << " , "<<v[i].y<<" , "<< v[i].flag<<endl;
    }
}

void insert(point p1, point p2 , vector<point> &v)
{
    if(p1.x != p2.x)
    {
        point left = p1.x < p2.x ? p1 : p2;
        point right = p1.x > p2.x ? p1 : p2;
        left.flag = 1; right.flag = 2;
        v.push_back(left); v.push_back(right);
    }
    else
    {
       point up = p1.y > p2.y ? p1 : p2;
       point down = p1.y < p2.y ? p1 : p2;
       up.flag = down.flag = 3;
       v.push_back(up);
       v.push_back(down);
    }
}

int * constructBIT(vector<point> v , int &maxy)
{

    for(int i = 0 ; i < v.size()  ; i++)
       if(v[i].y > maxy)
          maxy = v[i].y;
    int *BIT = new int[maxy + 1];
    for(int i = 0 ; i <= maxy ; i++)
       BIT[i] = 0;
    return BIT;
}

void update(int *BIT, int n , int index , int val)
{
    while(index < n)
    {
        BIT[index] += val;
        index += index & (-index);
    }
}
int getSum(int *BIT , int n  , int index)
{
   int sum = 0;
   while(index > 0)
   {
       sum = sum + BIT[index];
       index -= index & (-index);
   }
   return sum;
}
void printBIT(int *BIT , int n)
{
   cout<<"\n\t BIT is   ";
   for(int i = 0 ; i < n ; i++)
   {
     cout<<"   "<<BIT[i];
   }
   cout<<endl;
}
int findIntersections(vector<point> v)
{
     int *BIT;
     int sz = INT_MIN;
     int intersections = 0;
     BIT = constructBIT(v , sz);
     sz = sz + 1;
     for(int i = 0 ; i < v.size() ; i++)
     {
         if(v[i].flag == 1)
            update(BIT , sz ,  v[i].y , 1);
         else if(v[i].flag == 2)
             update(BIT , sz , v[i].y , -1);
         else if(v[i].flag == 3)
         {
             int up_y = v[i].y;
             int down_y = v[++i].y;
             int sum = getSum(BIT , sz , up_y) - getSum(BIT , sz , down_y);
             cout<<"\n\t Sum between "<<up_y<<" "<<down_y<<" is = "<<sum<<endl;
             intersections += sum;
         }
         printBIT(BIT , sz);
     }
     return intersections;
}

int findTriangles(vector<point> v)
{
     int intersections = findIntersections(v);
     cout<<"\n\t No of intersections = "<<intersections;
     if(intersections <= 2)
       return 0;
     return (intersections * (intersections - 1) * (intersections - 2))  / 6;

}

int main()
{
  vector<point> v;
  insert(point(2,1) , point(2,9) , v);
  insert(point(1 , 7) , point(6 ,7) , v);
  insert(point(5,2) , point(5 , 8) , v);
  insert(point(3 , 4 ) , point( 6 , 4) , v);
  insert(point(4 , 3 ) , point(4 , 5) , v);
  insert(point(7 , 6 ) , point(9 , 6) , v);
  insert(point(8 , 2) , point(8 , 5) , v);
  int n = v.size();
  print(v);
  sort(v.begin() , v.end() ,  compare);
  print(v);
  cout<<"\n\t No of triangles = "<<findTriangles(v);
  return 0;
}
