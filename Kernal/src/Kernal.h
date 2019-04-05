
#ifndef _KERNAL_H

#define _KERNAL_H

#include <Arduino.h>
#include <ServiceManager.h>

class Kernal {
  protected:

    ServiceManager * services;

    Kernal();

  public:

    ServiceManager * getServiceManager();

    static Service * service(String name);

    static Kernal * getInstance();

    static void serviceProcess();

};

#endif
