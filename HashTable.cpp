#include "HashTable.h"
#include <cassert>

void HashTable::Grow()
{
    std::shared_ptr<Array<List<Course>>> newTable(new Array<List<Course>>(2*table->GetSize()));
    ReHash(table, newTable);
    table = newTable;
}

void HashTable::Shrink()
{
    std::shared_ptr<Array<List<Course>>> newTable(new Array<List<Course>>(table->GetSize()/2));
    ReHash(table, newTable);
    table = newTable;
}

void ReHash(std::shared_ptr<Array<List<Course>>> oldTable, std::shared_ptr<Array<List<Course>>> newTable)
{
    int oldSize = oldTable->GetSize();
    int newSize = newTable->GetSize();
    assert(oldSize >= 8 && newSize >= 8);
    assert(oldSize == newSize*2 || oldSize*2 == newSize);
    for (int i = 0; i < oldSize; ++i) {
        List<Course> &list = (*oldTable)[i];
        for (const Course &course:list) {
            (*newTable)[course.id % newSize].PushFront(course);
        }
    }
}

void HashTable::Insert(Course &course)
{
    if (Exists(course.id)) {
        //throw
    }
    if (numOfItems == table->GetSize()/2) {
        Grow();
    }
    int index = Hash(course.id);
    (*table)[index].PushFront(course);
    ++numOfItems;
}

void HashTable::Remove(int id)
{
    int index = Hash(id);
    (*table)[index].PopItem(Course(id)); //ctor currently undefined
}

Course& HashTable::GetCourse(int id)
{
    int index = Hash(id);
    for (Course& course:(*table)[index]) {
        if (course.id == id) {
            return course;
        }
    }
    //throw
}