#ifndef COURSESMANAGER
#define COURSESMANAGER

#include <memory>
#include "AVLTree.h"
#include "HashTable.h"
#include "library.h"
#include "Exception.h"
#include "TimeTreeKey.h"
#include "ClassList.h"

class CoursesManager
{
    private:
    HashTable courseTable;
    AVLTree<TimeTreeKey,TimeTreeKey> watchedClasses;

    public:
    CoursesManager()=default;

    CoursesManager(const CoursesManager &other) = delete;

    CoursesManager& operator=(const CoursesManager &other) = delete;

    ~CoursesManager() = default;

    StatusType AddCourse(int courseID);

    StatusType RemoveCourse(int courseID);

    StatusType AddClass(int courseID, int* classID);

    StatusType WatchClass(int courseID, int classID, int time);

    StatusType TimeViewed(int courseID, int classID, int *timeViewed);

    StatusType GetIthWatchedClass(int i, int* courseID, int* classID);
};




#endif//Course maneger