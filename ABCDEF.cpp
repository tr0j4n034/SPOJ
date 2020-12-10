//author : codeminion(SPOJ)


#include <bits/stdc++.h>
using namespace std;
int main ()
{
		int n;
		scanf("%d",&n);
		int a[n];
		int i,j,k;
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		vector <int> v1;
		vector <int> v2;
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				for (k=0;k<n;k++){
					v1.push_back(a[i]*a[j]+a[k]);
				}
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				for (k=0;k<n;k++)
					if (a[i])
					v2.push_back(a[i]*(a[j]+a[k]));
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		int s=v1.size();
		long long int sum=0;
		for (i=0;i<s;i++){
        	int lo=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
    	 	int hi=upper_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
        	sum+=(hi-lo);
    	}
		cout<<sum<<endl;
	return 0;
}
