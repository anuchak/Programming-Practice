#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
	return a;
	
	if(a > b)
		return gcd(b,a%b);
	else if(b > a)
		return gcd(a,b%a);
	else
		return a;
}

int lcm(int a,int b)
{
	return (a/gcd(a,b))*b;
}

int main()
{
	int s1,s2;
	cin>>s1>>s2;
	int a[s1],b[s2];
	   
	int l = 1;
	
	for(int i=0;i<s1;i++)
	{
		int t;
        cin>>t;
        a[i]=t;
        l = lcm(t,l);
	}	
	cout<<"lcm -> "<<l<<endl;
	int h;
	cin>>b[0];
	h=b[0];
	for(int i=1;i<s2;i++)
	{
		int t;
		cin>>t;
		b[i]=t;
		h = gcd(h,t);
	}
    cout<<"hcf -> "<<h<<endl;
    if(l > h)
    	cout<<0<<endl;
    else if (l == h)
    	cout<<1<<endl;
    else {

    	h /= l;
    	int res = 0;
        for(int i = 1; i <= h; i++)
        {
        	if(h % i == 0)
        	{
        		res++;
        	}
        }
        cout<<res<<endl;
    }
	return 0;
}
