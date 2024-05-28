#ifndef PRINTOPERATORUNIT_CPP
#define PRINTOPERATORUNIT_CPP
#include "Unit.cpp"
#include <memory>

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }

protected:
    std::string m_text;
};

#endif // PRINTOPERATORUNIT_CPP
