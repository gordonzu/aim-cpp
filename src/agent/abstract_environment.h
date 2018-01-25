#ifndef ABSTRACT_ENVIRONMENT_H
#define ABSTRACT_ENVIRONMENT_H

#include <vector>
#include <memory>
#include <iostream>
#include "agent.h"
#include "environment_object.h"

class AbstractEnvironment {
public:
    void                              addEnvironmentObject(EnvironmentObject* eo);
    std::vector<Agent*>&              getAgents(); 
    std::vector<EnvironmentObject*>&  getEnvironmentObjects();  

protected:
    std::vector<EnvironmentObject*> envObjects;
    std::vector<Agent*>             agents;
};
#endif

