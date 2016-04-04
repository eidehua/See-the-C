//This is a circularly-linked list 

//Usually a linked list contains the items that are to be linked. For example:
struct my_list{
	void *myitem;
	struct my_list *next;
	struct my_list *prev;
	};
//Kernel implementation:
struct my_cool_list{
	struct list_head list; /* kernel's list structure */
	int my_cool_data;
	void* my_cool_void;
	};
//reference: https://isis.poly.edu/kulesh/stuff/src/klist/
