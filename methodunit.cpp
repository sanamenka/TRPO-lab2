#ifndef METHODUNIT_CPP
#define METHODUNIT_CPP
#include "Unit.cpp"
#include <memory>
class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC,
        CONST,
        FINAL
    };
public:
    // Конструктор класса MethodUnit, name - имя метода, returnType - Тип возвращаемого значения
    // flags - Флаги для определения модификаторов метода

    MethodUnit(const std::string &name, const std::string &returnType, Flags flags) :
        m_name(name), m_returnType(returnType), m_flags(flags) {}

    // Метод для добавления вложенных элементов, unit - Указатель на подэлемент,
    // flags - Флаги для определения модификаторов метода (не используется в данном классе)
    void add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0)
    {
        // Добавляем указатель unit в конец вектора m_body
        m_body.push_back(unit);
    }

    // Метод для формирования строкового представления метода со всеми его подэлементами,
    // учитывая модификаторы доступа и вложенность, level Уровень вложенности элемента
    virtual std::string compile(unsigned int level = 0) const
    {
        // Создание переменной, которая будет содержать сгенерированный результат, добавляем отступ,
        // зависящий от вложенности
        std::string result = generateShift(level);
        // Если у метода установлен модификатор STATIC
        if (m_flags & STATIC) {
            // То в строку result добавляется ключевое слово "static"
            result += "static ";
        }
        // Если у метода установлен модификатор FINAL
        if (m_flags & FINAL) {
            // То в строку result добавляется ключевое слово "final"
            result += "final ";
        }
        // В строку result добавляется тип возвращаемого значения метода
        result += m_returnType + " ";
        // В строку добавляется имя метода с круглыми скобками после него
        result += m_name + "()";
        // Если у метода установлен модификатор CONST
        if (m_flags & CONST) {
            // То в строку result добавляется ключевое слово "const"
            result += " const";
        }
        // В строку добавляется открывающая фигурная скобка "{", обозначающая начало тела метода
        result += " {\n";
        // Для каждого элемента b (указатель на объект типа Unit) в векторе m_body
        for (const auto &b: m_body) {
            // Вызывается метод compile для элемента b с уровнем вложенности level + 1, чтобы
            // сгенерировать код вложенных элементов
            result += b->compile(level + 1);
        }
        // В строку добавляется отступ, и закрывающая скобка, обозначающая конец тела метода
        result += generateShift(level) + "}\n";
        return result;
    }

private:
    std::string m_name;
    std::string m_returnType;
    std::vector<std::shared_ptr<Unit> > m_body;
protected:
    Flags m_flags;
};
#endif // METHODUNIT_CPP
