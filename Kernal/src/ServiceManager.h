class ServiceManager {
  
  protected:
    
    ServiceManager() {}
  
  public:
    
    Service * services[SERVICE_MAX_QUENTITY] = {};
    
    static ServiceManager * getInstance() {
      static ServiceManager * instance = new ServiceManager;
    
      return instance;
    }

    int getFreeIndex() {
      int index = -1;

      for (int unsigned i = 0; i < SERVICE_MAX_QUENTITY; i++) {
        if (!isset_object(services[i])) {
          index = i;
          break;
        }
      }

      return index;
    }
    
    void add(Service * service) {
      int index = this->getFreeIndex();
      if (index >= 0) {
        this->services[index] = service;
      }
    }
  
    void remove(Service * service) {
      for (int unsigned i = 0; i < SERVICE_MAX_QUENTITY; i++) {
        if (isset_object(services[i]) && services[i] == service) {
          services[i] = NULL;
          break;
        }
      }
    }

    Service * get(String name) {
      for (int unsigned i = 0; i < SERVICE_MAX_QUENTITY; i++) {
        if (isset_object(services[i]) && services[i]->name == name) {
          return services[i];
        }
      }
    }

    void process() {
      for (int unsigned i = 0; i < SERVICE_MAX_QUENTITY; i++) {
        if (isset_object(services[i])) {
          services[i]->execute();
        }
      }
    }
};