#include <stdio.h>

#include <stdlib.h>

typedef struct node

{

	int data;	struct node *next;

}node;

int main()

{

	int i,n;

	struct node *head=NULL,*A,*B,*C;

	printf("Enter the number of nodes\n");

	scanf("%d",&n);

	for(i=1;i<=n;i++)

	{

		if(head==NULL)

		{

			head=(struct node*)malloc(sizeof(struct node));

			printf("Enter the element\n");

			scanf("%d",&head->data);

			A=head;

			head->next=NULL;

		}

		else

		{

			B=(struct node*)malloc(sizeof(struct node));

			A->next=B;

			A=A->next;

			printf("Enter the element\n");

			scanf("%d",&A->data);

			A->next=NULL;

		}

	}

	A=head;

	printf("Elements of all the nodes\n");

	while(A!=NULL)

	{

		printf("%d\t",A->data);

		A=A->next;

	}

	//inversion of linked list

	A=NULL;

	B=head;

	C=B->next;

	while(B!=NULL)

	{

		B->next=A;

		A=B;

	    B=C;

	    if(C!=NULL)

	    {

	    	C=C->next;

	    }

	}

	head=A;

	printf("\nElements after inversion\n");

	while(A!=NULL)

	{

		printf("%d\t",A->data);

		A=A->next;

	}

	return 0;

}
