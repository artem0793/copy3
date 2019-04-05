
#ifndef _BASE_OBJECT_H

#define _BASE_OBJECT_H

const char BASE_OBJECT_NO_EMPTY = *"+";

const char BASE_OBJECT_EMPTY = *"";

class BaseObject {
  
  public:   
    
    char ISSET;
    
    BaseObject();

    ~BaseObject();

};

bool isset_object(BaseObject* obj);

#endif
