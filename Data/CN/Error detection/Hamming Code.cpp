#include<stdio.h>
#include<string.h>
#include<math.h>

//Blockk to find no of parity bits required in the codeword
int No_of_Bits(int n)
{
	int d=0;
	
	while((int)(pow(2,d))<n+d+1)
		d++;
		
	return d;
}

//Block to check if a number is a power of 2 or not
int power_of_two(int n)
{
	int k=1;
	
	while(k<n)
		k*=2;
		
	if(k==n)
		return 1;
		
	return 0;
}

//Block to find out the parity of hte positional bits corresponding to the parity position
char find_parity(char codeword[],int j,int size)
{
	int c=0,k=j,count=0,i;
	
	while(1)
	{
		if(c==j)
		{
			k+=c;
			c=0;	
		}	
		
		if(size-k<0)
			break;
		
		if(k!=j)
		{
			i=size-k;
			
			if(codeword[i]=='1')
				count++;
		}
		
		c++;
		k++;
	}
	
	if(count%2==0)
		return '0';
		
	return '1';
}

//Block to find the parity bit values in codeword
void find_pvalues(char codeword[])
{
	int i,j,size=strlen(codeword);
	char c;
	
	j=1;
	i=size-j;
	
	while(i>=0)
	{
		
		c=find_parity(codeword,j,size);
		codeword[i]=c;
		
		j*=2;
		i=size-j;
	}
}

//Sender Impplementation
void sender(char data[],char codeword[])
{
	int size=strlen(data),p,i,j,k;
	
	//Finding out no of parity bits requires
	p=No_of_Bits(size);
	size+=p;
	
	printf("\nThe no of parity bits requires is : %d",p);
	
	k=0;
	
	//Preparing the codeword
	for(i=0;i<size;i++)
	{
		j=size-i;
		
		if(power_of_two(j))
			codeword[i]='p';
			
		else
			codeword[i]=data[k++];
	}
	
	codeword[i]='\0';
	
	//Finding the value of parity bit
	find_pvalues(codeword);
	
	printf("\nThe codeword is :%s",codeword);
	
}

void receiver(char codeword[])
{
	int i,j,size=strlen(codeword),sum=0;
	char c,p;
	
	j=1;
	i=size-j;
	
	while(i>=0)
	{
		p=codeword[i];
		c=find_parity(codeword,j,size);
		
		if(p!=c)
			sum+=j;
			
			
		j*=2;
		i=size-j;
	}
	
	if(sum==0)
		printf("\nThere is no error.");
		
	else
		printf("\nThe data is erroneous and the error is at position : %d",sum);
	
}

//Driver Function
int main (void)
{
	char data[100],codeword[100];
	int limit,pos;
	char choose;
	
	//User Input for the data
	printf("\nEnter the data:");
	gets(data);
	
	//Sender Side
	sender(data,codeword);
	
	//User input for existence of error
	printf("\nEnter Y if a bit is tampered while transmission else N:");
	scanf("%c",&choose);
	
	if(choose=='Y')
	{
		limit=strlen(codeword);
		
		//Position of error
		printf("\nEnter the position where there exists error:");
		scanf("%d",&pos);
		
		//Checking for invalid position
		if(pos>=limit || pos<=0)
		{
			printf("\nInvalid position!!!");
			return 1;
		}
		
		pos=limit-pos;
		
		if(codeword[pos]=='1')
			codeword[pos]='0';
		else
			codeword[pos]='1';
	}
	
	//Receiver side
	receiver(codeword);
	
	return 0;
}
