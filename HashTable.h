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

    int Hash(int key) const {
        return key % table->GetSize();
    }

    void Grow();
    void Shrink();

    bool Exists(int id) const {
        int index = Hash(id);
        for (const Course& course:(*table)[index]) {
            if (course.id == id) {
                return true;
            }
        }
        return false;
    }

public:

    HashTable() : table(new Array<List<Course>>(INITIAL_TABLE_SIZE)), numOfItems(0){}
    HashTable(const HashTable &other) = default;
    HashTable& operator=(const HashTable &other) = default;
    ~HashTable() = default;

    void Insert(Course &course);
    void Remove(int id);

    Course& GetCourse(int id);
};



#endif//HASH_TABLE_H