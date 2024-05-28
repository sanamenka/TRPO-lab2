#ifndef CSPRINTOPERATORUNIT_CPP
#define CSPRINTOPERATORUNIT_CPP
#include "printoperatorunit.cpp"

class CSPrintOperator : public PrintOperatorUnit
{
public:
    explicit CSPrintOperator( const std::string& text ) : PrintOperatorUnit(text) { }
    std::string compile( unsigned int level = 0 ) const
    {
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

#endif // CSPRINTOPERATORUNIT_CPP
