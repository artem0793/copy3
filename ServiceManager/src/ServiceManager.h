#ifndef _SERVICE_MANAGER_H

#define _SERVICE_MANAGER_H

#include "Service.h"

const int unsigned SERVICE_MAX_QUENTITY = 10;

class ServiceManager {

  protected:

    ServiceManager();

  public:

    Service * services[SERVICE_MAX_QUENTITY] = {};

    static ServiceManager * getInstance();

    int getFreeIndex();

    void add(Service * service);

    void remove(Service * service);

    Service * get(String name);

    void process();

};

#endif