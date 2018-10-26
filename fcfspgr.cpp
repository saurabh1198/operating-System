#include<iostream>
using namespace std;
int main()
{
	int k=0,i,pg[10],pf[10],nop,nof,avail,hit=0,fault=0,j;
	cout<<"enter no page";
	cin>>nop;
	cout<<"enter no of page farme";
	cin>>nof;
	cout<<"enter page refrence bit";
	for(i=0;i<nop;i++)
	{
		cin>>pg[i];
	}
	cout<<"enter page frame values";
		for(i=0;i<nof;i++)
	{
		cin>>pf[i];
	}
	for(i=0;i<nop;i++)
	{
		avail=0;
		for(j=0;j<nof;j++)
		{
			if(pf[j]==pg[i])
			{
				hit++;
				avail=1;
			}
		}
			if(avail==0)
			{
				pf[k]=pg[i];
				k=(k+1)%nof;
				fault++;
				
			}
		
	}
	cout<<"hit="<<hit<<endl;
	cout<<"fault="<<fault;
	cout<<"page frame  final bits";
	for(i=0;i<nof;i++)
	cout<<pf[i]<<" ";
}
