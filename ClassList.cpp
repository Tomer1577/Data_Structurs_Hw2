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
int& ClassList::operator[](int classID)
{
    return (*classes)[classID];
}
int ClassList::GetClassnum()
{
    return numOfClasses;
}