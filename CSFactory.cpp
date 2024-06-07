#ifndef CSFACTORY_CPP
#define CSFACTORY_CPP
#include "abstractfactory.cpp"
#include "CSClassUnit.cpp"
#include "CSMethodUnit.cpp"
#include "CSPrintOperatorUnit.cpp"

// Класс фабрики для языка C#
class CSFactory : public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<CSClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, int flags) override {
        return std::make_shared<CSMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<CSPrintOperatorUnit>(text);
    }
};
#endif // CSFACTORY_CPP
