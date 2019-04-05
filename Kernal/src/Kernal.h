
#ifndef _KERNAL_H

#define _KERNAL_H

#include <ServiceManager.h>

class Kernal {

  protected:

    ServiceManager* services;

    Kernal(void);

  public:

    ServiceManager* getServiceManager(void);

    static Service* service(const char*);

    static Kernal* getInstance(void);

    static void serviceProcess(void);

};

#endif
