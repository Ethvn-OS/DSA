#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 11   // small to make collisions more likely
#define EMPTY -1
#define DELETED -2

typedef struct {
    int keys[TABLE_SIZE];
} HashTable;

// Function prototypes
bool search(HashTable ht, int key);
void removeKey(HashTable *ht, int key);
void reinsertLostKeys(HashTable *ht);
void initTable(HashTable *ht);
int hash(int key);
void insert(HashTable *ht, int key);
void display(HashTable ht);

int main() {
    HashTable galaxy;
    initTable(&galaxy);

    printf("🚀 Inserting ship IDs...\n");
    insert(&galaxy, 22);
    insert(&galaxy, 33);
    insert(&galaxy, 44);
    insert(&galaxy, 55);
    insert(&galaxy, 66);
    insert(&galaxy, 77);
    insert(&galaxy, 88);
    display(galaxy);

    printf("\n🔍 Searching for some ships...\n");
    printf("Search 55 → %s\n", search(galaxy, 55) ? "Found" : "Not found");
    printf("Search 99 → %s\n", search(galaxy, 99) ? "Found" : "Not found");

    printf("\n💥 Removing some ships...\n");
    removeKey(&galaxy, 33);
    removeKey(&galaxy, 77);
    display(galaxy);

    printf("\n🔍 Rechecking after deletion...\n");
    printf("Search 33 → %s\n", search(galaxy, 33) ? "Found" : "Not found");
    printf("Search 77 → %s\n", search(galaxy, 77) ? "Found" : "Not found");

    printf("\n🛰️ Inserting new ship (99)...\n");
    insert(&galaxy, 99);
    display(galaxy);

    printf("\n🌌 Reinserting lost keys (clean up DELETED slots)...\n");
    reinsertLostKeys(&galaxy);
    display(galaxy);

    return 0;
}

// TODO: You will implement search() and removeKey()
bool search(HashTable ht, int key) {
    int hashVal = hash(key),
        ctr;
    bool retval = false;

    if (ht.keys[hashVal] == key) {
        retval = true;
    } else {
        for (ctr = (hashVal+1) % TABLE_SIZE; ctr != hashVal && ht.keys[ctr] != key && ht.keys[ctr] != EMPTY; ctr = (ctr+1) % TABLE_SIZE) {}
        if (ctr != hashVal && ht.keys[ctr] == key) {
            retval = true;
        }
    }
    return retval;
}

void removeKey(HashTable *ht, int key) {
    int hashVal = hash(key),
        ctr;

    if (ht->keys[hashVal] == key) {
        ht->keys[hashVal] = DELETED;
    } else {
        for (ctr = (hashVal+1) % TABLE_SIZE; ctr != hashVal && ht->keys[ctr] != key && ht->keys[ctr] != EMPTY; ctr = (ctr+1) % TABLE_SIZE) {}
        if (ctr != hashVal && ht->keys[ctr] == key) {
            ht->keys[ctr] = DELETED;
        }
    }
}

void reinsertLostKeys(HashTable *ht) {
    int tempKeys[TABLE_SIZE],
        ctr,
        count = 0;

    for (ctr = 0; ctr < TABLE_SIZE; ctr++) {
        if (ht->keys[ctr] != DELETED || ht->keys[ctr] != EMPTY) {
            tempKeys[count++] = ht->keys[ctr];
        }
    }

    initTable(ht);

    for (ctr = 0; ctr < count; ctr++) {
        insert(ht, tempKeys[ctr]);
    }
}

// Pre - implemented functions
void initTable(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++)
        ht->keys[i] = EMPTY;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(HashTable *ht, int key) {
    int index = hash(key);
    int startIndex = index;

    while (ht->keys[index] != EMPTY && ht->keys[index] != DELETED) {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            printf("Table is full! Could not insert %d\n", key);
            return;
        }
    }

    ht->keys[index] = key;
}

void display(HashTable ht) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht.keys[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else if (ht.keys[i] == DELETED)
            printf("[%d] : DELETED\n", i);
        else
            printf("[%d] : %d\n", i, ht.keys[i]);
    }
}
