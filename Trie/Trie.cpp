/* This code is about Trie Data Strucutre and it checks  whether a name is present in an array or not*/
//Sumit Chauhan


#include<bits/stdc++.h>
typedef long long int ld;
using namespace std;

int alpha(char s)  //Calculate the index for string alphabet
{ char p='a';
 int a=p;
 int b=s;
 return (b-a);
 }
 
struct trie
   {
     struct trie* alpha[26];
     
     int leaf;
     
     };
   
  struct trie* createnode()                                   //create the new node
    { struct trie* root;
       root=(struct trie*)malloc(sizeof(trie));
        root->leaf=0;
     for(int i=0;i<26;i++)
       root->alpha[i]=NULL;
       return root;
      }
      
    int insert(struct trie* root,char str[])
      {
        for(ld i=0;i<strlen(str);i++)
        {  int index=alpha(str[i]);
            if(root->alpha[index]==NULL)
              { 
                root->alpha[index]=createnode();
               
                root=root->alpha[index];
                 
                 }
           else
              	 root=root->alpha[index];
              	 
            }
            
            root->leaf=1;
        
            }
       int search(struct trie* root,char str[])                  //search Function;
          { int num=0;
            
            for(ld i=0;i<strlen(str);i++)
              {
               int index=alpha(str[i]);
                
               if(root->alpha[index]!=NULL)
                  { root=root->alpha[index];
                   
                    }
                   else
                   {
                 
                     num=1;                  
                     break;
                     }
                   }
                   if(num==1||root->leaf==0)
                    return 0;
                   else
                    return 1;
                   }
                   
           int main()
           {
              struct trie* root;
              root=createnode();                        // Test Case:-
                                                        //  2 
              char str[100001],s[100001];               //  Sumit
              ld data;                                  //  Chauhan
              cin>>data;                                //  Ritik
              for(ld i=0;i<data;i++)
              {
                cin>>str;
                 insert(root,str);
                }
              
                   cin>>s;
               int  num=search(root,s);
               if(num==1)
                cout<<"Element Found";
                else
                cout<<"Element Not Found";
                return 0;
                }
                      
                   
        
       
        
     
