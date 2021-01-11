#include "CoursesManager.h"

StatusType CoursesManager::AddCourse(int courseID)
{
    if(courseID <= 0)
    {
        return INVALID_INPUT;
    }
    Course newCourse(courseID);
    try{
    this->courseTable.Insert(newCourse);//i fthink catch
    }
    catch(ItemFound &e)
    {
        return FAILURE;
    }
    catch(std::exception &e)
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
    Course toRemove = (this->courseTable).GetCourse(courseID);
    ClassList classesToRemove =  toRemove.classes;
    for(int i = 0 ; i < classesToRemove.GetClassnum(); i++)
    {
        if(classesToRemove[i] > 0)
        {
            TimeTreeKey keyToRemove(classesToRemove[i],courseID,i);
            try
            {
                watchedClasses.Remove(keyToRemove);//catch??
            }
            catch(ItemNotFound &e)
            {
                return FAILURE;
            }
            catch(std::exception &e)
            {
                return ALLOCATION_ERROR;
            }
        }
    }
    this->courseTable.Remove(courseID);
    return SUCCESS;
}

StatusType CoursesManager::AddClass(int courseID, int* classID)
{
    if(courseID <= 0)
    {
        return INVALID_INPUT;
    }
    try {
        Course& tempClass = courseTable.GetCourse(courseID);//catch!
        //no need to check class id match
        tempClass.classes.AddClass();//this will be fine when change to claasss list
        *classID = tempClass.classes.GetClassnum()-1;
    }
    catch(ItemNotFound &e)
    {
        return FAILURE;
    }
    catch(std::exception &e)
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
        Course& tempClass = courseTable.GetCourse(courseID);//catch!
        if(tempClass.classes.GetClassnum() <  classID+1)
        {
            return INVALID_INPUT;
        }
        if(tempClass.classes[classID] == NOCLASS)
        {
            return FAILURE;
        }
        tempClass.classes[classID] += time;
    }
    catch(ItemNotFound &e)
    {
        return FAILURE;
    }
    catch(std::exception &e)
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
        Course& tempClass = courseTable.GetCourse(courseID);//catch!
        if(tempClass.classes.GetClassnum() <  classID+1)
        {
            return INVALID_INPUT;
        }
        if(tempClass.classes[classID] == NOCLASS)
        {
            return FAILURE;
        }
        *timeViewed = tempClass.classes[classID];
    }
    catch(ItemNotFound &e)
    {
        return FAILURE;
    }
    catch(std::exception &e)
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
        TimeTreeKey ithWatched = watchedClasses.GetIthItem(i); //catch
        *classID = ithWatched.classId;
        *courseID = ithWatched.courseId;
    }
    catch(OutOfBounds &e)
    {
        return FAILURE;
    }
    catch(std::exception &e)
    {
         return ALLOCATION_ERROR;
    }
    return SUCCESS;
}