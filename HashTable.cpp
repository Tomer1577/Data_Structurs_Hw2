#include "HashTable.h"
#include "Exception.h"

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

void HashTable::ReHash(std::shared_ptr<Array<List<Course>>> oldTable, std::shared_ptr<Array<List<Course>>> newTable)
{
    int oldSize = oldTable->GetSize();
    int newSize = newTable->GetSize();
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
        throw ItemFound();
    }
    if (numOfItems == table->GetSize()/2) {
        Grow();
    }
    int index = Hash(course.id);
    List<Course> &list = (*table)[index];
    (*table)[index].PushFront(course);
    ++numOfItems;
}

void HashTable::Remove(int id)
{
    int index = Hash(id);
    (*table)[index].PopItem(Course(id));
}

Course& HashTable::GetCourse(int id)
{
    int index = Hash(id);
    for (Course& course:(*table)[index]) {
        if (course.id == id) {
            return course;
        }
    }
    throw ItemNotFound();
}