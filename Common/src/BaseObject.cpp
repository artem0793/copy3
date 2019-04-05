
#include "BaseObject.h"

BaseObject::BaseObject() {
  this->ISSET = BASE_OBJECT_NO_EMPTY;
};

BaseObject::~BaseObject() {
  this->ISSET = BASE_OBJECT_EMPTY;
};

bool isset_object(BaseObject * obj) {
  return obj->ISSET == BASE_OBJECT_NO_EMPTY;
};
