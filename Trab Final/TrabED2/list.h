//#include "list-definitions.h"

// listCreate
// ----------
// Create a list.
// Return a pointer to a list,
// or return NULL, in the case of malloc problem.
List * listCreate ();

// listDestroy
// -----------
// De-allocate the space memory used by l.
void listDestroy (List *l);

// listIns
// -------
// Insert i in the position p of l, such that p >= 1.
// If p > l->n, then i is inserted in the position l->n + 1.
//
// Return 1, if i was inserted in l at position p;
// or return 0, otherwise.
List * listIns(void *i,int p,List *l);

// listDel
// -------
// Delete the item pointed to by i from l
void listDel (void *i, List *l);

// listGetI
// --------
// Get the i-th item of l (i >= 1).
// Return the pointer to the i-th item of l;
// or return NULL, if i > l->N.
void * listGetI (List *l, int i);

// listSearch
// ----------
// Search for an item in l whose key matches to the one in k.
//
// Return a pointer to the item that matches k,
// or return NULL, if there was no match.
//
// cmp is a pointer to a comparison function provided by
// the application. This function returns 0, if x == y,
// or return a number != 0, otherwise.
void * listSearch (void *k, List *l, int (*cmp) (const void *x, const void *y));


// listSort
// --------
// Sort the content of l.
//
// Return a pointer to an ordered list whose items are the
// ones in l; or return NULL, if the new list could not be created.
//
// cmp is a pointer to a comparison function provided by
// the application. This function compares whether x is less than,
// equal to, or greater than y. It returns, respectively,
// a number less than, equal to, or greater than zero.
List * listSort (List *l, int (*cmp) (const void *x, const void *y));
