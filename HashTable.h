#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define INITIAL_TABLE_SIZE 8

#include "Array.h"
#include "Course.h"
#include "List.h"
#include <memory>

class HashTable
{
private:

    std::shared_ptr<Array<List<Course>>> table;
    int numOfItems;

public:

    HashTable() : table(new Array<List<Course>>(INITIAL_TABLE_SIZE)), numOfItems(0) {}
    HashTable(const HashTable& other) = default;
    HashTable& operator=(const HashTable& other) = default;
    ~HashTable() = default;

    void Insert(Course& course);
    void Remove(int id);

    Course& GetCourse(int id);
};



#endif//HASH_TABLE_H