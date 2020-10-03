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

set<string> permutations;

void permutations_with_caseChange(string in, string out){
	if(in.length()==0){
		permutations.insert(out);
		return;
	}

	string out1 = out;
	string out2 = out;


	char x = in[0];
	out1.push_back(x);
	out2.push_back(x-32);

	in.erase(in.begin());


	permutations_with_caseChange(in, out1);
	permutations_with_caseChange(in, out2);

	return;
}

int solve()
{
	permutations.clear();
	string s;
	cin>>s;
	string out = "";
	
	permutations_with_caseChange(s, out);

	for(auto it : permutations){
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