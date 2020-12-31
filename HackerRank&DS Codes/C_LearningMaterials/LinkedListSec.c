#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	node *next;
};

void printer(node *);
node *appendConsecutive(node* , int);

int main()
{
	node *root;
	root = NULL;
	int n,num=0;
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%d",&num);
		root = appendConsecutive(root,num);
	}
		
	printer(root);
	
	return 0;
}

void printer(node *r)
{
	while (r != NULL){
		printf("%d ",r -> data);
		r = r -> next;
	}	
}

node * appendConsecutive(node *r,int x)
{
	
	if (r==NULL){ // link list bo�sa
		r=(node *) malloc(sizeof(node));
		r -> next = NULL;
		r -> data = x;
		return r;
	}
	
	if (r->data > x){ // ilk elemandan k���k durumu
		// root de�i�iyor ��nk� ilk kutuya daha k���k eleman geldi
		node *temp = (node*)malloc(sizeof(node));
		temp -> data = x;
		temp -> next = r;
		return temp;
	}	
		
	node *iter = r;
	while(iter->next != NULL && iter->next->data < x)
		iter = iter->next;
	
	node *temp = (node*)malloc(sizeof(node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> data = x;
	return r;
	
	
	
}
