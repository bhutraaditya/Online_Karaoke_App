#include<fstream>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
double ans=0;
ifstream f1,f2;
f1.open("in1.txt");
f2.open("in2.txt");
vector<double> arr1(500), arr2(500);
vector<int> num1(500,0), num2(500,0);
double max1=0,max2=0;

double s1=0,s2=0;
bool f1a=0,f2a=0;

while(!f1.eof())
{
double a,b;
f1>>a>>b;
if(!f1a)
{
if(b>0)
{s1=a;
f1a=1;}
}
else
{
arr1[floor(a-s1)]+=b;
num1[floor(a-s1)]++;
max1=max(max1,floor(a-s1));
}
}

while(!f2.eof())
{
double a,b;
f2>>a>>b;
if(!f2a)
{if(b>0)
{
s2=a;
f2a=1;
}
}
else
{
arr2[floor(a-s2)]+=b;
num2[floor(a-s2)]++;
max2=max(max2,floor(a-s2));
}
}
for(int i=0;i<min(max1,max2);++i)
{
double k=abs(arr1[i]/num1[i] - arr2[i]/num2[i]);
//k=arr1[i]*num2[i]/(num1[i]*arr2[i]);
//if(k<=1)ans+=100*(k);
//else if(k<=1)ans+=100*(k-1);
ans+=k;
}
ans/=min(max1,max2);
if(min(max1,max2)<18)cout<<0;
else
{

if(ans>=500)cout<<0;
else cout<<(int)(100-ans/5);
}
return 0;
}
