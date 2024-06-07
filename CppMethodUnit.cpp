#ifndef CPPMETHODUNIT_CPP
#define CPPMETHODUNIT_CPP
#include "MethodUnit.cpp"

class CppMethodUnit : public MethodUnit {
public:
    // список модификаторов
    enum Modifier {
        STATIC = 1,
        VIRTUAL = 1 << 2,
        CONST = 1 << 4,
    };

    // конструктор класса, который принимает name - имя метода, returnType - тип возвращаемого значения
    // flags - флаги для определения модификаторов метода
    explicit CppMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
        : MethodUnit(name, returnType, flags) {}

    // Метод для генерации кода, level - уровень вложенности
    std::string compile(unsigned int level = 0) const
    {

        std::string result = generateShift(level); // строка result, которая будет содержит сформированную строку
        // проверка - установлен ли флаг VIRTUAL в битовой маске m_flags
        // если флаг установлен, к переменной result добавляется слово "virtual"
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

        if (m_flags & CONST)
        {
            result += " const";
        }
        result += " {\n";

        for (const auto &b: m_body)
        {

            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
        return result;
    }
};

#endif // CPPMETHODUNIT_CPP
