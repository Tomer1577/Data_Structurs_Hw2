#include "HashTable.h"
#include <cassert>

void HashTable::Grow()
{
    int oldSize = table->GetSize();
    std::shared_ptr<Array<List<Course>>> newTable(new Array<List<Course>>(2*oldSize));
    for (int i = 0; i < oldSize; ++i) {
        List<Course> &list = (*table)[i];
        for (const Course &course:list) {
            (*newTable)[course.id % 2*oldSize].PushFront(course);
        }
    }
    table = newTable;
}

void HashTable::Shrink()
{
    int oldSize = table->GetSize();
    assert(oldSize % 2 == 0 && oldSize > 8);
    std::shared_ptr<Array<List<Course>>> newTable(new Array<List<Course>>(oldSize/2));
    for (int i = 0; i < oldSize; ++i) {
        List<Course> &list = (*table)[i];
        for (const Course &course:list) {
            (*newTable)[course.id % oldSize/2].PushFront(course);
        }
    }
    table = newTable;
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