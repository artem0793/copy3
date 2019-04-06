#ifndef _SERVICE_MANAGER_H

#define _SERVICE_MANAGER_H

#include "Service.h"

const unsigned int SERVICE_MAX_QUENTITY = 15;

class ServiceManager {

  protected:

    ServiceManager(void);

  public:

    Service* services[SERVICE_MAX_QUENTITY] = {};

    static ServiceManager* getInstance(void);

    int getFreeIndex(void);

    void add(Service*);

    void remove(Service*);

    Service* get(const char*);

    void process(void);

};

#endif
