#ifndef Singleton_hpp
#define Singleton_hpp

template <typename Class>
class Singleton{
private:
    
    static Class* _instancePointer;
    
    Singleton(const Singleton& singleton){}
    Singleton& operator=(const Singleton& singleton){}
    
protected:
    
    Singleton(){}
    ~Singleton(){
        if (_instancePointer){
            delete _instancePointer;
        }
        _instancePointer = nullptr;
    }
    
public:
    
    static Class* volatile getInstance(){
        if (_instancePointer == nullptr){
            _instancePointer = new (std::nothrow) Class();
            assert(_instancePointer != nullptr);
        }
        return _instancePointer;
    }
    
};

template <typename Class>
Class* Singleton<Class>::_instancePointer = nullptr;

#endif
