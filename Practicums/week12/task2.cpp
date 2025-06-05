#include <iostream>
#include <stdexcept>

template <typename T, size_t MaxRefs>
class SharedPtr {
private:
    T* ptr;
    static size_t refCount;

    void addRef() {
        if (refCount >= MaxRefs) {
            throw std::runtime_error("Max number of pointers exceeded!");
        }
        ++refCount;
    }

    void removeRef() {
        if (refCount > 0) {
            --refCount;
            if (refCount == 0) {
                delete ptr;
                ptr = nullptr;
            }
        }
    }

public:
    explicit SharedPtr(T* p = nullptr) : ptr(p) {
        if (ptr) addRef();
    }

    SharedPtr(const SharedPtr& other) : ptr(other.ptr) {
        if (ptr) addRef();
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            removeRef();
            ptr = other.ptr;
            if (ptr) addRef();
        }
        return *this;
    }

    ~SharedPtr() {
        removeRef();
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    static size_t use_count() {
        return refCount;
    }
};

template <typename T, size_t MaxRefs>
size_t SharedPtr<T, MaxRefs>::refCount = 0;

int main() {
    try {
        SharedPtr<int, 2> p1(new int(5));
        SharedPtr<int, 2> p2 = p1;
        std::cout << *p2 << std::endl;

        SharedPtr<int, 2> p3 = p1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
