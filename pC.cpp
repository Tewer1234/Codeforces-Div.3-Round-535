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
string comb[100]={
  "GAY",
  "RGB",
  "RBG",
  "BGR",
  "BRG",
  "GRB",
  "GBR"
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,ans=INT_MAX,method=-1;
  string s;
  cin>>n>>s;
  
  for (int i=1;i<=6;i++){
    int temp=0;
    for (int j=0;j<n;j++){
      char c=comb[i][j%3];
      if (c!=s[j]) temp++;
    }
    
    if (temp<ans){
      ans=temp;
      method=i;
    }
  }
  cout<<ans<<"\n";
  for (int i=0;i<n;i++){
    char c=comb[method][i%3];
    if (c!=s[i]) s[i]=c;
  }
  cout<<s;
  return 0; 
}
