#ifndef CLASSUNIT_CPP
#define CLASSUNIT_CPP
#include "Unit.cpp"
#include <memory>
#include <vector>

class ClassUnit : public Unit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    const std::vector<std::string> ACCESS_MODIFIERS  = {"public", "protected", "private"};
public:
    // Конструктор класса ClassUnit
    // Устанавливает размер вектора m_fields равным количеству доступных модификаторов класса
    explicit ClassUnit(const std::string &name) : m_name(name) {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }

    // Метод для добавления вложенных элементов
    void add(const std::shared_ptr<Unit> &unit, Flags flags)
    {
        // Установка модификатора по умолчанию
        int accessModifier = PRIVATE;
        // Проверяет корректность flags и устанавливает accessModifier в значение flags
        if (flags < ACCESS_MODIFIERS.size()) {
            accessModifier = flags;
        }
        // добавляет указатель unit в вектор, соответствующий модификатору доступа accessModifier
        // Таким образом, подэлемент класса будет добавлен в правильную группу вектора m_fields в
        // зависимости от переданных флагов flags
        m_fields[accessModifier].push_back(unit);
    }

    // Метод для формирования строкового представления класса со всеми его подэлементами,
    // учитывая модификаторы доступа и вложенность, level Уровень вложенности элемента
    virtual std::string compile(unsigned int level = 0) const
    {
        // Создание переменной, которая будет содержать сгенерированный результат
        std::string result = "class " + m_name + " {\n";
        // Цикл, который проходит по доступным модификаторам класса
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            // Если вектор, содержащий подэлементы класса для текущего модификатора, пуст, то
            // пропускается текущая итерация цикла
            if (m_fields[i].empty()) {
                continue;
            }
            // Если не пуст, то перебираются все элементы вектора m_fields и формируется строка для
            // каждого подэлемента класса
            for (const auto &f: m_fields[i]) {
                result += ACCESS_MODIFIERS[i] + f->compile(level + 1) + "\n";
            }
        }
        // Формируется строка окончания класса
        result += generateShift(level) + "};\n";
        return result;
    }

    // Объявление псевдонима Fields для std::vector<std::shared_ptr<Unit>>
    using Fields = std::vector<std::shared_ptr<Unit>>;

protected:
    std::string m_name;
    std::vector<Fields> m_fields;
};

#endif // CLASSUNIT_CPP
