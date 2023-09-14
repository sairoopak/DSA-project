#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{TRUE,FALSE} boolean;

struct pers         // structure definition for personal
{	
	char f_name[20];
	char l_name[20];
	char email[20];
	char number[20];
	struct pers* next;
};

struct prof               // structure definition for professional
{	
	char f_name[20];
	char l_name[20];
	char email[20];
	char off_name[20];
	char off_address[20];
	char off_number[20];
	struct prof* next;
};

struct phonebook             // structure definition for phonebook
{
	char name[20];
	char mob_number[20];
	char address[20];
	int calls;
	int duration_in_min;
	struct phonebook* next;	
};

//  function to Insert/add

struct pers* createlist_pers(int num, struct pers* list_ptr)     //create list for personal
{
	struct pers* nptr;
	char f_name[20], l_name[20], email[20], number[20];
	int i;
	nptr= NULL;
	
	printf("Enter the personal contact deails : \n");
	for(i=1;i<=num;i++)
	{
		nptr = (struct pers*) malloc(sizeof(struct pers));
		printf("first name : ");
		scanf("%s",f_name);
		printf("last name : ");
		scanf("%s",l_name);
		printf("email : ");
		scanf("%s",email);
		printf("number : ");
		scanf("%s",number);
		strcpy( nptr->f_name , f_name);
		strcpy ( nptr->l_name , l_name);
		strcpy ( nptr->email ,email);
		strcpy (nptr->number , number);
		nptr->next = list_ptr;
		list_ptr = nptr;
	}
	printf("%d contacts are created\n",num);
	return list_ptr;
}

struct prof* createlist_prof(int num, struct prof* list_ptr)        //create list for professional
{
	struct prof* nptr;
	char f_name[20], l_name[20], email[20], off_name[20], off_address[20], off_number[20];
	int i;
	nptr= NULL;
	
	printf("Enter the professional contact deails : \n");
	for(i=1;i<=num;i++)
	{
		nptr = (struct prof*) malloc(sizeof(struct prof));
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
		scanf("%s",off_number);	
		strcpy(nptr->f_name , f_name);
		strcpy(nptr->l_name , l_name);
		strcpy(nptr->email , email);
		strcpy(nptr->off_name , off_name);
		strcpy(nptr->off_address , off_address);
		strcpy(nptr->off_number , off_number);
		nptr->next = list_ptr;
		list_ptr = nptr;
	}
	printf("%d contacts are created\n",num);
	return list_ptr;
}

// function's to display

void full_display_pers(struct pers* list_ptr)       // displays personal data
{
	printf("\nFirst name \t Last name \t Email id \t number \n");
	if(list_ptr == NULL)
	{
		printf("No data is there Enter any data to display !!\n");
	}
	else
	{	
		while(list_ptr != NULL)
		{
			printf("%s\t\t %s\t\t %s\t\t %s \n",list_ptr->f_name,list_ptr->l_name,list_ptr->email,list_ptr->number);
			list_ptr = list_ptr->next;
		}
	}
}

void full_display_prof(struct prof* list_ptr)       // displays professional data
{
	printf("\nFirst name \t Last name \t Email id \t Office name \t Office address \t Office number \t ");
	
	if(list_ptr == NULL)           //if list_ptr is null prints the msg
	{
		printf("No data is there Enter any data to display !!\n");
	}
	else
	{	
		while(list_ptr != NULL)         //displays if list_ptr is not null
		{
			printf("%s\t %s\t %s\t %s\t %s\t %s\t",list_ptr->f_name,list_ptr->l_name,list_ptr->email,
			list_ptr->off_name,list_ptr->off_address,list_ptr->off_number);
			
			list_ptr = list_ptr->next;
		}
	}	
}

//function's to delete list by field

struct pers* deletelist_pers_byfield(struct pers* list_ptr, char del_byfield[20])   //delete's specific personal data by whole.
{
	struct pers *ptr, *temp = list_ptr->next;
	struct pers *prev ;
	struct pers* nochange_ptr = list_ptr;
	int count=0;
	
	if(list_ptr == NULL)        //if list_ptr is null prints the msg
	{
		printf("\nLinked list is NULL Enter any data to delete !!\n");
	}
	else
	{
		if((strcmp(list_ptr->f_name,del_byfield) ==0) || (strcmp(list_ptr->l_name,del_byfield)== 0)
		 || (strcmp(list_ptr->email,del_byfield) == 0)                
		 || (strcmp(list_ptr->number, del_byfield) == 0))     //if the entered feild is the first node to delete in linked list.
		{	
			ptr = list_ptr;
			list_ptr = list_ptr->next;
			free(ptr);
			return list_ptr;
			count++;
			if(count>0)
			{	printf("%d contact is deleted\n",count);
			}
			else
			{	printf("contact not found\n");
			}
		}
		else
		{	
			while(temp != NULL )         //traverse the linklist and delete the specific field as whole if list_ptr is not null
			{	
				if((strcmp(temp->f_name,del_byfield) == 0) || (strcmp(temp->l_name,del_byfield) == 0)
					 || (strcmp(temp->email,del_byfield) == 0) || (strcmp(list_ptr->number, del_byfield) == 0) )
				{	
					prev = list_ptr;
					prev->next = temp->next;
					ptr = temp;	
					temp = temp->next;
					list_ptr = list_ptr->next;
					free(ptr);
					count++;
				}
				else
				{	prev = list_ptr;
					temp = temp->next;
					list_ptr = list_ptr->next;
				}
			}
			return nochange_ptr;
			if(count>0)
			{	printf("%d contact is deleted\n",count);
			}
			else
			{	printf("contact not found\n");
			}
		}
	}
	
}

struct prof* deletelist_prof_byfield(struct prof* list_ptr, char del_byfield[20])  ////delete's specific professional data by whole.
{
	struct prof *ptr, *temp = list_ptr->next;
	struct prof *prev;
	struct prof* nochange_ptr = list_ptr;
	int count=0;
	
	if(list_ptr == NULL)    //if list_ptr is null prints the msg
	{
		printf("\nLinked list is NULL Enter any data to delete !!\n");
	}
	else
	{	
		if((strcmp(list_ptr->f_name,del_byfield) ==0) || (strcmp(list_ptr->l_name,del_byfield) ==0) ||(strcmp(list_ptr->email,del_byfield) ==0) 
		   	|| (strcmp(list_ptr->off_name,del_byfield) == 0) || (strcmp(list_ptr->off_address,del_byfield) == 0) 
		   	|| (strcmp(list_ptr->off_number, del_byfield) == 0)) 
			   
			    //if the entered feild is the first node to delete in linked list.
		{
			ptr = list_ptr;
			list_ptr = list_ptr->next;
			free(ptr);
			return list_ptr;
			count++;
			
			if(count>0)
			{	printf("%d contact is deleted\n",count);    //prints the msg to know deleted.
			}
			else
			{	printf("contact not found\n");
			}
		}
		else
		{
			while(temp != NULL )     //traverse the linklist and delete the specific field as whole if list_ptr is not null
			{	
				if((strcmp(temp->f_name,del_byfield) == 0) || (strcmp(temp->l_name,del_byfield) == 0) || (strcmp(temp->email,del_byfield) == 0)
				 || (strcmp(temp->off_name,del_byfield) == 0) ||(strcmp(temp->off_address,del_byfield) == 0)
				 || (strcmp(list_ptr->off_number,del_byfield) == 0))
				 
				{	
					prev = list_ptr;
					prev->next = temp->next;
					ptr = temp;	
					temp = temp->next;
					list_ptr = list_ptr->next;
					free(ptr);
					count++;
				}
				else        //if not found it will traverse       
				{	
					prev = list_ptr;
					temp = temp->next;
					list_ptr = list_ptr->next;
				}
			}
			
			if(count>0)
			{	printf("%d contact is deleted\n",count);    //prints the msg to know deleted.
			}
			else
			{	printf("contact not found\n");
			}
			return nochange_ptr;	
		}
	}
}

//function to search and display that whole field 

void search_byfield_pers(struct pers* list_ptr , char byfield[20])    //search by feild for personal
{
	int count=0;
	
	if(list_ptr == NULL)   
	{
		printf("\nLinked list is NULL Enter any data to search !!\n");
	}
	else
	{	
		while(list_ptr!=NULL)      //traverse the list if found prints the whole field
		{	
			if((strcmp(list_ptr->f_name,byfield) == 0) || (strcmp(list_ptr->l_name,byfield) == 0)
				|| (strcmp(list_ptr->email,byfield) == 0) || (strcmp(list_ptr->number,byfield) == 0))
			{	
				printf("First name : %s\n",list_ptr->f_name);
				printf("Last name : %s\n",list_ptr->l_name);
				printf("Email id : %s\n",list_ptr->email);
				printf("Personal number : %s\n",list_ptr->number);
				list_ptr = list_ptr->next;
				count++;
			}	
			else
			{	list_ptr = list_ptr->next;
			}
		}
		if(count>0)
		{	printf("%d contact searched\n",count);    //prints the msg to know searched
		}
		else
		{	printf("contact not found\n");
		}
	}	
}

void search_byfield_prof(struct prof* list_ptr , char byfield[20])  //search by feild for professional
{
	int count=0;
	
	if(list_ptr == NULL)
	{
		printf("\nLinked list is NULL Enter any data to search !!\n");
	}
	else
	{	
		while(list_ptr!=NULL)         //traverse the list if found prints the whole field
		{	
			if( strcmp(list_ptr->f_name,byfield) == 0  || (strcmp(list_ptr->l_name,byfield) == 0) || (strcmp(list_ptr->email,byfield) == 0) || 
		  (strcmp(list_ptr->off_name,byfield) == 0) || (strcmp(list_ptr->off_address,byfield) == 0) || (strcmp(list_ptr->off_number,byfield) == 0))
			{	
				printf("First name : %s\n",list_ptr->f_name);
				printf("Last name : %s\n",list_ptr->l_name);
				printf("Email id : %s\n",list_ptr->email);
				printf("Office name : %s\n",list_ptr->off_name);
				printf("Office address : %s\n",list_ptr->off_address);
				printf("Office number : %s\n",list_ptr->off_number);
				list_ptr = list_ptr->next;
				count++;
			}	
			else                                
			{	list_ptr = list_ptr->next;
			}
		}
		
		if(count>0)
		{	printf("%d contact searched\n",count);     //prints the msg to know searched
		}
		else
		{	printf("contact not found\n");
		}
	}
}
 
//functions to edit by field

void search_to_edit_pers_byfield(struct pers* list_ptr, char byfield[20])   //search the field and edit for personal data
{
	int count=0;
	
	if(list_ptr == NULL)
	{
		printf("\nLinked list is NULL Enter any data to edit !!\n");
	}
	else
	{
		while(list_ptr!=NULL)    //traverse the field if found edit by whole field
		{	
			if((strcmp(list_ptr->f_name,byfield) == 0) || (strcmp(list_ptr->l_name,byfield) == 0)
					|| (strcmp(list_ptr->email,byfield) == 0) || (strcmp(list_ptr->number,byfield) == 0) )
			{	
				printf("Enter First name to edit : \n");
				scanf("%s",list_ptr->f_name);
				printf("Enter Last name to edit : \n");
				scanf("%s",list_ptr->l_name);
				printf("Enter Email id to edit : \n");
				scanf("%s",list_ptr->email);
				printf("Enter Personal number to edit: \n");
				scanf("%s",list_ptr->number);
				list_ptr = list_ptr->next;
				count++;
			}	
			else
			{	
				list_ptr = list_ptr->next;
			}
		}
		if(count>0)
		{	printf("%d contact is modified\n",count);  //prints the msg to know modified
		}
		else
		{	printf("contact was not found\n");
		}
	}
}

void search_to_edit_prof_byfield(struct prof* list_ptr, char byfield[20])    //search the field and edit for professional data
{
	int count=0;
	
	if(list_ptr == NULL)
	{
		printf("\nLinked list is NULL Enter any data to edit !!\n");
	}
	else
	{
		while(list_ptr!=NULL)       //traverse the field if found edit by whole field
		{	
			if(strcmp(list_ptr->f_name,byfield) == 0  || (strcmp(list_ptr->l_name,byfield) == 0) || (strcmp(list_ptr->email,byfield) == 0)
			 	|| (strcmp(list_ptr->off_name,byfield) == 0) || (strcmp(list_ptr->off_address,byfield) == 0)
		   		|| (strcmp(list_ptr->off_number,byfield) == 0))
	 		{	
				printf("Enter First name to edit : \n");
				scanf("%s",list_ptr->f_name);
				printf("Enter Last name to edit : \n");
				scanf("%s",list_ptr->l_name);
				printf("Enter Email id to edit : \n");
				scanf("%s",list_ptr->email);
				printf("Enter Office Name to edit: \n");
				scanf("%s",list_ptr->off_name);
				printf("Enter Office Address to edit: \n");
				scanf("%s",list_ptr->off_address);
				printf("Enter Office Number to edit: \n");
				scanf("%s",list_ptr->off_number);
				
				list_ptr = list_ptr->next;
				count++;
			}	
			else
			{	
				list_ptr = list_ptr->next;
			}
		}
		if(count>0)
		{	printf("%d contact is modified\n",count);    //prints the msg to know modified
		}
		else
		{	printf("contact was not found\n");
		}
	}
}

//funtions to sort

boolean compare_pers(struct pers*first, struct pers* second)   //compares the names/number if they are in decending order returns true
{                                                              // for personal.
  	if(strcmp(first->f_name,second->f_name) < 0)   //if order is correct returns true
  	{
    	return TRUE;
  	}
  	else if(strcmp(first->f_name,second->f_name) == 0)   //if f_name is same check for l_name
	{ 
		if(strcmp(first->l_name, second->l_name) < 0)
    	{
        	return TRUE;
    	}
    	else if(strcmp(first->l_name, second->l_name) == 0)   //if l_name is also same then sort by number.
    	{    
        	if(strcmp(first->number,second->number) < 0 )   //if names are same sort by number.
        	{
          		return TRUE;
        	}
  		}
	}
  	return FALSE;
}

struct pers* sorted_merge_pers(struct pers* a, struct pers* b)
{
    if (a == NULL)        // base cases
	{
        return b;
    }
    else if (b == NULL) 
	{
        return a;
    }	
	struct pers* result = NULL;
 	
	if(compare_pers(a,b))          // pick either 'a or 'b and recur
    {
        result = a;
        result->next = sorted_merge_pers(a->next,b);
    }
    else 
	{
        result = b;
        result->next = sorted_merge_pers(a,b->next);
    }
    return result;
}

void split_pers(struct pers* source, struct pers** front_ref, struct pers** backRef)    //split by halfs
{
    if(source == NULL || source->next == NULL)      // if the length is less than 2,it will handled separately.
    {
        *front_ref = source;
        *backRef = NULL;
        return;
    }
 
    struct pers* slow = source;
    struct pers* fast = source->next;
 
    while (fast != NULL)           // advance fast two nodes, and advance slow one node
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front_ref = source;           // slow is before the midpoint in the linked list, so split it in two at that point.
    *backRef = slow->next;
    slow->next = NULL;
}

struct pers* mergesort_pers(struct pers* head)
{
    if (head == NULL || (head)->next == NULL)       // base case.
	{
        return head;
    }
    struct pers* a;
    struct pers* b;
 
    split_pers(head, &a, &b);       // splits the 'head' into two sublists 'a and 'b'.
 
    mergesort_pers(a);           // recursively sort the sublists.
    mergesort_pers(b);
 
    return sorted_merge_pers(a,b);     // merges the two sorted link lists
}


//////////////////////////////////////////////////////////////////////////////////professional


boolean compare_prof(struct prof*first, struct prof* second)   //compares the names/number if they are in decending order returns true
{															  //for professional data.
  	if(strcmp(first->f_name,second->f_name) < 0)   //if order is correct returns true
  	{
    	return TRUE;
  	}
  	else if(strcmp(first->f_name,second->f_name) == 0)  //if f_name is same check for l_name
	{ 
		if(strcmp(first->l_name, second->l_name) < 0)
    	{
        	return TRUE;
    	}
    	else if(strcmp(first->l_name, second->l_name) == 0)     //if l_name is also same then sort by number.
    	{    
        	if(strcmp(first->off_number,second->off_number) < 0 )    //if names are same sort by number.
        	{
          		return TRUE;
        	}
  		}
	}
  	return FALSE;
}

struct prof* sorted_merge_prof(struct prof* a, struct prof* b)
{
    if (a == NULL)       // base cases
	{
        return b;
    }
    else if (b == NULL) 
	{
        return a;
    }
 	
	struct prof* result = NULL;
 	
	if(compare_prof(a,b) )          // pick either 'a or 'b and recur
    {
        result = a;
        result->next = sorted_merge_prof(a->next, b);
    }
    else 
	{
        result = b;
        result->next = sorted_merge_prof(a, b->next);
    }
    return result;
}
 
void split_prof(struct prof* source, struct prof** front_ref, struct prof** back_ref)   //split by halfs
{
    if(source == NULL || source->next == NULL)      // if the length is less than 2,it will handled separately.
    {
        *front_ref = source;
        *back_ref = NULL;
        return;
    }
 
    struct prof* slow = source;
    struct prof* fast = source->next;
 
    while (fast != NULL)           // advance fast two nodes, and advance slow one node
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front_ref = source;           // slow is before the midpoint in the linked list, so split it in two at that point.
    *back_ref = slow->next;
    slow->next = NULL;
}

struct prof* mergesort_prof(struct prof* head)
{
    if (head == NULL || (head)->next == NULL)       // base case.
	{
        return head;
    }
 
    struct prof* a;
    struct prof* b;
 
    split_prof(head, &a, &b);       // splits the 'head' into two sublists 'a and 'b'.
 
    mergesort_prof(a);            // recursively sort the sublists.
    mergesort_prof(b);
 
    return sorted_merge_prof(a, b);     // merges the two sorted link lists
}

//functions to print in ascending order 

void ascending_pers(struct pers* list_ptr)   //for personal data
{ 
    if (list_ptr == NULL)     // Base case
   	    return;
 
    ascending_pers(list_ptr->next);          //calls recursively
	      
	printf("%s\t\t %s\t\t %s\t\t %s \n",list_ptr->f_name,list_ptr->l_name,list_ptr->email,list_ptr->number);
}

void ascending_prof(struct prof* list_ptr)   //for professional data
{ 
    if (list_ptr == NULL)     // Base case
   	    return;
 
    ascending_prof(list_ptr->next);           //calls recursively
	      
	printf("%s\t %s\t %s\t %s\t %s\t %s\t",list_ptr->f_name,list_ptr->l_name,list_ptr->email,
			list_ptr->off_name,list_ptr->off_address,list_ptr->off_number);
}

//functions to remove duplicates

void remove_duplicate_pers(struct pers* list_ptr)    //removes duplicates in personal data
{
    struct pers* current = list_ptr;
    struct pers* next_next;
    int count=0;
    
    if (current == NULL)         //if empty linked list is called prints the msg.
    {
    	printf("The link list is empty !! enter any data to remove duplicates\n");
	}
	else
	{
	    while (current->next != NULL)      //travese the link list if any duplicates found removes it.
	    {	
	        if((strcmp(current->f_name,current->next->f_name) == 0) && (strcmp(current->l_name,current->next->l_name) == 0)
				&& (strcmp(current->email,current->next->email) == 0) && (strcmp(current->number,current->next->number) == 0) )
	        {          
	           next_next = current->next->next;
	           free(current->next);
	           current->next = next_next; 
	           count++;
	        }
	        else                        
	        {
			  	current = current->next;
	       	}
	    }
	    
		if(count >0)         //prints the msg if duplicates are found.
		{
			printf("%d duplicates are found\n",count);    
		}
		else if(count == 0)
		{
			printf("No Duplicates are found\n");   
		}
	}
}

void remove_duplicate_prof(struct prof* list_ptr)   //removes duplicates in professional data
{
    struct prof* current = list_ptr;
    struct prof* next_next;
    int count=0;
    
    if (current == NULL)         //if empty linked list is called prints the msg.
    {
    	printf("The link list is empty !! enter any data to remove duplicates\n");
	}
	else
	{
	    while (current->next != NULL)	  //travese the link list if any duplicates found  removes it.
	    {	
	        if((strcmp(current->f_name,current->next->f_name) == 0) && (strcmp(current->l_name,current->next->l_name) == 0)
			&& (strcmp(current->email,current->next->email) == 0) && (strcmp(current->off_name,current->next->off_name) == 0 )
			&& (strcmp(current->off_address,current->next->off_address) == 0 ) && (strcmp(current->off_number,current->next->off_number) == 0) )
	        {          
	           next_next = current->next->next;
	           free(current->next);
	           current->next = next_next; 
	           count++;
	        }
	        else 
	        {
			  	current = current->next;
	       	}
	    }
	    
		if(count >0)           //prints the msg if duplicates are found.
		{
			printf("%d duplicates are found\n",count);   
		}
		else if(count == 0)
		{
			printf("No Duplicates are found\n");   
		}
	}
}

//function to merge two linked lists (union) 

struct pers* union_pers(struct pers* p1, struct pers* p2)      //function for personal data.
{
	struct pers* ptr = p1;
	
	if((p1 == NULL) && (p2 == NULL) )         //if both p1 and p2 are null.
	{
		ptr = NULL;
	}
	else if((p1 == NULL) && (p2->next == NULL) )   //if p1 is null and p2 having 1 node.
	{
		ptr = p2;
	}
	else if((p1 != NULL) && (p2 != NULL))
	{
		while(p1->next != NULL)   //will handle for case1: p1 one node and p2 null and case2: p1 and p2 both are not null			
		{
			p1 = p1->next;
		}
		p1->next = p2;
	}
	return ptr;	
}

struct prof* union_prof(struct prof* p1, struct prof* p2)    //function for professional data.
{
	struct prof* ptr = p1;
		
	if((p1 == NULL) && (p2 == NULL) )        // both p1 and p2 are null
	{
		ptr = NULL;
		printf("\nBoth lists are NULL!! enter any data to union two linked lists \n");
	}
	else if((p1 == NULL) && (p2->next == NULL) )   // p1 is null and p2 having 1 node
	{
		ptr = p2;
	}
	else if((p1 != NULL) && (p2 != NULL))
	{
		while(p1->next != NULL)   // p1 one node and p2 null and p1 and p2 both are not null.			
		{
			p1 = p1->next;
		}
		p1->next = p2;
	}
	return ptr;	
}

//phonebook create list

struct phonebook* createlist_phonebook(int num, struct phonebook* list_ptr)     //create list for phonebook
{
	struct phonebook* nptr;
	char name[20], mob_number[20], address[20];
	int i,calls,duration_in_min;
	nptr= NULL;
	
	printf("Enter the phonebook deails : \n");
	for(i=1;i<=num;i++)
	{
		nptr = (struct phonebook*) malloc(sizeof(struct phonebook));
		printf("Name : ");
		scanf("%s",name);
		printf("Mobile number : ");
		scanf("%s",mob_number);
		printf("Address : ");
		scanf("%s",address);
		strcpy(nptr->name , name);
		strcpy(nptr->mob_number ,mob_number);
		strcpy(nptr->address , address);
		printf("No.of calls : ");
		scanf("%d",&calls);
		printf("Duration of each phone call : ");
		scanf("%d",&duration_in_min);
		nptr->next = list_ptr;
		list_ptr = nptr;
	}
	printf("%d phonebook records are created\n",num);
	return list_ptr;
}

// displays phonebook data

void display_phonebook(struct phonebook* list_ptr)       // displays phonebook data
{
	printf("\nName \t Mobile number \t Address \t No.of Calls \t Duration of each call in min \n");
	if(list_ptr == NULL)
	{
		printf("No data is there in phonebook enter any data to display !!\n");
	}
	else
	{	
		while(list_ptr != NULL)
		{
			printf("%s\t %s\t\t %s\t %d\t\t %d \n",list_ptr->name,list_ptr->mob_number,list_ptr->address,list_ptr->calls,list_ptr->duration_in_min);
			list_ptr = list_ptr->next;
		}
	}
}

//main function.
int main()
{
	struct pers* pers_ptr = NULL;
	int choice, cont;
	printf("Press 1. Personal \nPress 2. Professional \n");
	printf("Enter the choice to create : ");
	scanf("%d",&choice);
	
	if(choice == 1)
	{	
		int entry,flag = 1;	
		while(flag == 1)
		{
			printf("\nPress 1. To Insert / Add \nPress 2. Edit \nPress 3. Delete \nPress 4. Search \nPress 5. Sort \nPress 6. To Display \n");
			printf("Press 7. Union \nPress 8. Remove Duplicates \nPress 9. Phonebook \n");
			scanf("%d",&entry);
			
			if(entry == 1 )     //to add (or) insert
			{	
				int numnodes;
				printf("Enter the number of contacts to be created : ");
				scanf("%d",&numnodes);
			
				pers_ptr = createlist_pers(numnodes,pers_ptr);
					
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if(entry == 2)     //edit by any field
			{	
				char e_byfield[20];
				printf("Enter the any field to edit : ");
				scanf("%s",e_byfield);
				search_to_edit_pers_byfield(pers_ptr, e_byfield);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);		
			}
			else if(entry == 3)         //delete by any field
			{	
				char del_byfield[20];
				printf("Enter the field to delete : ");
				scanf("%s",del_byfield);
				pers_ptr = deletelist_pers_byfield(pers_ptr,del_byfield);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);	
			}
			else if (entry == 4)        //search by any field
			{
				char s_byfield[20];
				printf("Enter any feild to search : ");
				scanf("%s",s_byfield);
				search_byfield_pers(pers_ptr,s_byfield);	
				
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if(entry == 5)        //sorted based on name if name is same then by number.
			{
				int order;
                printf("Press 1. Ascending \nPress 2. Descending \n"); 
                printf("Enter the choice : ");
                scanf("%d",&order);
                
                if(order == 1)
                {
                	pers_ptr= mergesort_pers(pers_ptr);
                	printf("\nFirst name \t Last name \t Email id \t number \n");
                	ascending_pers(pers_ptr);
				}
				else if(order == 2)
				{
					pers_ptr= mergesort_pers(pers_ptr);
					full_display_pers(pers_ptr);
				}
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);				
			}
			else if(entry == 6)         // full display
			{
				full_display_pers(pers_ptr);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);	
		    }
		    else if(entry ==7)         //to merge linked lists (union).
		    {
		    	struct pers *p2, *union_pers_ptr;
		    	int numnodes;
				printf("Enter the number of contacts to be create another linked list : ");
				scanf("%d",&numnodes);
		    	p2 = createlist_pers(numnodes,p2);
		    	
		    	printf("\nThe Second Linklist is : \n");
		    	full_display_pers(p2);
		    	
		    	p2= mergesort_pers(p2);
		    	printf("\nThe sorted linked list is : \n");
            	printf("\nFirst name \t Last name \t Email id \t number \n");
            	full_display_pers(p2);
            	
            	pers_ptr = mergesort_pers(pers_ptr);
            	union_pers_ptr = union_pers(pers_ptr,p2);
            	union_pers_ptr = mergesort_pers(union_pers_ptr);
            	printf("\nThe sorted order of union of two linked lists is : \n"); 
            	full_display_pers(union_pers_ptr); 
            	printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);			    		
			}
			else if(entry == 8)       // remove's duplicates.
			{
				pers_ptr= mergesort_pers(pers_ptr);
				remove_duplicate_pers(pers_ptr);	
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);	
			} 
			else if(entry == 9)
			{
				struct phonebook* phn_ptr;
				int num;
				printf("Enter number of phonebook records to be created : ");
				scanf("%d",&num);
				phn_ptr = createlist_phonebook(num,phn_ptr);
				printf("The phonebook data is : ");
				display_phonebook(phn_ptr);
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
		struct prof* prof_ptr = NULL;
		
		while(flag == 1)     
		{
			printf("Press 1. To Insert / Add \nPress 2. Edit \nPress 3. Delete \nPress 4. Search \nPress 5. Sort \nPress 6. To Display \n");
			printf("Press 7. Union \nPress 8. Remove Duplicates \nPress 9. Phonebook \n");
			scanf("%d",&entry);
			
			if(entry == 1 )         //to add (or) insert
			{
				int numnodes;
				printf("Enter the number of contacts to be created : ");
				scanf("%d",&numnodes);
			
				prof_ptr = createlist_prof(numnodes,prof_ptr);
				
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if(entry == 2)          //edit by any field
			{			
				char e_byfeild[20];
				printf("Enter any field to edit : ");
				scanf("%s",e_byfeild);
				search_to_edit_prof_byfield(prof_ptr, e_byfeild);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);		
			}
			else if(entry == 3)          //delete by any field
			{
				char del_byfield[20];
				printf("Enter any field to delete : ");
				scanf("%s",del_byfield);
				prof_ptr = deletelist_prof_byfield(prof_ptr,del_byfield);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);
			}
			else if (entry == 4)         //search by any field
			{
				char s_byfield[20];
				printf("Enter any feild to search : ");
				scanf("%s",s_byfield);
				search_byfield_prof(prof_ptr,s_byfield);	
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
                	prof_ptr= mergesort_prof(prof_ptr);
                	printf("\nFirst name \t Last name \t Email id \t Office name \t Office address \t Office number \t ");
                	ascending_prof(prof_ptr);
				}
				else if(order == 2)
				{
					prof_ptr= mergesort_prof(prof_ptr);
					full_display_prof(prof_ptr);
				}
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);				
			}
			else if(entry == 6)           // full display
			{
				full_display_prof(prof_ptr);
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);	
		    } 
		    else if(entry == 7)           //to merge linked lists (union).
		    {
		    	struct prof *p2, *union_prof_ptr;
		    	int numnodes;
				printf("\nEnter the number of contacts to be create another linked list : ");
				scanf("%d",&numnodes);
		    	p2 = createlist_prof(numnodes,p2);
		    	
		    	printf("\nThe Second Linklist is : \n");
		    	full_display_prof(p2);
		    	
		    	p2= mergesort_prof(p2);
		    	printf("\nThe sorted linked list is : \n");
            	printf("\nFirst name \t Last name \t Email id \t number \n");
            	full_display_prof(p2);
            	
            	prof_ptr = mergesort_prof(prof_ptr);
            	union_prof_ptr = union_prof(prof_ptr,p2);
            	union_prof_ptr = mergesort_prof(union_prof_ptr);
            	printf("\nThe sorted order of union of two linked lists is : \n");  
            	full_display_prof(union_prof_ptr);		    	
		    	
			}
			else if(entry == 8)        // remove's duplicates.
			{
				prof_ptr= mergesort_prof(prof_ptr);
				remove_duplicate_prof(prof_ptr);	
				printf("\nTo continue press 1 or press 0 : ");
				scanf("%d",&flag);	
			}
			else if(entry == 9)
			{
				struct phonebook* phn_ptr;
				int num;
				printf("Enter number of phonebook records to be created : ");
				scanf("%d",&num);
				phn_ptr = createlist_phonebook(num,phn_ptr);
				printf("The phonebook data is : ");
				display_phonebook(phn_ptr);
			}
			else
			{
				printf("\nEnter the Valid Input !!\n ");
			}							
		}	
	}	
	return 0;
}

