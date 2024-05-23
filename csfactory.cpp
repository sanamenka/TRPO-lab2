#ifndef CSFACTORY_CPP
#define CSFACTORY_CPP
#include "abstractfactory.cpp"

class CSFactory : public AbstractFactory {
public:
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, unsigned int flags) const {
        return std::make_shared<CSMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const {
        return std::make_shared<CSClassUnit>(name);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const {
        return std::make_shared<CSPrintOperatorUnit>(text);
    }
};
#endif // CSFACTORY_CPP
