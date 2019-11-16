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
    Student *next;
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
        t->next = nullptr;
    }
    return hashtable;
}

void insert(HashTable *hashtable, int key, char *name) {
    int address = hashFunc(hashtable, key);
    Student *head = hashtable->data + address;
    while (true){
        if (head->id == NULL) {
            head->id = key;
            int nameLen = (int) strlen(name);
            head->name = (char *)malloc(sizeof(char) * nameLen);
            head->name = name;
            head->next = nullptr;
            break;
        }
        if (head->id != NULL){
            int newLen = (int) strlen(name);
            Student *newNode = (Student *)malloc(sizeof(Student));
            newNode->id = key;
            newNode->name = (char *)malloc(sizeof(char) * newLen);
            newNode->name = name;
            newNode->next = nullptr;
            head->next = newNode;
            break;
        }
        head = head->next;
    }
}

string findName(HashTable *hashtable, int key) {
    int address = hashFunc(hashtable, key);
    Student *temp = hashtable->data + address;
    while (temp->id != key) {
        temp = temp->next;
    }
    return temp->name;
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