#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fi first
#define sec second
bool compare(pair<ll,ll> x ,pair<ll,ll> y)
    {
       if(x.fi==y.fi)
         return ((x.fi) < (y.fi));
        else
          return (x.sec < y.sec);
     } 

int area(ll ar[],ll n)
 {
    stack<ll> s;
  
   
    ll maxarea= 0;
     ll i=0;
    while(i<n)
     {
       if(s.empty()||ar[s.top()]<=ar[i])
 {        s.push(i);
           i++;
}
       else
        {
          ll tp= s.top();
           s.pop();
           ll ara=ar[tp]*((s.empty()==1)?i:(i-s.top()-1));
            maxarea=max(ara,maxarea);
         }
     
   }
     while(!s.empty())
       {
        ll tp=s.top();
         s.pop();
         ll ara=ar[tp]*(s.empty()?i:(i-s.top()-1));
          maxarea=max(ara,maxarea);
      }
  return maxarea;
  } 
 
int main()
{

  ll ar[10001]={0};
  ll t;
   cin>>t;
  while(t--)
     {
  ll a,b;
  cin>>a>>b;
 vector<pair<ll,ll> > v[10];
  for(int i=0;i<b;i++)
  {ll x,y,z;
   cin>>x>>y>>z;
   v[x].push_back(make_pair(y-1,z-1));
  }
  for(int i=1;i<=3;i++)
    sort(v[i].begin(),v[i].end(),compare);
 ll br[4][100001]={0};

for(int i=1;i<=3;i++)
 {  ll prev = 0 ,next =0;
   for(int j=0;j<v[i].size();j++)
    {
         ll m = v[i][j].fi ,n=v[i][j].sec;
          if(m<=next)
            m=next;
          if(n<=next)
           n=next;
         for(int k=m;k<=n;k++)
            br[i][k]=1;
           prev=m ; next=n;
    }
  }

  ll ans = area(br[1],a);
  for(int i=0;i<a;i++)
    { br[2][i]=(br[1][i]==0||br[2][i]==0)?br[2][i]:br[2][i]+br[1][i];
     
      }
   ll res= area(br[2],a);
   for(int i=0;i<a;i++)
    br[3][i]=(br[2][i]==0||br[3][i]==0)?br[3][i]:br[3][i]+br[2][i];
  
  ll pes = area(br[3],a);
 
  cout<<max(ans,max(res,pes));
}

return 0;
}
