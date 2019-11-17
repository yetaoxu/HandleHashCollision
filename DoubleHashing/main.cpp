#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define TABLE_SIZE 10
#define PRIME 7
struct Student
{
    int id;
    char* name;
};

struct HashTable {
    int hashLen;
    int curSize;
    Student *data;
};

bool isFull(HashTable *hashtable) {
    return hashtable->curSize == hashtable->hashLen;
}

int hashFunc1(int key) {
    return key % TABLE_SIZE;
}

int hashFunc2(int base, int key) {
    int addr1 = hashFunc1(key);
    int newaddress = (addr1 + (PRIME - (key % PRIME)) * base) % TABLE_SIZE;
    return newaddress;
}

HashTable *initHashTable() {
    HashTable *hashtable = (HashTable *) malloc(sizeof(HashTable));
    hashtable->hashLen = TABLE_SIZE;
    hashtable->curSize = 0;
    hashtable->data = (Student *)malloc(sizeof(Student) * TABLE_SIZE);
    for (Student *t = hashtable->data; t != hashtable->data + TABLE_SIZE; t++) {
        t->id = NULL;
        t->name = nullptr;
    }
    return hashtable;
}

void insert(HashTable *hashtable, int key, char *name) {
    if (isFull(hashtable)) {
        cout << "The hashtable is full... " << endl;
        return;
    }
    int address = hashFunc1(key);
    int i = 1;
    while ((hashtable->data + address)->id != NULL) {
        address = hashFunc2(i, key);
        i++;
    }
    cout << "the key: " << key << ", insert address is " << address << endl;
    Student *head = hashtable->data + address;
    head->id = key;
    int nameLen = (int) strlen(name);
    head->name = (char *)malloc(sizeof(char) * nameLen);
    head->name = name;
    hashtable->hashLen++;
    hashtable->curSize++;
}

string findName(HashTable *hashtable, int key) {
    int address = hashFunc1(key);
    int i = 1;
    while ((hashtable->data + address)->id != key) {
        address = hashFunc2(i, key);
        i++;
    }
    cout << "find the key: " << key <<  ", the address is " << address << endl;
    return (hashtable->data + address)->name;
}

int main()
{
    HashTable *a = initHashTable();
    insert(a, 2, "xu");
    insert(a, 12, "tao");
    cout << "cin the ID you wan to find: " << endl;
    int ID;
    cin >> ID;
    string studentName = findName(a, ID);
    cout << "the student name is " << studentName << endl;
}
