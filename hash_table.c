#include "hash_table.h"
#include "stdio.h"
#include "stdlib.h"

// initialize the components of the hashtable
void init(hashtable** ht) {
    // This line tells the compiler that we know we haven't used the variable
    // yet so don't issue a warning. You should remove this line once you use
    // the parameter.
	//(*ht)->size = INIT_SIZE;
	//(void) ht;
	*ht = malloc( (size_t) sizeof(hashtable));
	(*ht)->size = INIT_SIZE;
	for(int i = 0; i < INIT_SIZE; ++i) {
			(*ht)->storage[i] = NULL;
	}
}


int hash(hashtable* ht, keyType key) {
	   int idx = key % ht->size;	
	   return idx;
}

keynode* create_node(keyType key, valType value)
{
    keynode *newnode = (keynode *)malloc(sizeof(keynode));
    if (newnode == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        newnode->value = value;
		newnode->key = key;
        newnode->next = NULL;
        return newnode;
    }
}


// insert a key-value pair into the hash table
void put(hashtable* ht, keyType key, valType value) {
	int idx = hash(ht, key);
	keynode * new_node = create_node(key, value);
	// printf("new_node is %d->%d\n",  new_node->key, new_node->value);
	// printf("hash is %d\n", idx);

	if (ht->storage[idx] == NULL) {
			// printf("we the first\n");
			ht->storage[idx] = new_node;
	} else {// put us at the end
			// printf("not the first\n");
			keynode *cur = ht->storage[idx];
			// printf("first node is %d ->  %d\n", cur->key, cur->value);
		   while (cur->next != NULL) {
			   cur = cur->next;	   
			   // printf("next node is %d ->  %d\n", cur->key, cur->value);
		   }
		   // printf("got it\n");
		   // printf("final node is %d - %d\n", cur->key, cur->value);
		   cur->next = new_node;
	}
	
	/*insert in front
	if (ht->storage[idx] != NULL) {
			new_node->next = ht->storage[idx];
	}
			
	ht->storage[idx] = create_node(value);
	*/
}

int get_all_nodes(keyType key, valType *values, int num_values, keynode *first) {
	(void) num_values;
	keynode *cur = first;
	int found = 0;
	while (cur != NULL) {
		// printf("cur node value is %d\n", cur->value);
		if (cur->key == key) {
			// if found > num_values;
		    values[found] = cur->value;
			found ++;
		}
	    cur = cur->next;
	}
	// printf("no more");
	return found;
}


// get entries with a matching key and stores the corresponding values in the
// values array. The size of the values array is given by the parameter
// num_values. If there are more matching entries than num_values, they are not
// stored in the values array to avoid a buffer overflow. The function returns
// the number of matching entries. If the return value is greater than
// num_values, the caller can invoke this function again (with a larger buffer)
// to get values that it missed during the first call. 
int get(hashtable* ht, keyType key, valType *values, int num_values) {
    //(void) ht;
    //(void) key;
    //(void) values;
    //(void) num_values;
	int idx = hash(ht, key);
	// printf("in get idx is %d", idx);
	// printf("there we got %d", ht->storage[idx]->value);
	if (ht->storage[idx] == NULL){
			// printf("key not found -1");
			return -1;
    }

	int num_nodes = get_all_nodes(key, values, num_values, ht->storage[idx]);
	/*if (num_nodes <= num_values) {
			for (int j = 0 ; j < num_nodes; j++) {
					values[j] = all_vals[j];
			}
	} else { // to much to return
	}
	*/
	return num_nodes;




    return 0;
}

// erase a key-value pair from the hash talbe
void erase(hashtable* ht, keyType key) {
    (void) ht;
    (void) key;
}
