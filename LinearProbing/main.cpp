#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;


struct Student
{
    int id;
    char* name;
};

struct HashTable {
    int hashLen;
    Student *data;
};

int hashFunc(HashTable *hashtable, int key) {
    return key % 10;
}

HashTable *initHashTable(int len) {
    HashTable *hashtable = (HashTable *) malloc(sizeof(HashTable));
    hashtable->hashLen= len;
    hashtable->data = (Student *)malloc(sizeof(Student) * len);
    for (Student *t = hashtable->data; t != hashtable->data + len; t++) {
        t->id = NULL;
        t->name = nullptr;
    }
    return hashtable;
}

void insert(HashTable *hashtable, int key, char *name) {
    int address = hashFunc(hashtable, key);
    while ((hashtable->data + address)->id != NULL) {
        address = (address + 1) % 10;
    }
    cout << "the key: " << key << ", insert address is " << address << endl;
    Student *head = hashtable->data + address;
    head->id = key;
    int nameLen = (int) strlen(name);
    head->name = (char *)malloc(sizeof(char) * nameLen);
    head->name = name;
}

string findName(HashTable *hashtable, int key) {
    int address = hashFunc(hashtable, key);
    while ((hashtable->data + address)->id != key) {
        address = (address + 1) % 10;
        if ((hashtable->data + address)->id == NULL || address == hashFunc(hashtable, key)) {
            return "no found\n";
        }
    }
    cout << "find the key: " << key <<  ", the address is " << address << endl;
    return (hashtable->data + address)->name;
}

int main()
{
    HashTable *a = initHashTable(10);
    insert(a, 2, "xu");
    insert(a, 12, "tao");
    cout << "cin the ID you wan to find: " << endl;
    int ID;
    cin >> ID;
    string studentName = findName(a, ID);
    cout << "the student name is " << studentName << endl;
}
