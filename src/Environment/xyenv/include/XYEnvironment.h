#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

#include <vector>
#include <memory>
#include "Agent/include/EnvironmentObject.h"
#include "Util/datastructure/include/XYLocation.h"
#include "Util/datastructure/include/LocationPair.h"
#include "Agent/impl/include/AbstractEnvironment.h"
#include "Environment/xyenv/include/XYEnvironmentState.h"

using PtrEnv = std::shared_ptr<EnvironmentObject>;

class XYEnvironment: public AbstractEnvironment {
public:
    XYEnvironment(); 
    XYEnvironment(int w, int h); 
    virtual ~XYEnvironment();

    void                        addObjectToLocation(PtrEnv eo, XYLocation* loc); 
    void                        moveObjectToAbsoluteLocation(PtrEnv eo, XYLocation* loc);
    XYLocation*                 getCurrentLocationFor(PtrEnv eo); 
    std::vector<LocationPair>&  get_vector();
    std::vector<PtrEnv>&        getObjectsAt(XYLocation* loc);

private:
    XYEnvironmentState* envState;
};
#endif


