#include<iostream>
using namespace std;
int main()
{	
	int n,i;
	float avgwt=0.0,avgtat=0.0;
	cout<<"enter no of process";
	cin>>n;
	int p[n],at[n],c=0,ct[n],tat[n],wt[n];
	cout<<"enter burst time for each process";
	for(i=0;i<n;i++)
	{
		cin>>p[i];
		at[i]=0;
	}
	for(i=0;i<n;i++)
	{
		c=c+p[i];
		ct[i]=c;
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-p[i];
		avgwt=avgwt+wt[i];
		avgtat=avgtat+tat[i];
		cout<<"ct["<<i<<"]="<<ct[i]<<endl;
		
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
	cout<<"average waiting time="<<avgwt/n<<endl;
	
	cout<<"average turn around time ="<<avgtat/n<<endl;
	
		
}

