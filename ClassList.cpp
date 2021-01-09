#include "ClassList.h"



ClassList::ClassList() : classes(new Array<int>(INITIAL_CLASS_SIZE,NOCLASS))
{
    numOfClasses = 0;
}

void ClassList::GrowArray()
{
    std::shared_ptr<Array<int>> newArr(new Array<int>(classes->GetSize()*2,NOCLASS));
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
    if((*classes)[classID] == NOCLASS)
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
    if((*classes)[classID] == NOCLASS )
    {
        //throw
    }
    return (*classes)[classID];
}

int ClassList::GetClassnum()
{
    return numOfClasses;
}