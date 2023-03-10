#include<stdio.h>

int main()
{
	int A[50],B[50],C[50],i=0,j=0,k,count=0,ch=1,m,n;

	printf("Input the terms of polynomial 1\n");
	while(ch==1)
	{
		printf("Enter exponential degree of the term : ");
		scanf("%d",&A[++i]);
		printf("Enter co-efficient of the term : ");
		scanf("%d",&A[++i]);
		printf("Add another term? (1/0) : ");
		scanf("%d",&ch);
		count++;
	}
	A[0]=count;

	count=0;
	ch=1;

	printf("\nInput the terms of polynomial 2\n");
	while(ch==1)
	{
		printf("Enter exponential degree of the term : ");
		scanf("%d",&B[++j]);
		printf("Enter co-efficient of the term : ");
		scanf("%d",&B[++j]);
		count++;
		printf("Add another term? (1/0) : ");
		scanf("%d",&ch);
	}
	B[0]=count;

	printf("\nPolynomial 1 is : ");
	for(k=1;k<=2*A[0];k=k+2)
	{
		printf("%dx^%d",A[k+1],A[k]);
		if(k<2*A[0]-1)
			printf(" + ");
	}

	printf("\nPolynomial 2 is : ");
	for(k=1;k<=2*B[0];k=k+2)
	{
		printf("%dx^%d",B[k+1],B[k]);
		if(k<2*B[0]-1)
			printf(" + ");
	}

	count=0;
	k=1;

	for(m=1,n=1 ; m<=i||n<=j ; )
	{
		if(A[m]<B[n])
		{
			C[k++]=B[n++];
			C[k++]=B[n++];
			count++;
		}
		else
		{
			if(A[m]>B[n])
			{
				C[k++]=A[m++];
				C[k++]=A[m++];
				count++;
			}
			else
			{
				C[k++]=A[m++];
				n++;
				C[k++]=A[m++]+B[n++];
				count++;
			}
		}
	}

	C[0]=count;
	printf("\n\nSum of the two polynomials is : ");

	for(k=1;k<=2*C[0];k=k+2)
	{
		printf("%dx^%d",C[k+1],C[k]);
		if(k<2*C[0]-1)
			printf(" + ");
	}
	return 0;
}
