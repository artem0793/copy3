#ifndef _SERVICE_H

#define _SERVICE_H

#include <BaseObject.h>

class Service: public BaseObject {

  public:

    const char* name;

    virtual void execute(void) {

    };

  protected:

    Service(const char*);

    ~Service(void);

};

#endif
