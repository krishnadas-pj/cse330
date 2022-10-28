#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 128
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,k,h[1<<20],c[1<<20],t[1<<7][1<<17];
long nm,temp;
vector<pair<long, long> > v;

void ad(long &a,long &b)
{
 a+=b;
 if (a>=bs)a-=bs;
}

void add(long id,long i,long val)
{
 for (;i<=100000;i=(i|(i+1)))
  ad(t[id][i],val);
}

long sum(long id,long r)
{
 long res=0;
 for (;r>=0;r=(r&(r+1))-1)
  ad(res,t[id][r]);
 return res;
}


int main(){
//freopen("graph.in","r",stdin);
//freopen("graph.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;

add(0,0,1);
for (int i=1;i<=n;i++)
{
 cin>>h[i]>>c[i];
 v.clear();
 for (int mask=0;mask<(1<<k);mask++)
 {
  nm=mask;
  nm|=(1<<(c[i]-1));
  temp=sum(mask,h[i]-1);
  v.push_back(make_pair(nm,temp));
 }
 for (int j=0;j<v.size();j++)
 {
  nm=v[j].first;
  temp=v[j].second;
  add(nm,h[i],temp);
 }
}
cout<<sum((1<<k)-1,100000)<<endl;

cin.get();cin.get();
return 0;}  