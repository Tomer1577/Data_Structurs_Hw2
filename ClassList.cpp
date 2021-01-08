#include "ClassList.h"



ClassList::ClassList() : classes(new Array<int>(1,-1))
{
    numOfClasses = 0;
}

void ClassList::GrowArray()
{
    std::shared_ptr<Array<int>> newArr(new Array<int>(classes->GetSize()*2,-1));
    for(int i = 0; i  < numOfClasses; i++)
    {
        (*newArr)[i] = (*classes)[i];
    }
    classes = newArr;
}

void ClassList::AddClass()
{
    if(classes->GetSize() == numOfClasses)
    {
        GrowArray();
    }
    (*classes)[++numOfClasses] = 0;
}
void ClassList::WatchClass(int classID, int time)
{
    if(classes->GetSize() <= classID)
    {
        //throw
    }
    if((*classes)[classID] == -1 )
    {
        //throw
    }
    (*classes)[classID] += time;
}
int ClassList::TimeWatched(int classID)
{
    if(classes->GetSize() <= classID)
    {
        //throw
    }
    if((*classes)[classID] == -1 )
    {
        //throw
    }
    return (*classes)[classID];
}