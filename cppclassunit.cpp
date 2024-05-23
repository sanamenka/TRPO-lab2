#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H
#include "ClassUnit.cpp"

class CppClassUnit : public ClassUnit{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    const std::vector<std::string> ACCESS_MODIFIERS  = {"public", "protected", "private"};


    explicit CppClassUnit(const std::string &name) : ClassUnit(name) {}


    void add(const std::shared_ptr<Unit> &unit, Flags flags)
    {
        int accessModifier = PRIVATE;

        if (flags < ACCESS_MODIFIERS.size())
        {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }

    virtual std::string compile(unsigned int level = 0) const
    {
        std::string result = "class " + m_name + " {\n";
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
        {
            if (m_fields[i].empty())
            {
                continue;
            }
            for (const auto &f: m_fields[i])
            {
                result += ACCESS_MODIFIERS[i] + f->compile(level + 1) + "\n";
            }
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};
#endif // CPPCLASSUNIT_H
