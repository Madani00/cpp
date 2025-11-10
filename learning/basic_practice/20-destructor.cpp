#include <iostream>

#include <string>


class ResourceLocker {
    public:
        ResourceLocker(const std::string& name) : name_(name) {
            std::cout << "[" << name_ << "] Constructor called. Resource is now active. ✨\n";
        }
        ~ResourceLocker() {
            std::cout << "[" << name_ << "] Destructor called. Resource is released/closed. 🗑️\n";
        }

        void doWork() const {
            std::cout << "[" << name_ << "] Doing some work while the resource is active.\n";
        }

    private:
        std::string name_;
};

// 2. The main function to demonstrate scope
void demonstrate_destructor_scope() {
    std::cout << "--- START of demonstrate_destructor_scope() function ---\n";

    // A. Object with the full function scope
    ResourceLocker obj_a("Obj A (Full Scope)");

    // Start an INNER SCOPE using curly braces { }
    {
        std::cout << "\n--- START of INNER SCOPE ---\n";
        
        // B. Object whose life is restricted to this inner scope
        ResourceLocker obj_b("Obj B (Inner Scope)");
        obj_b.doWork();

        std::cout << "--- END of INNER SCOPE ---\n";
    } // <-- When the code hits this closing brace, obj_b is destroyed.

    // This code runs *after* obj_b has been destroyed, but *before* obj_a is destroyed.
    std::cout << "\n[Middle of Function] Back in the main function scope.\n";
    obj_a.doWork();

    std::cout << "--- END of demonstrate_destructor_scope() function ---\n";
} // <-- When the code hits this final closing brace, obj_a is destroyed.

int main() {
    demonstrate_destructor_scope();
    return 0;
}