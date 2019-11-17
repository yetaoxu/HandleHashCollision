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
    Student *next;
};

struct HashTable {
    int hashLen;
    Student *data;
};

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
        t->next = nullptr;
    }
    return hashtable;
}

void insert(HashTable *hashtable, int key, char *name) {
    int address = hashFunc(key);
    Student *head = hashtable->data + address;
    while (true){
        if (head->id == NULL) {
            head->id = key;
            int nameLen = (int) strlen(name);
            head->name = (char *)malloc(sizeof(char) * nameLen);
            head->name = name;
            head->next = nullptr;
            cout << "insert key : " << key << " success" << endl;
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
            cout << "insert key : " << key << " success" << endl;
            break;
        }
        head = head->next;
    }
}

string findName(HashTable *hashtable, int key) {
    int address = hashFunc(key);
    Student *temp = hashtable->data + address;
    while (temp->id != key) {
        temp = temp->next;
    }
    return temp->name;
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