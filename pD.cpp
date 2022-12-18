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
int color[1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,ans=0;
  string s;
  cin>>n>>s;
  
  for (int i=0;i<n;i++){
    int check=0;
    memset(color,0,sizeof(color));
    if (i>=1){
      if (s[i]==s[i-1]){
        ans++;
        check=1;
        color[s[i-1]]=1;
      }
    }
    if (i+1<n){
      color[s[i+1]]=1;
    }
    
    if (check){
      if (!color['R']) s[i]='R';
      else if (!color['G']) s[i]='G';
      else s[i]='B';
    }
  }
  
  cout<<ans<<"\n"<<s;
  return 0; 
}
