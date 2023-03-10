/*
Write a program using linked list to read & print a polynomial
Write a program to insert & delete a term of a polynomial
Write a program to add & multiply two polynomials
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int coeff;
	int exp;
	struct node *next;
} poly;

void insertterm(int,int,int);
void sort(poly*);

void polyin(int);
void polyout(poly*);

void appendterm();
void deleteterm();
void polyadd(poly*,poly*);
void polymul(poly*,poly*);

poly *p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL,*temp,*prev,*newnode,*i,*j;

//To store values of polynomials by creating a node
void insertterm(int co,int ex,int poly_no)
{
	newnode=(poly*)malloc(sizeof(poly));
	newnode->coeff=co;
	newnode->exp=ex;
	newnode->next=NULL;

	switch(poly_no)
	{
	case 1:
		if(p1==NULL)
		{
			p1=newnode;
			return;
		}
		temp=p1;
		break;
	case 2:
		if(p2==NULL)
		{
			p2=newnode;
			return;
		}
		temp=p2;
		break;
	case 3:
		if(p3==NULL)
		{
			p3=newnode;
			return;
		}
		temp=p3;
		break;
	case 4:
		if(p4==NULL)
		{
			p4=newnode;
			return;
		}
		temp=p4;
		break;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newnode;
}

// For user Input
void polyin(int n)
{
	int coeff,exp;
	printf("\n(Enter coefficient 0 to be terminated)\n");
	while(1)
	{
		printf("Enter co-efficient of the term : ");
		scanf("%d",&coeff);
		if(coeff==0)
			break;
		printf("Enter exponential degree of the term : ");
		scanf("%d",&exp);
		insertterm(coeff,exp,n);
	}
}

//To display the results
void polyout(poly *p)
{
	if(p==NULL)
	{
		printf("Empty List\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%dx^%d ",p->coeff,p->exp);
		if(p->next!=NULL)
			printf("+ ");
		p=p->next;
	}
	printf("\n");
}

//To add the two polynomials
void polyadd(poly *p1,poly *p2)
{
	int r;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->exp == p2->exp) //polynomials terms with same degree to be evaluated
		{
			r=p1->coeff+p2->coeff;
			if(r!=0)
				insertterm(r,p2->exp,3);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->exp < p2->exp)
		{
			insertterm(p2->coeff,p2->exp,3);
			p2=p2->next;
		}
		else
		{
			insertterm(p1->coeff,p1->exp,3);
			p1=p1->next;
		}
	}
	while(p1!=NULL)
	{
		insertterm(p1->coeff,p1->exp,3);
		p1=p1->next;
	}
	while(p2!=NULL)
	{
		insertterm(p2->coeff,p2->exp,3);
		p2=p2->next;
	}
}

void polymul(poly *p1,poly *p2)
{
    int c,e,flag;
    for(i=p1;i!=NULL;i=i->next)
        for(j=p2;j!=NULL;j=j->next)
        {
            flag=0;
            c=i->coeff*j->coeff;  //coefficients are being multiplied
            e=i->exp+j->exp;  //exponential powers are being added
            temp=p4;
            while(temp!=NULL)
            {
                if(e==temp->exp)
                {
                    temp->coeff+=c;
                    flag++;
                    break;
                }
                temp=temp->next;
            }
            if(flag==0)
                insertterm(c,e,4);
        }
}

//To insert one or more new terms to any of the two polynomials
void appendterm()
{
    int p,coeff,exp,flag=0;
    printf("Enter to which polynomial the term to append (1 or 2): ");
    scanf("%d",&p);
    printf("\n(Enter coefficient 0 to be terminated)\n");
	while(1)
	{
		printf("Enter co-efficient of the term : ");
		scanf("%d",&coeff);
		if(coeff==0)
			break;
		printf("Enter exponential degree of the term : ");
		scanf("%d",&exp);
		if(p==1)
            temp=p1;
        else
            temp=p2;
		while(temp!=NULL)
            {
                if(exp==temp->exp)
                {
                    temp->coeff+=coeff;
                    flag++;
                    break;
                }
                temp=temp->next;
            }
            if(flag==0)
                insertterm(coeff,exp,p);
	}
}

//To delete a term among any of the two polynomials
void deleteterm()
{
    int i,p,e,pos;
    printf("Enter to which polynomial the term to remove (1 or 2): ");
    scanf("%d",&p);
    printf("Enter position of the term to remove: ");
    scanf("%d",&pos);
    if(pos==0)
    {
        if(p==1)
            p1=p1->next;
        else
            p2=p2->next;
    }
    else
    {
        if(p==1)
            temp=p1;
        else
            temp=p2;

        for(i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
}

void sort(poly *p)
{
	int t1,t2;
	if(p==NULL)
		return;
	else
		for(temp=p;temp!=NULL;temp=temp->next)
			for(j=temp->next;j!=NULL;j=j->next)
				if(temp->exp < j->exp)
				{
					t1=temp->exp;
					t2=temp->coeff;
					temp->exp=j->exp;
					temp->coeff=j->coeff;
					j->exp=t1;
					j->coeff=t2;
				}
}

int main()
{
	int choice,n;
	while(1)
	{
		printf("\nMENU");
		printf("\n1. Insert");
		printf("\n2. Display");
		printf("\n3. Append");
		printf("\n4. Remove");
		printf("\n5. Addition");
		printf("\n6. Multiply");
		printf("\n7. Exit");

		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter input for polynomial 1 ");
                polyin(1);
                sort(p1);
                printf("\nEnter input for polynomial 2 ");
                polyin(2);
                sort(p2);
				break;
			case 2:
				printf("\nPolynomial 1 is : ");
                polyout(p1);
                sort(p1);
                printf("Polynomial 2 is : ");
                polyout(p2);
                sort(p2);
				break;
			case 3:
			    appendterm();
			    sort(p1);
			    sort(p2);
				break;
            case 4:
                deleteterm();
				break;
            case 5:
                polyadd(p1,p2);
                printf("\nThe addition of two polynomial gives : ");
                polyout(p3);
                sort(p3);
                break;
            case 6:
                polymul(p1,p2);
                printf("\nThe multiplication of the two polynomial gives : ");
                polyout(p4);
                sort(p4);
                break;
			case 7:
				exit(1);
			default:
				printf("WRONG INPUT\n");
		}
	}
	return 0;
}
