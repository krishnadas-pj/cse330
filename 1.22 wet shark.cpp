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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,r,s,na,nb,q,dp[101][2525][101];
long long ans;

void add(long&a,long &b)
{
 a+=b;
 if (a>=bs)
  a-=bs;
}

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>r>>s;
nb=(r-s)/2;

na=r-nb;
if (na>2000) return 1;

dp[0][0][0]=1;

for (int i=1;i<=n;i++)
{
     cin>>q;
     for (int j=0;j<=2000;j++)
     for (int l=0;l<=n;l++)
     {
      add(dp[i][j][l],dp[i-1][j][l]);
      if (j>=q&&l>0)
       add(dp[i][j][l],dp[i-1][j-q][l-1]);
     }
}
long long answ=0;

for (int p=1;p<=n;p++)
{
ans=dp[n][na][p];
if (s%2!=r%2||r<s)
 ans=0;else
ans*=dp[n][nb][p];
ans%=bs;
answ=answ+ans;
answ%=bs;}
cout<<answ<<endl;

cin.get();cin.get();
return 0;}



