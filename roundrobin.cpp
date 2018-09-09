#include<iostream>
using namespace std;
void roundrobin(int tq,int n,int s,int bt[])
{  
	int a[n],tat[n],wt[n],avgtat=0,avgwt=0,k[n];
	float avgtatt,avgwtt;
	for(int i=0;i<n;i++)
{       
         k[i]=0;
		tat[i]=0;
		a[i]=bt[i];
}
	while(s>0)
	{
	int j=0;
	while(j<n)
	{    if(k[j]==1)
	{
	j++;
	continue;

}
		if(tq<a[j])
		{    avgtat=avgtat+tq;
			tat[j]=avgtat;
			a[j]=a[j]-tq;
		s=s-tq;
		j++;	
		}
		else
		{   k[j]=1;
		avgtat=avgtat+a[j];
			tat[j]=avgtat;
			s=s-a[j];
			j++;
		}
	}
}
cout<<"turn around time\n";
avgtat=0;
for(int k=0;k<n;k++)
{  wt[k]=tat[k]-bt[k];
cout<<tat[k]<<endl;
avgtat=avgtat+tat[k];

}
cout<<"witing time\n";
for(int k=0;k<n;k++)
{  
cout<<wt[k]<<endl;
avgwt=avgwt+wt[k];

}

avgtatt=(float)avgtat/n;
avgwtt=(float)avgwt/n;
cout<<"\naverage turnaround time="<<avgtatt;
cout<<"\naverage waitng time="<<avgwtt;
}
int main()
{
	int tq,n;
	cout<<"\t \t Roundrobin scheduling\n";
	cout<<"enter no of  process: ";
	cin>>n;
	int bt[n],s=0;
	cout<<"enter burst time for each process:\n ";
	for(int i=0;i<n;i++)
	{
		cin>>bt[i];
		s=s+bt[i];
	}
cout<<"enter time quantum\n";
cin>>tq;
roundrobin(tq,n,s,bt);

}
