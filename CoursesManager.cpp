#include "CoursesManager.h"

StatusType CoursesManager::AddCourse(int courseID)
{
    if(courseID <= 0)
    {
        return INVALID_INPUT;
    }
    Course newCourse(courseID,1);
    this->courseTable.Insert(newCourse);//i fthink catch
    return SUCCESS;

}

StatusType CoursesManager::RemoveCourse(int courseID)
{
    if(courseID <= 0)
    {
        return INVALID_INPUT;
    }
    Course toRemove = (this->courseTable).GetCourse(courseID);
    ClassList classesToRemove =  toRemove.classes;//will be fine when switch to 
    for(int i = 0 ; i < classesToRemove.GetClassnum(); i++)
    {
        if(classesToRemove.TimeWatched(i) > 0)
        {
            TimeTreeKey keyToRemove(classesToRemove.TimeWatched(i),courseID,i);
            watchedClasses.Remove(keyToRemove);//catch??
        }
    }
    this->courseTable.Remove(courseID);
    return SUCCESS;
}

StatusType CoursesManager::AddClass(int courseID, int* classID)///WHY THE FUCK IS IT POINTER????? do i put it back in??
{
    if(courseID <= 0)
    {
        return INVALID_INPUT;
    }
    Course& tempClass = courseTable.GetCourse(courseID);//catch!
    //no need to check class id match
    tempClass.classes.AddClass();//this will be fine when change to claasss list
    *classID = tempClass.classes.GetClassnum()-1;
    return SUCCESS;
}

StatusType CoursesManager::WatchClass(int courseID, int classID, int time)
{
    if(courseID <= 0 || classID < 0 || time <= 0)
    {
        return INVALID_INPUT;
    }
    Course& tempClass = courseTable.GetCourse(courseID);//catch!
    if(tempClass.classes.GetClassnum() <  classID+1)////this will be fine when change to claasss list
    {
        return INVALID_INPUT;
    }
    tempClass.classes.WatchClass(classID,time);//this will be fine when change to claasss list
    return SUCCESS;
}

StatusType CoursesManager::TimeViewed(int courseID, int classID, int *timeViewed)
{
    if(courseID <= 0 || classID < 0)
    {
        return INVALID_INPUT;
    }
    Course& tempClass = courseTable.GetCourse(courseID);//catch!
    if(tempClass.classes.GetClassnum() <  classID+1)////this will be fine when change to claasss list
    {
        return INVALID_INPUT;
    }
    *timeViewed = tempClass.classes.TimeWatched(classID);//this will be fine when change to claasss list
    return SUCCESS;
}

StatusType CoursesManager::GetIthWatchedClass(int i, int* courseID, int* classID)
{
    if(i<=0)
    {
        return INVALID_INPUT;
    }
    //TimeTreeKey ithWatched = watchedClasses.

}