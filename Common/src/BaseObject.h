
#ifndef _BASE_OBJECT_H

#define _BASE_OBJECT_H

#include <Arduino.h>

const String BASE_OBJECT_NO_EMPTY = "+";

const String BASE_OBJECT_EMPTY = "";

class BaseObject {
  
  public:   
    
    String ISSET;
    
    BaseObject();

    ~BaseObject();

};

bool isset_object(BaseObject * obj);

#endif
