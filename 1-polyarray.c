/*
  Write a program using arrays to read & print a polynomial.
  Write a program to add & multiply two polynomials.
*/

#include<stdio.h>

int main()
{
	int A[50],B[50],C[50],i=0,j=0,k,count=0,ch=1,m,n;

	printf("Input the terms of polynomial 1\n");
	while(ch==1)
	{
		printf("Enter exponential degree of the term : "); //to store the exponent of the degree in the array
		scanf("%d",&A[++i]);
		printf("Enter co-efficient of the term : "); //to store the coefficient of the degree in the array
		scanf("%d",&A[++i]);
		printf("Add another term? (1/0) : ");
		scanf("%d",&ch);
		count++;
	}
	A[0]=count; //no.of terms to be stored in the first index of array A

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
	B[0]=count; //no.of terms to be stored in the first index of array B

	printf("\nPolynomial 1 is : ");
	for(k=1;k<=2*A[0];k=k+2)  //traversing till the size of array from index1, as the index0 is only size
	{
		printf("%dx^%d",A[k+1],A[k]);
		if(k<2*A[0]-1)        //to avoid the + at the end of the polynomial
			printf(" + ");
	}

	printf("\nPolynomial 2 is : ");
	for(k=1;k<=2*B[0];k=k+2) //traversing till the size of array from index1, as the index0 is only size
	{
		printf("%dx^%d",B[k+1],B[k]);
		if(k<2*B[0]-1)
			printf(" + "); //printing the values
	}


//Addition of the two polynomials

	count=0;
	k=1;

	for(m=1,n=1 ; m<i&&n<j ; )
	{
        if(A[m]<B[n])      //If exponential in B is greater than A, then store the exponent and coefficient of that term in B to C
		{
			C[k++]=B[n++];
			C[k++]=B[n++];
			count++;
		}
		else
		{
			if(A[m]>B[n]) //If exponential in B is lesser than A, then store the exponent and coefficient of that term in A to C
			{
				C[k++]=A[m++];
				C[k++]=A[m++];
				count++;
			}
			else         //If exponential of both polynomial numbers is same, then add the respective coefficients and store the updated coefficient in C
			{
				C[k++]=A[m++];
				n++;
				C[k++]=A[m++]+B[n++];
				count++;
			}
		}
	}
	for( ; m<i ; )      //for any additional terms left in A to be evaluated
	{
        C[k++] = A[m++];
        C[k++] = A[m++];
        count++;
	}
	for( ; n<j ; )     //for any additional terms left in B to be evaluated
    {
        C[k++] = B[n++];
        C[k++] = B[n++];
        count++;
	}

	C[0]=count;
	printf("\n\nSum of the two polynomials is : ");

	for(k=1;k<2*C[0];k=k+2)            //k+2 indicates the index of the next coefficient
	{
		printf("%dx^%d",C[k+1],C[k]);  //printing the addition value of two polynomials
		if(k<2*C[0]-1)
			printf(" + ");
	}


//Multiplication of the two polynomials

	count = 0;
	k = 1;
	for(m = 1; m <= i; m = m + 2){
        for(n = 1; n <= j ; ){
            C[k++] = A[m] + B[n++];      //Add the exponentials of both polynomials A,B and updating it in C
            C[k++] = A[m + 1] * B[n++];  //Multiply the coefficient of both polynomials A,B and updating it in C
            count++;
        }
	}

	C[0] = count;
	printf("\n\nMultiplication of the two polynomials is : ");

	for(k=1;k<2*C[0];k=k+2)
	{
		printf("%dx^%d",C[k+1],C[k]);  //printing the multiplication value of two polynomials
		if(k<2*C[0]-1)
			printf(" + ");
	}
	return 0;
}
