#ifndef METHODUNIT_CPP
#define METHODUNIT_CPP
#include "Unit.cpp"
#include <memory>
class MethodUnit : public Unit {

public:
    MethodUnit(const std::string &name, const std::string &returnType, Flags flags) :
        m_name(name), m_returnType(returnType), m_flags(flags) {}

    void add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0)
    {
        m_body.push_back(unit);
    }

protected:
    std::string m_name;
    std::string m_returnType;
    std::vector<std::shared_ptr<Unit> > m_body;
    Flags m_flags;
};
#endif // METHODUNIT_CPP
