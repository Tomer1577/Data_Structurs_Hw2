#include "library2.h"
#include "CoursesManager.h"

void *Init()
{
    CoursesManager* DS = new(CoursesManager);
    return DS;
}

StatusType AddCourse (void *DS, int courseID)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager*)DS)->AddCourse(courseID);
}

StatusType RemoveCourse(void *DS, int courseID)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager*)DS)->RemoveCourse(courseID);
}

StatusType WatchClass(void *DS, int courseID, int classID, int time)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager*)DS)->WatchClass(courseID,classID,time);
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager*)DS)->TimeViewed(courseID,classID,timeViewed);
}

StatusType GetIthWatchedClass(void *DS, int i, int *courses, int *classes)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager*)DS)->GetIthWatchedClass(i,courses,classes);
}
StatusType AddClass(void* DS, int courseID, int* classID)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager*)DS)->AddClass(courseID,classID);
}
void Quit(void** DS)//is this right?
{

    delete((CoursesManager*)*DS);
    *DS = nullptr;
}