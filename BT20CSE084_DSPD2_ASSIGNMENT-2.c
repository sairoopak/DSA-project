#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>

struct pers         // structure definition for personal
{	
	char f_name[20];
	char l_name[20];
	char email[20];
	int number;        // key
	int ht;
	struct pers* left;
	struct pers* right;
};

struct prof               // structure definition for professional
{	
	char f_name[20];
	char l_name[20];
	char email[20];
	char off_name[20];
	char off_address[20];
	int number;              // key
	int ht;
	struct prof* left;
	struct prof* right;
};

struct phonebook             // structure definition for phonebook
{
	char name[20];
	char mob_number[20];
	char address[20];
	int calls;
	int duration_in_min;
	struct phonebook* left;	
	struct phonebook* right;
};

//func's to find max number(key)

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//func's to find height

int height(struct pers *root)   //personal
{
	int retval;
	if(root == NULL)
	{
		retval = -1;
	}
	else
	{
		retval = (max(height(root->left),height(root->right))+1); 
	}
	return retval;
}

int height_prof(struct prof *root_prof)    //professional
{
	int retval;
	if(root_prof == NULL)
	{
		retval = -1;
	}
	else
	{
		retval = (max(height_prof(root_prof->left),height_prof(root_prof->right))+1); 
	}
	return retval;
}

//func's to find balance factor 

int bf(struct pers *root)    //personal
{
	return abs(height(root->left) - height(root->right));
}

int bf_prof(struct prof *root_prof)    //professional
{
	return abs(height_prof(root_prof->left) - height_prof(root_prof->right));
}

//rotate fun's (to maintain balance factors) for personal

struct pers* LL(struct pers* x)     
{
	struct pers* y = x->left;
	x->left = y->right;
	y->right = x;
	x->ht = height(x);
	y->ht = height(y);
	return y;
}

struct pers *RR(struct pers* x)    
{
	struct pers *y = x->right;
	x->right = y->left;
	y->left = x;
	x->ht = height(x);
	y->ht = height(y);
	return y;
}

struct pers *LR(struct pers* x)
{
	x->left = RR(x->left);
	x = LL(x);
	return x;
}

struct pers *RL(struct pers* x)
{
	x->right = LL(x->right);
	x = RR(x);
	return x;
}

//rotate fun's (to maintain balance factors) for professional

struct prof* LL_prof(struct prof* x)     
{
	struct prof* y = x->left;
	x->left = y->right;
	y->right = x;
	x->ht = height_prof(x);
	y->ht = height_prof(y);
	return y;
}

struct prof* RR_prof(struct prof* x)   
{
	struct prof* y = x->right;
	x->right = y->left;
	y->left = x;
	x->ht = height_prof(x);
	y->ht = height_prof(y);
	return y;
}

struct prof* LR_prof(struct prof* x)
{
	x->left = RR_prof(x->left);
	x = LL_prof(x);
	return x;
}

struct prof* RL_prof(struct prof* x)
{
	x->right = LL_prof(x->right);
	x = RR_prof(x);
	return x;
}

// function's to Insert/add for personal

struct pers* insert_pers(struct pers* root, char f_name[20], char l_name[20], char email[20], int number)
{	
	struct pers *nptr = NULL;

	if(root == NULL)
	{
		nptr = (struct pers*) malloc(sizeof(struct pers));			
		strcpy (nptr->f_name , f_name);
		strcpy (nptr->l_name , l_name);
		strcpy (nptr->email , email);
		nptr->number = number;
		nptr->ht=0;
		nptr->left = NULL;
		nptr->right = NULL;
		root = nptr;
		return root;
	}
	else if(number < root->number)
	{
		root->left=insert_pers(root->left, f_name, l_name, email, number);
		if(bf(root) == 2)
		{
			if(number < root->left->number)     // nptr inserted to left of root->left
			{
				return LL(root);
			}
			else
			{
				return LR(root);
			}
		}
	}
 	else
    {
		root->right = insert_pers(root->right, f_name, l_name, email, number);
  		if (bf(root) == 2)
  		{
   			if (number > root->right->number)     // nptr inserted to right of root->right
    		{
    			return RR(root);
			}
   			else
    		{
    			return RL(root);
			}
  		}
    }
    root->ht = height(root);
 	return root;
}

// function's to Insert/add for professional

struct prof* insert_prof(struct prof* root_prof, char f_name[20], char l_name[20], char email[20],
                           char off_name[20], char off_address[20], int number)
{	
	struct prof* nptr = NULL;

	if(root_prof == NULL)
	{
		nptr = (struct prof*) malloc(sizeof(struct prof));			
		strcpy (nptr->f_name , f_name);
		strcpy (nptr->l_name , l_name);
		strcpy (nptr->email , email);
		strcpy (nptr->off_name , off_name);
		strcpy (nptr->off_address , off_address);
		nptr->number = number;
		nptr->ht = 0;
		nptr->left = NULL;
		nptr->right = NULL;
		root_prof = nptr;
		return root_prof;
	}
	else if(number < root_prof->number)
	{
		root_prof->left = insert_prof(root_prof->left, f_name, l_name, email, off_name, off_address, number);
		if(bf_prof(root_prof) == 2)
		{
			if(number < root_prof->left->number)     // nptr inserted to left of root_prof->left
			{
				return LL_prof(root_prof);
			}
			else
			{
				return LR_prof(root_prof);
			}
		}
	}
 	else
    {
		root_prof->right = insert_prof(root_prof->right, f_name, l_name, email, off_name, off_address, number);
  		if (bf_prof(root_prof) == 2)
  		{
   			if (number > root_prof->right->number)    // nptr inserted to right of root->right
    		{
    			return RR_prof(root_prof);
			}
   			else
    		{
    			return RL_prof(root_prof);
			}
  		}
    }
    root_prof->ht = height_prof(root_prof);
 	return root_prof;
}

//function's to display and also print as per the ascending and descending order

void inorder(struct pers * root)		// inoder traversal for personal (prints the data ascendingly with number(key) )
{
	if(root != NULL)
 	{
        inorder(root->left);
        printf("%s\t\t %s\t\t %s\t\t %d \n",root->f_name,root->l_name,root->email,root->number);
        inorder(root->right);
    }
}

void inorder_descending(struct pers* root)     // prints descendingly as per key(which is number in this case)
{
    if (root != NULL)
    {
      	inorder_descending(root->right);
       	printf("%s\t\t %s\t\t %s\t\t %d \n",root->f_name,root->l_name,root->email,root->number);
      	inorder_descending(root->left);
    }
}

void inorder_prof(struct prof * root_prof)    // inorder traversal for professional (prints the data ascendingly with number(key) )
{
	if(root_prof != NULL)
 	{
        inorder_prof(root_prof->left);
        printf("%s\t\t %s\t\t %s\t\t %s\t\t %s\t\t    %d\n",root_prof->f_name,root_prof->l_name,root_prof->email,
			root_prof->off_name,root_prof->off_address,root_prof->number);
		inorder_prof(root_prof->right);
    }
}

void inorder_descending_prof(struct prof* root_prof)     // prints descendingly as per key(which is number in this case)
{
    if (root_prof != NULL)
    {
      	inorder_descending_prof(root_prof->right);
      	printf("%s\t\t %s\t\t %s\t\t %s\t\t %s\t\t    %d\n",root_prof->f_name,root_prof->l_name,root_prof->email,
			root_prof->off_name,root_prof->off_address,root_prof->number);
		inorder_descending_prof(root_prof->left);
    }
}

//functions to find the min number(key)

struct pers* findmin(struct pers* root)			// finds the min number(key) in the node for personal
{
   	struct pers* retval;	
	if (root == NULL)
    {
    	retval = NULL;
	}
   	else if(root->left == NULL)
    {
    	retval = root;
	}
    else
    {
    	retval = findmin(root->left);
	}
	return retval;
}

struct prof* findmin_prof(struct prof* root_prof)		// finds the min number(key) in the node for professional
{
   	struct prof* retval;
	if (root_prof == NULL)
    {
    	retval = NULL;
	}
   	else if(root_prof->left == NULL)
    {
    	retval = root_prof;
	}
    else
    {
    	retval = findmin_prof(root_prof->left);
	}
	return retval;
}

//function's to delete list by number(key)   

struct pers* delete_pers(struct pers *root, int number)		 //delete's specific personal data by whole.
{
	int count = 0;
	struct pers *min;
	struct pers *ptr = root;
	
	if(ptr == NULL)										//if ptr is null prints the msg
	{
	  	printf("\nData was not found !!\n");
	  	return ptr;
	}
	else if( number < ptr->number)
	{
		ptr->left=delete_pers(ptr->left,number);
	}
	else if( number > ptr->number)
	{
		ptr->right=delete_pers(ptr->right,number);
	}
	else
	{
		if(ptr->left == NULL && ptr->right == NULL)
		{
			return NULL;
		}
		else if(ptr->right != NULL && ptr->left == NULL)     // if only right child exists
		{
			return ptr->right;
		}
		else if(ptr->left != NULL && ptr->right == NULL)     // if only left child exists
		{
			return ptr->left;
		}
		else
		{
			min = findmin(ptr->right);            //find the minimum element in right subtree
			strcpy (ptr->f_name, min->f_name);
			strcpy (ptr->l_name, min->l_name);
			strcpy (ptr->email, min->email);
			ptr->number = min->number;           // copy the minimum element value into the ptr
			ptr->right = delete_pers(ptr->right,min->number);  //delete the duplicate element
			count++;
			printf("%d contact is deleted\n",count);    //prints the msg to know deleted.
			return ptr;
		}
	  	ptr->ht = height(ptr);
	  	
	  	if (bf(ptr) >= 2 && ptr->left && ptr->left->left)		//calculates the bf and does the required adjustments
	    {
	    	return LL(ptr);
		}
	  	else if (bf(ptr) >= 2 && ptr->left && ptr->left->right)
	    {
	    	ptr = LR(ptr);
		}
	 
	  	else if (bf(ptr) >= 2 && ptr->right && ptr->right->right)
	    {
	    	return RR(ptr);
		}
	  	if (bf(ptr) >= 2 && ptr->right && ptr->right->left)
	  	{
	  		ptr = RL(ptr);	          
	   	} 
	}
}

struct prof* delete_prof(struct prof *root_prof, int number)	 //delete's specific personal data by whole.
{
	int count = 0;
	struct prof *min;
	struct prof *ptr = root_prof;
	
	if(ptr == NULL)						// if ptr is null prints the msg
	{
	  	printf("\nData was not found !!\n");		
	  	return ptr;
	}
	else if( number < ptr->number)
	{
		ptr->left=delete_prof(ptr->left,number);
	}
	else if( number > ptr->number)
	{
		ptr->right=delete_prof(ptr->right,number);
	}
	else
	{
		if(ptr->left == NULL && ptr->right == NULL)
		{
			return NULL;
		}
		else if(ptr->right != NULL && ptr->left == NULL)      // if only right child exists
		{
			return ptr->right;
		}
		else if(ptr->left != NULL && ptr->right == NULL)     // if only left child exists
		{
			return ptr->left;
		}
		else
		{
			min = findmin_prof(ptr->right);            //find the minimum element in right subtree
			strcpy (ptr->f_name, min->f_name);
			strcpy (ptr->l_name, min->l_name);
			strcpy (ptr->email, min->email);
			strcpy (ptr->off_name, min->off_name);
			strcpy (ptr->off_address, min->off_address);
			ptr->number = min->number;                         // copy the minimum element value into the ptr
			ptr->right = delete_prof(ptr->right,min->number);  //delete the element
			count++;
			printf("%d contact is deleted\n",count);    //prints the msg to know deleted.
			return ptr;
		}
	  	ptr->ht = height_prof(ptr);
	  	
	  	if (bf_prof(ptr) >= 2 && ptr->left && ptr->left->left)  //calculates the bf and does the required adjustments
	    {
	    	return LL_prof(ptr);
		}
	  	else if (bf_prof(ptr) >= 2 && ptr->left && ptr->left->right)
	    {
	    	ptr = LR_prof(ptr);
		}
	  	else if (bf_prof(ptr) >= 2 && ptr->right && ptr->right->right)
	    {
	    	return RR_prof(ptr);
		}
	  	if (bf_prof(ptr) >= 2 && ptr->right && ptr->right->left)
	  	{
	  		ptr = RL_prof(ptr);	          
	   	} 
	}
}

//functions to edit by number(key)

struct pers* edit_pers(struct pers* root, int number)	  //search's the number(key) and edit for personal data
{
	struct pers* list_ptr = root;
	char f_name[20], l_name[20], email[20];
	int count = 0;
	
	if(list_ptr == NULL)
	{
		printf("\nData was not found !!\n");
	}
	else if (number == list_ptr->number)		   //if the record found allows to edit that perticular record
	{
		printf("Enter First name to edit : \n");
		scanf("%s",f_name);
		printf("Enter Last name to edit : \n");
		scanf("%s",l_name);
		printf("Enter email id to edit : \n");
		scanf("%s",email);
		strcpy (list_ptr->f_name , f_name);
		strcpy (list_ptr->l_name , l_name);
		strcpy (list_ptr->email , email);
		count++;
		printf("%d contact is modified\n",count);    //prints the msg to know modified
	}
	else if (number < list_ptr->number)
	{
		edit_pers(list_ptr->left,number);
	}
	else if(number > list_ptr->number)
	{
		edit_pers(list_ptr->right,number);	
	}
	return root;
}

struct prof* edit_prof(struct prof* root_prof, int number)     //search's the number(key) and edit for professional data
{
	struct prof* list_ptr = root_prof;
	char f_name[20], l_name[20], email[20], off_name[20], off_address[20];
	int count = 0;
	
	if(list_ptr == NULL)
	{
		printf("\nData was not found !!\n");
	}
	else if (number == list_ptr->number)		//if the record found allows to edit that perticular record
	{
		printf("Enter First name to edit : \n");
		scanf("%s",f_name);
		printf("Enter Last name to edit : \n");
		scanf("%s",l_name);
		printf("Enter email id to edit : \n");
		scanf("%s",email);
		printf("Enter Office Name to edit: \n");
		scanf("%s",off_name);
		printf("Enter Office Address to edit: \n");
		scanf("%s",off_address);
		strcpy (list_ptr->f_name ,f_name);
		strcpy (list_ptr->l_name ,l_name);
		strcpy (list_ptr->email ,email);
		strcpy (list_ptr->off_name ,off_name);
		strcpy (list_ptr->off_address ,off_address);
		count++;
		printf("\n%d contact is modified\n",count);    //prints the msg to know modified
	}
	else if (number < list_ptr->number)
	{
		edit_prof(list_ptr->left,number);
	}
	else if(number > list_ptr->number)
	{
		edit_prof(list_ptr->right,number);	
	}
	return list_ptr;
}

//func to search particular record by giving the number(key)

void search_pers(struct pers* root, int number)      //personal
{
	int count=0;
	struct pers* retval;
	struct pers* ptr = root;
	
	if(ptr == NULL)
	{
	  	printf("\nData was not found !!\n");
	}
	else if (number == ptr->number)			//if the record found print's that perticular record
	{
		printf("\nFirst name : %s\n",ptr->f_name);
		printf("Last name : %s\n",ptr->l_name);
		printf("Email id : %s\n",ptr->email);
		printf("Personal number : %d\n",ptr->number);
		count++;
		printf("\n%d contact searched\n",count);    //prints the msg to know searched
	}
	else if (number < ptr->number)     //recursive call to search
	{
		search_pers(ptr->left,number);
	}
	else if(number > ptr->number)      //recursive call to search
	{
		search_pers(ptr->right,number);
	}		
}

void search_prof(struct prof* root_prof, int number)    //professional
{
	int count=0;
	struct prof* retval;
	struct prof* ptr = root_prof;
	
	if(ptr == NULL)
	{
	  	printf("\nData was not found !!\n");
	}
	else if (number == ptr->number)           //if the record found print's that perticular record
	{
		printf("\nFirst name : %s\n",ptr->f_name);
		printf("Last name : %s\n",ptr->l_name);
		printf("Email id : %s\n",ptr->email);
		printf("Office name : %s\n",ptr->off_name);
		printf("Office address : %s\n",ptr->off_address);
		printf("Office number : %d\n",ptr->number);
		count++;
		printf("%d contact searched\n",count);    //prints the msg to know searched
	}
	
	else if (number < ptr->number)       //recursive call to search
	{
		search_prof(ptr->left,number);
	}
	else if(number > ptr->number)        //recursive call to search
	{
		search_prof(ptr->right,number);
	}		
}

//range search functions

void range_print_pers(struct pers* ptr)    //fun to print that paticular value in the range (personal)
{
	printf("\nFirst name : %s\n",ptr->f_name);
	printf("Last name : %s\n",ptr->l_name);
	printf("Email id : %s\n",ptr->email);
	printf("Personal number : %d\n",ptr->number);
	printf("--------------------------------------\n");
}

void range_search_pers(struct pers* root, int start, int end)   //fun to search in the particular range (personal)
{
    if(root!=NULL)
    {
        range_search_pers(root->left,start,end);
        if(root->number>=start && root->number<=end)
        {
            range_print_pers(root);
        }
        range_search_pers(root->right,start,end);
    }
}

void range_print_prof(struct prof* ptr)     //fun to print that paticular value in the range (professional)
{
	printf("\nFirst name : %s\n",ptr->f_name);
	printf("Last name : %s\n",ptr->l_name);
	printf("Email id : %s\n",ptr->email);
	printf("Personal number : %d\n",ptr->number);
	printf("--------------------------------------\n");
}

void range_search_prof(struct prof* root, int start, int end)    //fun to search in the particular range (professional)
{
	if(root!=NULL)
    {
        range_search_prof(root->left,start,end);
        if(root->number>=start && root->number<=end)
        {
            range_print_prof(root);
        }
        range_search_prof(root->right,start,end);
    }
}

// main fun

int main()
{
	int i,choice, flag = 1;
	char f_name[20], l_name[20], email[20];
	char off_name[20];
	char off_address[20];
	int number;
	
	printf("Press 1. Personal \nPress 2. Professional \n");
	printf("Enter the choice to create : ");
	scanf("%d",&choice);
	
	if(choice == 1)
	{	
		int entry,flag = 1;
		struct pers *root = NULL;
		
		while(flag == 1)
		{
			printf("\nPress 1. To Insert / Add \nPress 2. Edit \nPress 3. Delete \nPress 4. Search \nPress 5. Sort \nPress 6. To Display \n");
			printf("Press 7. Range Search \nPress 8. Sort by f_name \n");
			scanf("%d",&entry);
			
			if(entry == 1 )     //to add (or) insert
			{ 
				int numnodes = 0;
				printf("enter number of elements\n");
			    scanf("%d",&numnodes);
		       	for(i=0;i<numnodes;i++)
		       	{
			        printf("first name : ");
					scanf("%s",f_name);
					printf("last name : ");
					scanf("%s",l_name);
					printf("email : ");
					scanf("%s",email);
					printf("personal number : ");
					scanf("%d",&number);
		
		        	root = insert_pers(root, f_name, l_name, email, number);		        	
		       	}
		       	printf("%d contacts are created\n",numnodes);
		      	printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if(entry == 2)     //edit by any field
			{	
				
				int e_byfield;
				printf("Enter the number(key) to edit : ");
				scanf("%d",&e_byfield);
				root = edit_pers(root, e_byfield);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);		
			}
			else if(entry == 3)         //delete by any field
			{
		       	int number;
				printf("Enter the number(key) to be deleted\n");
		       	scanf("%d",&number);
		       	root = delete_pers(root,number);
		       	printf("\ncontact deleted\n");
		       	printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if(entry == 4)
			{
				int s_byfield;
				printf("Enter number(key) to search : ");
				scanf("%d",&s_byfield);
				search_pers(root,s_byfield);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
				
			}
			else if(entry == 5)     //sorting based on key(which is number in this case )
			{	
				int order;
	            printf("Press 1. Ascending \nPress 2. Descending \n");
	            printf("Enter the choice : ");
	            scanf("%d",&order);
	        	if(order == 1)
	            {    
					printf("\nFirst name \t Last name \t Email id \t Personal number \n");
					inorder(root);
				}
				else if(order == 2)
				{
					printf("\nFirst name \t Last name \t Email id \t Personal number \n");
					inorder_descending(root);	
				}	
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if(entry == 6)         // full display
			{
				printf("\nFirst name \t Last name \t Email id \t Personal number \n");
				inorder(root);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);	
		    }
			else if(entry == 7)
			{
				int start, end;
				printf("Enter Start and End limits of number to do Range search : ");
				scanf("%d%d",&start,&end);
				range_search_pers(root, start, end);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if(entry == 8)
			{
				struct phonebook* phn_ptr;
				int num;
				printf("Enter number of phonebook records to be created : ");
				scanf("%d",&num);
//				phn_ptr = createlist_phonebook(num,phn_ptr);
//				printf("The phonebook data is : ");
//				display_phonebook(phn_ptr);
			}
			else
			{
				printf("\nEnter the Valid Input !!\n ");
			}		
		}
	}
	else if (choice == 2)
	{
		int entry,flag = 1;
		struct prof *root_prof = NULL;
		
		while(flag == 1)     
		{
			printf("\nPress 1. To Insert / Add \nPress 2. Edit \nPress 3. Delete \nPress 4. Search \nPress 5. Sort \nPress 6. To Display \n");
			printf("Press 7. Range Search \nPress 8. Sort by f_name \n");
			scanf("%d",&entry);
			
			if(entry == 1 )     //to add (or) insert
			{ 
				int numnodes = 0;
				printf("enter number of elements\n");
			    scanf("%d",&numnodes);
		       	for(i=0;i<numnodes;i++)
		       	{
			        printf("first name : ");
					scanf("%s",f_name);
					printf("last name : ");
					scanf("%s",l_name);
					printf("email : ");
					scanf("%s",email);
					printf("office name : ");
					scanf("%s",off_name);
					printf("office address : ");
					scanf("%s",off_address);
					printf("office number : ");
					scanf("%d",&number);
					
		        	root_prof = insert_prof(root_prof, f_name, l_name, email, off_name, off_address, number);	
		       	}
				printf("%d contacts are created\n",numnodes);
		      	printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if(entry == 2)          //edit by any field
			{			
				int e_byfield;
				printf("Enter the number(key) to edit : ");
				scanf("%d",&e_byfield);
				root_prof = edit_prof(root_prof, e_byfield);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);		
			}
			else if(entry == 3)          //delete by any field
			{
				int number;
				printf("Enter the number(key) to be deleted\n");
		       	scanf("%d",&number);
		       	root_prof = delete_prof(root_prof,number);
		       	printf("\ncontact deleted\n");
		       	printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if (entry == 4)         //search by any field
			{
				int s_byfield;
				printf("Enter number(key) to search : ");
				scanf("%d",&s_byfield);
				search_prof(root_prof,s_byfield);	
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if(entry == 5)   		  //sorted based on name if name is same then by number.
			{
				int order;
	            printf("Press 1. Ascending \nPress 2. Descending \n");
	            printf("Enter the choice : ");
	            scanf("%d",&order);
	        	if(order == 1)
	            {    
					printf("\nFirst name \t Last name \t Email id \t Office name \t Office address     Office number \n");
					inorder_prof(root_prof);
				}
				else if(order == 2)
				{
					printf("\nFirst name \t Last name \t Email id \t Office name \t Office address     Office number \n");
					inorder_descending_prof(root_prof);	
				}	
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);			
			}
			else if(entry == 6)           // full display
			{
				printf("\nFirst name \t Last name \t Email id \t Office name \t Office address     Office number \n");
				inorder_prof(root_prof);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);	
		    }	
			else if(entry == 7)
			{
				int start, end;
				printf("Enter Start and End limits of number to do Range search : ");
				scanf("%d%d",&start,&end);
				range_search_prof(root_prof, start, end);	
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			} 
			else if(entry == 8)
			{
				struct phonebook* phn_ptr;
				int num;
				printf("Enter number of phonebook records to be created : ");
				scanf("%d",&num);
//				phn_ptr = createlist_phonebook(num,phn_ptr);
//				printf("The phonebook data is : ");
//				display_phonebook(phn_ptr);
			}
			else
			{
				printf("\nEnter the Valid Input !!\n ");
			}							   
		}
	}
	return 0;
}
