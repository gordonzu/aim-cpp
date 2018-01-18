// XYEnvironment.cpp

#include "Environment/xyenv/include/XYEnvironment.h"
#include "Environment/xyenv/include/Wall.h"

XYEnvironment::XYEnvironment()
{
}

XYEnvironment::XYEnvironment(int w, int h)
{
    assert (w > 0);
    assert (h > 0);

    envState = new XYEnvironmentState(w, h);
}

XYEnvironment::~XYEnvironment()
{
    delete envState;
    envState = nullptr;
}

void XYEnvironment::addObjectToLocation(EnvironmentObject* eo, const XYLocation& loc)
{
    moveObjectToAbsoluteLocation(eo, loc);
}

void XYEnvironment::moveObjectToAbsoluteLocation(EnvironmentObject* eo, const XYLocation& loc)
{
    envState->moveObjectToAbsoluteLocation(eo, loc);
    addEnvironmentObject(eo);
}

XYLocation& XYEnvironment::getCurrentLocationFor(EnvironmentObject* eo)
{
    return envState->getCurrentLocationFor(eo);
}

std::vector<EnvironmentObject*>& XYEnvironment::getObjectsAt(const XYLocation& loc)
{
    return envState->getObjectsAt(loc);
}

std::vector<LocationPair>& XYEnvironment::get_vector()
{
    return envState->get_vector();
}
/*
void XYEnvironment::moveObject(EnvironmentObject* eo, const XYLocation::Direction& dir)
{
    XYLocation* current = envState->getCurrentLocationFor(eo);

    if (current) {
        moveTo = current->locationAt(dir);
        if(!(isBlocked(moveTo))) {
            moveObjectToAbsoluteLocation(eo, moveTo);
        }
    }
}

bool XYEnvironment::isBlocked(XYLocation* loc) 
{
    for (auto& eo : envState->getObjectsAt(loc)) {
        if (Wall* w = dynamic_cast<Wall*>(eo)) {      
            return true;
        }
    }
    return false;
}
*/























