#ifndef METHODUNIT_CPP
#define METHODUNIT_CPP
#include "Unit.cpp"
#include <memory>
class MethodUnit : public Unit { // класс для представление член-функции

public:

   /* enum Modifier { //список для проверки
        STATIC = 1,
        ABSTRACT = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        CONST = 1 << 4,
    };*/

    // конструктор
    MethodUnit(const std::string &name, const std::string &returnType, Flags flags) :
        m_name(name), m_returnType(returnType), m_flags(flags) {}

    // метод add добавляет вложенные элементы в конец вектора m_body
    void add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0)
    {
        m_body.push_back(unit);
    }

protected:
    std::string m_name; // имя метода
    std::string m_returnType; // тип возвращаемого значения
    std::vector<std::shared_ptr<Unit> > m_body;
    Flags m_flags; // для определения модификатора метода
};
#endif // METHODUNIT_CPP
