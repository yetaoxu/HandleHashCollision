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

int hashFunc1(HashTable *hashtable, int key) {
    return key % hashtable->hashLen;
}
int hashFunc2(HashTable *hashtable, int key) {
    return 7 - (key % 7);
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
    int address = hashFunc1(hashtable, key);
    int newaddr = address;
    if ((hashtable->data + address)->id != NULL) {
        int address2 = hashFunc2(hashtable, key);
        int i = 0;
        while (1) {
            newaddr = (address + address2 * i) % hashtable->hashLen;
            if ((hashtable->data + newaddr)->id == NULL) {
                break;
            } else {
                i++;
            }
        }
    }
    cout << "the key: " << key << ", insert address is " << newaddr << endl;
    Student *head = hashtable->data + newaddr;
    head->id = key;
    int nameLen = (int) strlen(name);
    head->name = (char *)malloc(sizeof(char) * nameLen);
    head->name = name;
}

string findName(HashTable *hashtable, int key) {
    int address = hashFunc1(hashtable, key);
    int newaddr = address;
    if ((hashtable->data + address)->id != key) {
        int address2 = hashFunc2(hashtable, key);
        int i = 0;
        while (1) {
            newaddr = (address + address2 * i) % hashtable->hashLen;
            if ((hashtable->data + newaddr)->id == key) {
                break;
            } else {
                i++;
            }
        }
    }
    cout << "find the key: " << key <<  ", the address is " << newaddr << endl;
    return (hashtable->data + newaddr)->name;
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
