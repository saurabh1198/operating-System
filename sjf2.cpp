//shortest job first 
//author saurabh kushwah
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{	
	int n,i;
	float avgwt=0.0,avgtat=0.0;
	cout<<"enter no of process";
	cin>>n;
	int p[n],at[n],c=0,ct[n],tat[n],wt[n],a[n];//tat=turn around time
	cout<<"enter burst time for each process";  //wt=waitng time
	for(i=0;i<n;i++)                
	{
		cin>>p[i];
		at[i]=0;   //burst time calculation
		a[i]=p[i];
	}
	
	
	sort(p,p+n);  //sorting a/c to burst time
	
	for(i=0;i<n;i++)
	{
		c=c+p[i];
		ct[i]=c;
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-p[i];    //calculation for turn around time
		avgwt=avgwt+wt[i];    //and waaitin time
		avgtat=avgtat+tat[i];
		
		
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(p[i]==a[j])     //reposition tat and wt for their actual process
				{
					tat[j]=ct[i];
					wt[j]=wt[i];
				}
			}
		}
		for(i=0;i<n;i++)
		{
			wt[i]=tat[i]-a[i]; //waiting time 
			
		}
		
		cout<<"turn around time"<<endl;
		for(i=0;i<n;i++)
     {
	cout<<"tat["<<i<<"]="<<tat[i]<<endl;
	}	
	cout<<"waiting time"<<endl;
	for(i=0;i<n;i++)
     {
	cout<<"wt["<<i<<"]="<<wt[i]<<endl;
	}
	cout<<"average waiting time="<<avgwt/n<<endl;//avgwt

cout<<"avg turn around time="<<avgtat/n<<endl;
}
