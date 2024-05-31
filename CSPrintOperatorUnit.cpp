#ifndef CSPRINTOPERATORUNIT_CPP
#define CSPRINTOPERATORUNIT_CPP
#include "printoperatorunit.cpp"

class CSPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CSPrintOperatorUnit( const std::string& text ) : PrintOperatorUnit(text) { }
    std::string compile( unsigned int level = 0 ) const
    {
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

#endif // CSPRINTOPERATORUNIT_CPP
