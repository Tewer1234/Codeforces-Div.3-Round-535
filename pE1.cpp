#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int ary[1000000],l[1000000],r[1000000],sub[1000000],check[1000000],final[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,ans=INT_MIN,pos=1,chosen=0;
  cin>>n>>m;
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
  
  for (int i=1;i<=n;i++){
    int tt=0;
    memset(sub,0,sizeof(sub));
    memset(check,0,sizeof(check));
    for (int j=1;j<=m;j++){
      if (l[j]<=i and i<=r[j]){
        check[j]=1;
        tt++;
        for (int k=l[j];k<=r[j];k++){
          sub[k]++;
        }
      }
    }
    
    int maxNum=INT_MIN;
    for (int j=1;j<=n;j++){
      maxNum=max(maxNum,ary[j]-sub[j]);
    }
    
    // cout<<maxNum<<" "<<ary[i]-sub[i]<<"\n";
    int temp=maxNum-(ary[i]-sub[i]);
    if (temp>ans){
      ans=temp;
      pos=i;
      chosen=tt;
      for (int j=1;j<=m;j++){
        final[j]=check[j];
      }
    }
  }
  cout<<ans<<"\n";
  cout<<chosen<<"\n";
  for (int i=1;i<=m;i++){
    if (final[i]) cout<<i<<" ";
  }
  return 0; 
}
