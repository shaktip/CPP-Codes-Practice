#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>


using namespace std;
struct BinTree
{
   char letter;
   int freq;
   BinTree *left,*right;
};
struct Data
{
   char letter;
   int freq;
   struct BinTree *addr;
};
class Huffman
{
    vector<Data> Input;
    BinTree *root;
    public:
       void print()
       {
           cout<<"\n________Print Call____________\n";
           for(int i = 0 ; i < Input.size(); i++)
             cout<<"\n\t " << Input[i].letter <<","<< Input[i].freq;
           cout<<"\n______________________________\n";
       }
       void heapify(int i, int n)
       {
           Data obj = Input[i];
           Data objLeft, objRight;
           int left = 2 * i + 1;
           int right = 2 * i + 2;
           Data minObj = obj;
           int index = i;
           if(left < n)
           {
              objLeft = Input[left];
              if(objLeft.freq < minObj.freq)
              {
                 minObj = objLeft;
                 index = left;
              }
           }
           if(right < n)
           {
              objRight = Input[right];
              if(objRight.freq < minObj.freq)
              {
                  minObj = objRight;
                  index = right;
              }
           }
           if(i != index)
           {
             swap(Input[i], Input[index] );
             heapify(index, n);
           }
       }
       void CreateMinHeap()
       {
            int n = Input.size();
            for(int i = n/2 ; i >= 0 ; i--)
                 heapify(i, n);

            print();

       }
       void readInput()
       {
          int n;
          struct Data obj;
          cout<<"\n\t How many letters:"; cin>>n;
          for(int i = 0 ; i < n ; i++)
          {
             cout<<"\n\t Enter the letter : "; cin>>obj.letter;
             cout<<"\n\t Enter its frequency : "; cin>>obj.freq;
             BinTree *node = new BinTree();
             node->letter = obj.letter;
             node->freq = obj.freq;
             node->left = node->right = NULL;
             obj.addr = node;
             Input.push_back(obj);
          }
          if(n > 1)
          {
            CreateMinHeap();
            CreateHuffmanTree();
          }
          else
            cout<<"\n\t Number of letters should be more than 2";
       }
       Data getMinFromHeap()
       {
           Data obj = Input[0];
           swap(Input[0],Input[Input.size() - 1]);
           Input.pop_back();
           heapify(0, Input.size());
           print();
           return obj;

       }
       void printBinaryTree(BinTree *root)
       {
          if(root)
          {
              printBinaryTree(root->left);
              cout<<" -->  "<<root->letter<<" , "<<root->freq;
              printBinaryTree(root->right);
          }
       }
       void CreateHuffmanTree()
       {
          BinTree *node;
          while(Input.size() > 0)
          {
           Data firstMin = getMinFromHeap();
           cout<<"\n\t " << firstMin.letter<<" , "<<firstMin.freq;
           Data secondMin = getMinFromHeap();
           cout<<"\n\t " << secondMin.letter <<" , "<<secondMin.freq;
           node = new BinTree();
           node->freq = firstMin.freq + secondMin.freq;
           node->letter = '@';

             node->left = firstMin.addr;
             node->right = secondMin.addr;

           //cout<<"\n\r Root freq = "<<node->freq <<" Left Freq " << node->left->freq << " Right Freq " << node->right->freq;
           Data newNode ;
           newNode.freq = node->freq;
           newNode.letter = node->letter;
           newNode.addr = node;
           if(Input.size() > 0)
           {
             Input.push_back(newNode);
             CreateMinHeap();
           }
          }
          root = node;
          cout<<"\n\tBinary Tree is :";
          printBinaryTree(root);
          string s;
          s = "";
          printHuffmanCode(root, s);
       }
       void printHuffmanCode(BinTree *root, string s)
       {
          if(root)
          {
              printHuffmanCode(root->left, s + "0");
              if(root->letter != '@')
                cout<<"\n\t "<<root->letter <<"  :  "<<s;
              printHuffmanCode(root->right, s + "1");
          }
       }
};
int main()
{
  Huffman obj;
  obj.readInput();

  return 0;
}
