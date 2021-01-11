#include "CoursesManager.h"

StatusType CoursesManager::AddCourse(int courseID)
{
    if(courseID <= 0)
    {
        return INVALID_INPUT;
    }
    try {
        Course newCourse(courseID);
        this->courseTable.Insert(newCourse);
    }
    catch(ItemFound &e)
    {
        return FAILURE;
    }
    catch(std::bad_alloc &e)
    {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;

}

StatusType CoursesManager::RemoveCourse(int courseID)
{
    if(courseID <= 0)
    {
        return INVALID_INPUT;
    }
    try {
        Course toRemove = (this->courseTable).GetCourse(courseID);
        ClassList classesToRemove =  toRemove.classes;
        for(int i = 0 ; i < classesToRemove.GetClassNum(); i++)
        {
            if(classesToRemove[i] > 0)
            {
                TimeTreeKey keyToRemove(classesToRemove[i],courseID,i);
                watchedClasses.Remove(keyToRemove);
            }
        }
        this->courseTable.Remove(courseID);
    }
    catch(ItemNotFound &e)
    {
        return FAILURE;
    }
    catch(std::bad_alloc &e)
    {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType CoursesManager::AddClass(int courseID, int* classID)
{
    if(courseID <= 0)
    {
        return INVALID_INPUT;
    }
    try {
        Course& tempClass = courseTable.GetCourse(courseID);
        tempClass.classes.AddClass();
        *classID = tempClass.classes.GetClassNum() - 1;
    }
    catch(ItemNotFound &e)
    {
        return FAILURE;
    }
    catch(std::bad_alloc &e)
    {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType CoursesManager::WatchClass(int courseID, int classID, int time)
{
    if(courseID <= 0 || classID < 0 || time <= 0)
    {
        return INVALID_INPUT;
    }
    try {
        Course& tempClass = courseTable.GetCourse(courseID);
        if (tempClass.classes[classID] != 0) {
            watchedClasses.Remove(TimeTreeKey(tempClass.classes[classID], courseID, classID));
        }
        tempClass.classes[classID] += time;
        watchedClasses.Insert(TimeTreeKey(tempClass.classes[classID], courseID, classID),
                TimeTreeKey(tempClass.classes[classID], courseID, classID));
    }
    catch (OutOfBounds &e) {
        return INVALID_INPUT;
    }
    catch(ItemNotFound &e)
    {
        return FAILURE;
    }
    catch(std::bad_alloc &e)
    {
        return ALLOCATION_ERROR;
    } 
    return SUCCESS;
}

StatusType CoursesManager::TimeViewed(int courseID, int classID, int *timeViewed)
{
    if(courseID <= 0 || classID < 0)
    {
        return INVALID_INPUT;
    }
    try {
        const Course& tempClass = courseTable.GetCourse(courseID);
        *timeViewed = tempClass.classes[classID];
    }
    catch (OutOfBounds &e) {
        return INVALID_INPUT;
    }
    catch(ItemNotFound &e)
    {
        return FAILURE;
    }
    catch(std::bad_alloc &e)
    {
        return ALLOCATION_ERROR;
    }
    
    return SUCCESS;
}

StatusType CoursesManager::GetIthWatchedClass(int i, int* courseID, int* classID)
{
    if(i<=0)
    {
        return INVALID_INPUT;
    }
    try {
        const TimeTreeKey &ithWatched = watchedClasses.GetIthItem(i);
        *classID = ithWatched.classId;
        *courseID = ithWatched.courseId;
    }
    catch(OutOfBounds &e)
    {
        return FAILURE;
    }
    catch(std::bad_alloc &e)
    {
         return ALLOCATION_ERROR;
    }
    return SUCCESS;
}