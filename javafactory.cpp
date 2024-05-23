#ifndef JAVAFACTORY_CPP
#define JAVAFACTORY_CPP
#include "abstractfactory.cpp"

class JavaFactory : public AbstractFactory {
public:
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Flags flags) const override {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const override {
        return std::make_shared<JavaClassUnit>(name);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};
#endif // JavaFACTORY_CPP
