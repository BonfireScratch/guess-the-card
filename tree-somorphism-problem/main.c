#include <stdio.h> 
#include <stdlib.h> 

struct node  { 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

struct node* newNode(int data) { 
	struct node* node = (struct node*) 
								malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 

char * isIsomorphic(struct node* node1, struct node* node2) { 
	int flag = 0;
	
	if (node1 == NULL && node2 == NULL) {
		return "Isomorphic";
 	} else if ((node1 == NULL && node2 != NULL ) || (node1 != NULL && node2 == NULL )){
		flag = 1;
	}
	
	if (flag == 0) {
		if (isIsomorphic(node1->left,node2->left) == "Not isomorphic") {
			flag = 1;
		}

		if (isIsomorphic(node1->right,node2->right) == "Not isomorphic") {
			flag = 1;
		} 
	}
	
	if (flag == 1) {
		return "Not isomorphic";
	} else {
		return "Isomorphic";
	}
}	 

/* Driver program to test above functions*/
int main() { 
	char * result;
	struct node *root = newNode(1); 
	root->left		 = newNode(2); 
	root->right		 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right= newNode(5); 


	struct node *rootA = newNode(6); 
	rootA->left		   = newNode(7); 
	rootA->right	   = newNode(8); 
	rootA->left->left  = newNode(9); 
	rootA->left->right = newNode(10); 

	
	result=isIsomorphic(root, rootA); 
	printf("Tree is %s",result ); 
	return 0; 
} 
