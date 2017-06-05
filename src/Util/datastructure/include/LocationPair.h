// LocationPair.h
#ifndef LOCATION_PAIR_H
#define LOCATION_PAIR_H

#include <vector>
#include "Util/datastructure/include/XYLocation.h"
#include "Agent/include/EnvironmentObject.h"

class LocationPair {
public:
    LocationPair(XYLocation* xy, std::vector<EnvironmentObject*>* envs);
    //size_t getEnvsSize();
    std::vector<EnvironmentObject*>* get_envs();
    XYLocation* get_xy();

private:
    XYLocation* xy_;
    std::vector<EnvironmentObject*>* envs_;    
};
#endif

