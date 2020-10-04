#include <bits/stdc++.h>
using namespace std;
#define ll           long long 
#define rep(i,j,n)   for(ll i=j;i<n;i++)
#define scn(a)       scanf("%lld",&a)
#define nl           printf("\n")
#define scns(a,b)    scanf("%lld %lld",&a,&b)
#define print(a)     printf("%lld",a)
#define tc           ll t; scn(t); while(t--)
#define vec          vector<ll>
#define pb           push_back
#define pairs        pair<ll,ll>
#define fi           first
#define se           second
#define all(v)       v.begin(),v.end()
#define srt(v)       sort(v.rbegin(),v.rend())
#define mem(a,b)     memset(a,b,sizeof(a))
#define maxx         5000005
#define inf          LLONG_MAX
#define zer          LLONG_MIN
#define dbug(a)      cout<<"dbug : "<<a<<endl
#define debug(a,b)   cout<<a<<" "<<b<<endl
#define read(v)      vec v(n,0); rep(i,0,n) {cin>>v[i];}
#define write(a,n)   rep(i,0,n) {cout<<a[i]<<" ";}
#define All          rep(i,0,n)




/* 
Ques - to print all the permutaion with case change.
The basic thing is we always need to take two decisions and form a recursive tree the basis of those desisions.
Here we are decidinh that we want to change the case of the letter or not.

It is imp that we always tend to make the input smaller with every move.
 input - abc
	
	output - 

	ABC
	ABc
	AbC
	Abc
	aBC
	aBc
	abC
	abc


*/
set<string> st;
void permutation_with_digits(string in, string out){
	if(in.length() == 0){
		st.insert(out);
		return;
	}

	char x = in[0];
	if(x >=65 and x<=90) {
		string out1 = out;
		string out2 = out;
		out1.push_back(x);
		out2.push_back(x+32);
		in.erase(in.begin());
		permutation_with_digits(in, out1);
		permutation_with_digits(in, out2);
	}

	else if(x>=97 and x<=122) {
		string out1 = out;
		string out2 = out;
		out1.push_back(x);
		out2.push_back(x-32);
		in.erase(in.begin());
		permutation_with_digits(in, out1);
		permutation_with_digits(in, out2);
	}

	else if(x-'0' >=0 and x-'0' <=9){
		string out1 = out;
		out1.push_back(x);
		in.erase(in.begin());
		permutation_with_digits(in, out1);
	}

	return;
}

int solve()
{
	string s;
	cin>>s;

	string out = "";
	permutation_with_digits(s,out);

	for(auto it : st){
		cout<<it<<endl;
	}




   return 0;

}



int main()
{
int test;
test = 1;
//cin>>test;

while(test--)
{
	solve();
}

    
return 0;
}