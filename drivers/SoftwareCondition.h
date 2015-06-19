#ifndef SOFTWARE_CONDITION_H
#define SOFTWARE_CONDITION_H

#include "interfaces/SoftwareCondition.h"
#include "Condition.h"

namespace saftlib {

class SoftwareCondition : public Condition, public iSoftwareCondition
{
  public:
    typedef SoftwareCondition_Service ServiceType;
    typedef Condition_ConstructorType ConstructorType;
    
    static Glib::RefPtr<SoftwareCondition> create(Glib::ustring& objectPath, ConstructorType args);
    
    // iSoftwareCondition
    // -> Action
    
  protected:
    SoftwareCondition(ConstructorType args);
};

}

#endif