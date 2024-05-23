#ifndef CPPFACTORY_CPP
#define CPPFACTORY_CPP
#include "abstractfactory.cpp"

class CppFactory : public AbstractFactory {
public:
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Flags flags) const override {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const override {
        return std::make_shared<CppClassUnit>(name);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override {
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};
#endif // CPPFACTORY_CPP
