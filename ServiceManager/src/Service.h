#ifndef _SERVICE_H

#define _SERVICE_H

#include <BaseObject.h>

class Service: public BaseObject {

  public:

    String name;

    virtual void execute() {

    };

  protected:

    Service(String name);

    ~Service();

};

#endif