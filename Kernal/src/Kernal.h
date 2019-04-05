
#ifndef _KERNAL_H

#define _KERNAL_H

#include <ServiceManager.h>

class Kernal {

  protected:

    ServiceManager* services;

    Kernal();

  public:

    ServiceManager* getServiceManager();

    static Service* service(const char* name);

    static Kernal* getInstance();

    static void serviceProcess();

};

#endif
