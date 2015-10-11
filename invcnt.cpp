#include <bits/stdc++.h>
using namespace std;
long long int cnt=0;
void merge(int* a,int* b,int s,int e){
	if(s>=e)
		return ;
	merge(a,b,s,(s+e)/2);
	merge(a,b,((s+e)/2)+1,e);
	int i = s,j=((s+e)/2)+1,n = s;
	while(i <= (s+e)/2 && j <= e)
		if(a[i] <= a[j] && i <= (s+e)/2)
			b[n++] = a[i++];
		else {
			b[n++] = a[j++];
			cnt+=(s+e)/2+1-i;
		}
	while(i<=(s+e)/2)
		b[n++] = a[i++];
	while(j<=e)
		b[n++] = a[j++];
	for(i=s;i<=e;i++)
		a[i] = b[i];
	return ;
}
int main() {
	int t,i,j,k,l,n,m,a[200005],b[200005];
	cin>>t;
	while(t--) {
		cin>>n;
		cnt=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		merge(a,b,0,n-1);
		cout<<cnt<<endl;
	}
	return 0;
}
