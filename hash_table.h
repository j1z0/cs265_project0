#ifndef HASH_TABLE_GUARD
#define HASH_TABLE_GUARD
#define INIT_SIZE 20


typedef int keyType;
typedef int valType;

typedef struct keynode {
		valType value;
		keyType key;
		struct keynode *next;
} keynode;

typedef struct hashtable {
// define the components of the hash table here (e.g. the array, bookkeeping for number of elements, etc)
	    int size;
		keynode *storage[INIT_SIZE];
} hashtable;


void init(hashtable** ht);
void put(hashtable* ht, keyType key, valType value);
int get(hashtable* ht, keyType key, valType *values, int num_values);
void erase(hashtable* ht, keyType key);

#endif
