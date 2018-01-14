// LocationPair.h
#ifndef LOCATION_PAIR_H
#define LOCATION_PAIR_H

#include <vector>
#include <memory>
#include <utility>
#include "Util/datastructure/include/XYLocation.h"
#include "Agent/include/EnvironmentObject.h"

using PtrEnv = std::shared_ptr<EnvironmentObject>;

class LocationPair {
public:
    LocationPair(XYLocation* xy, std::vector<PtrEnv>& envs);
    LocationPair(XYLocation* xy, std::vector<PtrEnv>&& envs);

    size_t                  getEnvsSize();
    std::vector<PtrEnv>&    get_envs();
    XYLocation*             get_xy();

private:
    XYLocation*         xy_;
    std::vector<PtrEnv> envs_;    
};
#endif

