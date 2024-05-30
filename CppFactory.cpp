#ifndef CPPFACTORY_CPP
#define CPPFACTORY_CPP
#include "abstractfactory.cpp"
#include "CppClassUnit.cpp"
#include "CppMethodUnit.cpp"
#include "CppPrintOperatorUnit.cpp"

// Класс фабрики для языка C++
class CppFactory : public AbstractFactory {
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) {
        return std::make_shared<CppClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, int flags) {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) {
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};
#endif // CPPFACTORY_CPP
