struct list
{
   void *p;  // list of items
   int  n;   // number of items in l
};
typedef struct list List;

struct node
{
    void *i; 	      // pointer to the item
    struct node *next; // pointer to the next item
};
typedef struct node Node;
