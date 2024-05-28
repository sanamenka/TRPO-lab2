#ifndef CSMETHODUNIT_CPP
#define CSMETHODUNIT_CPP
#include "MethodUnit.cpp"

class CSMethodUnit : public MethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        ABSTRACT = 2 << 1,
        VIRTUAL = 3 << 2,
    };

    explicit CSMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
        : MethodUnit(name, returnType, flags) {}


    std::string compile(unsigned int level = 0) const
    {

        std::string result = generateShift(level);

        if (m_flags & ABSTRACT)
        {
            result += "abstract ";
        }

        if (m_flags & VIRTUAL)
        {
            result += "virtual ";
        }

        if (m_flags & STATIC)
        {
            result += "static ";
        }
        result += m_returnType + " ";
        result += m_name + "()";

        result += " {\n";

        for (const auto &b: m_body)
        {

            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
        return result;
    }
};

#endif // CSMETHODUNIT_CPP
