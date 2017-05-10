/*   The code is about use of Segment Tree and Lazy Propagation*/
//The code is developed by Sumit Chauhan


#include<bits/stdc++.h>
typedef long long int ld;
using namespace std;

const int size1=100001;

const int size2=400001;

ld tree[size1];

ld seg[size2];

ld lazy[size2];
                                                                                   //The Question add the elements for a particular range query;
//This is 1- based indexing;

 int segment(ld low,ld high,ld pos)
  {
    if(low==high)
      seg[pos]=tree[low];
     else
      {
       
       ld mid=(high+low)/2;
       segment(low,mid,2*pos);
       segment(mid+1,high,2*pos+1);
       seg[pos]=seg[2*pos]+seg[2*pos+1];
      
       }
       }
   int updateRange(ld low,ld high,ld l,ld r,ld val,ld pos)
        {
            if(low>high||(l>high||r<low))
               return 0;
             
          if(lazy[pos]!=0)
           {
             seg[pos]+=(high-low+1)*lazy[pos];
             
             
             if(low!=high)
             {
             lazy[2*pos]+=lazy[pos];
             lazy[2*pos+1]+=lazy[pos];
             }
             lazy[pos]=0;
             
             }
          
            
            if(l<=low&&high<=r)
              {
               seg[pos]+=(val*(high-low+1));
               if(low!=high)
               {
               lazy[2*pos]+=val;
               lazy[2*pos+1]+=val;
                }
                return 0;
                }
                ld mid=(low+high)/2;
                updateRange(low,mid,l,r,val,2*pos);
                updateRange(mid+1,high,l,r,val,2*pos+1);
                }
                
          int queryRange(ld low,ld high,ld l ,ld r,ld pos)
               {
               
                   if(low>high||(l>high||r<low))
                       return 0; 
                       
                   if(lazy[pos]!=0)
                  {
        	     seg[pos]+=(high-low+1)*lazy[pos];
        	     if(low!=high)
        	     {
          	     lazy[2*pos]+=lazy[pos];
    		     lazy[2*pos+1]+=lazy[pos];
                       }
                       lazy[pos]=0;
                    }
                    
               
                 if(l<=low&&high<=r)
                   return seg[pos];
                
                ld mid=(high+low)/2;
                 
                
               ld q1= queryRange(low,mid,l,r,2*pos);
               ld q2= queryRange(mid+1,high,l,r,2*pos+1);
               return (q1+q2);
                }
                
                
         int main()
         {
          ld data,i;
          cin>>data;
          for( i=1;i<=data;i++)
            cin>>tree[i];
            
            segment(1,data,1);
            
            ld t;
            cin>>t;
            while(t--)
             {
               ld num;
               cin>>num;
               ld l,r,val;
              
               if(num==0)
               { cin>>l>>r>>val;
                 updateRange(1,data,l,r,val,1);
                 }
                else
                 { cin>>l>>r;
                  ld q=queryRange(1,data,l,r,1);
                  cout<<q<<"\n";
                  }
                  }
                  return 0;
                  }
                   
             
                
            
            
     
