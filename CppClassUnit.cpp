#ifndef CPPCLASSUNIT_CPP
#define CPPCLASSUNIT_CPP
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


    explicit CppClassUnit(const std::string &name) : ClassUnit(name) {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }

    void add(const std::shared_ptr<Unit> &unit, Flags flags)
    {
        int accessModifier = PRIVATE;

        if (flags < ACCESS_MODIFIERS.size())
        {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }

    // метод представления класса с его подэлементами, учитывая модификаторы доступа. level - уровень вложенности
    virtual std::string compile(unsigned int level = 0) const
    {
        std::string result = "class " + m_name + " {\n"; // в result будем сохраняем сгенерированную строку
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i){ // цикл прохода по доступным модификаторам
            if (m_fields[i].empty()){ // если пусто - идем дальше
                continue;
            }
            result += ACCESS_MODIFIERS[i] + ":\n";
            for (const auto &f: m_fields[i]){
                result += ACCESS_MODIFIERS[i] + f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};
#endif // CPPCLASSUNIT_CPP
