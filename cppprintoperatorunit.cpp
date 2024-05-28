#ifndef CPPPRINTOPERATORUNIT_CPP
#define CPPPRINTOPERATORUNIT_CPP
#include "printoperatorunit.cpp"

class CppPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CppPrintOperator( const std::string& text ) : PrintOperatorUnit(text) { }
    std::string compile( unsigned int level = 0 ) const
    {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // CPPPRINTOPERATORUNIT_CPP
