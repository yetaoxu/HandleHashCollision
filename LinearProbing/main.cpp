#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define TABLE_SIZE 10

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

int hashFunc(int key) {
    return key % TABLE_SIZE;
}

HashTable *initHashTable() {
    HashTable *hashtable = (HashTable *) malloc(sizeof(HashTable));
    hashtable->hashLen= TABLE_SIZE;
    hashtable->data = (Student *)malloc(sizeof(Student) * TABLE_SIZE);
    for (Student *t = hashtable->data; t != hashtable->data + TABLE_SIZE; t++) {
        t->id = NULL;
        t->name = nullptr;
    }
    hashtable->curSize = 0;
    return hashtable;
}

void insert(HashTable *hashtable, int key, char *name) {
    if (isFull(hashtable)) {
        cout << "the hashtable is full..." << endl;
        return;
    }
    int address = hashFunc(key);
    while ((hashtable->data + address)->id != NULL) {
        address = (address + 1) % TABLE_SIZE;
    }
    cout << "the key: " << key << ", insert address is " << address << endl;
    Student *head = hashtable->data + address;
    head->id = key;
    int nameLen = (int) strlen(name);
    head->name = (char *)malloc(sizeof(char) * nameLen);
    head->name = name;
    hashtable->curSize++;
}

string findName(HashTable *hashtable, int key) {
    int address = hashFunc(key);
    while ((hashtable->data + address)->id != key) {
        address = (address + 1) % TABLE_SIZE;
        if ((hashtable->data + address)->id == NULL || address == hashFunc(key)) {
            return "no found\n";
        }
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