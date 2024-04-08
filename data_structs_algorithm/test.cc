
#include <iostream>
#include <string>
#include <utility>

template<typename... Args, typename Class, typename Ret, typename... UArgs>
void invoke(Class* obj, Ret (Class::*func)(Args...), UArgs&&... args)
{
    (obj->*func)(std::forward<UArgs>(args)...);
}

struct Foo
{
    void withOverload(const std::string& s)
    {
        std::cout << this << ": " << s << std::endl;
    }

    void withOverload(int i, double d)
    {
        std::cout << this << ": " << i << ", " << d << std::endl;
    }

    void noOverload(const std::string& s)
    {
        std::cout << this << ": " << s << std::endl;
    }
};

constexpr char kSomeName[] = "some-name";

int main()
{
    Foo foo;

    invoke(&foo, &Foo::noOverload, std::string("test"));
    invoke(&foo, &Foo::noOverload, "string literal");
    invoke(&foo, &Foo::noOverload, kSomeName);

    invoke<const std::string&>(&foo, &Foo::withOverload, "test");
    invoke<int, double>(&foo, &Foo::withOverload, 1, 5.0);

    return 0;
}