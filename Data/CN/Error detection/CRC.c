#include<stdio.h>
#include<string.h>

//Display a binary character array
void display(char arr[],int size)
{
	int i;
	
	for(i=0;i<size;i++)
		printf("%c",arr[i]);
		
	printf("\n");
}

//Block to copy one binary string into other
void copy(char a[],char b[],int size)
{
	int i;
	
	for(i=0;i<size;i++)
		a[i]=b[i];
}

//Block to initialise a binary string with all '0'
void reset(char a[],int size)
{
	int i;
	
	for(i=0;i<size;i++)
		a[i]='0';
}

//Block to perform bitwise xor
char XOR(char a,char b)
{
	if((a=='0' && b=='0') || (a=='1' && b=='1'))
		return '0';
	return '1';
}

//Block to divide two binary strings
void divide(char arr[],char div[],char min[],char sub[],int n,int m)
{
	int i,j;
	
	for(i=0;i<m;i++)
		min[i]=arr[i];
		
	for(i=0;i<n;i++)
	{
		if(min[0]=='1')
			copy(sub,div,m);   
			
		else
			reset(sub,n);
			
		for(j=0;j<m-1;j++)
			min[j]=XOR(min[j+1],sub[j+1]);
			
		if(i+m>=n+m-1)
			min[j]='\0';
			
		else
			min[j]=arr[i+m];
	}
}

//Sender Block
void sender(char data[],char codeword[],char div[])
{
	int n=strlen(data),m=strlen(div),i,newsize;
	
	char min[m],sub[m],newdata[n+m-1];
	
	//Padding data with 0s equal to size of divisor -1 
	for(i=0;i<n+m-1;i++)
	{
		if(i<n)
			newdata[i]=data[i];
			
		else
			newdata[i]='0';
	}
	
	printf("\nThe data after padding zeros is : ");
	display(newdata,n+m-1);
	
	//Perdorming the division operation and calculating the CRC bits
	divide(newdata,div,min,sub,n,m);
	
	printf("\nThe CRC bits are : %s",min);
	
	newsize=n+m-1;
	
	//Generating the Codeword
	for(i=0;i<newsize;i++)
	{
		if(i<n)
			codeword[i]=newdata[i];
			
		else
			codeword[i]=min[i-n];
	}
	
	codeword[i]='\0';
	
	printf("\nThe codeword is :%s",codeword);
	
}

//Receiver Side
void receiver(char codeword[],char div[])
{
	int n=strlen(codeword),m=strlen(div),i;
	char min[m],sub[m];
	
	//Division performed to find the remainder
	divide(codeword,div,min,sub,n-m+1,m);
	
	printf("\nThe remainder is : %s",min);
	
	//Remainder checked.If it is 0 then no error otherwise error exists
	for(i=0;i<m;i++)
	{
		if(min[i]=='1')
		{
			printf("\nData is received erroneously and received data is : %s",codeword);
			return;
		}
	}
	
	printf("\nData is error free.");
}

int main (void)
{
	char data[100],codeword[100],div[50],choose;
	int pos,limit;
	
	//User Input to get data and divisor
	printf("\nEnter the data:");
	gets(data);
	
	printf("\nEnter the divisor :");
	gets(div);
	
	//Sender Side
	sender(data,codeword,div);
	
	//User inputs to set error
	printf("\nEnter Y if there is error in the d=codeword while transmitting through medium else N:");
	scanf("%c",&choose);
	
	if(choose=='Y')
	{
		limit=strlen(codeword);
		
		printf("\nEnter the position of the bit error:");
		scanf("%d",&pos);
		
		if(pos>=limit)
		{
			printf("\nInvalid position!!!");
			return 1;
		}
		
		pos=limit-pos-1;
		
		if(codeword[pos]=='1')
			codeword[pos]='0';
			
		else
			codeword[pos]='1';
	}
	
	//Receiver Side
	receiver(codeword,div);
	
	return 0;
}
