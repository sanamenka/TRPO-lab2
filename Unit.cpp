#ifndef UNIT_CPP
#define UNIT_CPP
#include <memory>
#include <vector>

class Unit {
public:
    // Объявление псевдонима Flags для типа unsigned int
    using Flags = unsigned int;
    // Виртуальный деструктор, который
    virtual ~Unit() = default;

    // Метод для добавления вложенных элементов
    // Бросает исключение std::runtime_error, так как базовый класс Unit не поддерживает
    // добавление подэлементов
    virtual void add(const std::shared_ptr<Unit> &, Flags) {
        throw std::runtime_error("Not supported");
    }

    // Виртуальный метод для генерации кода, level - Уровень вложенности элемента
    virtual std::string compile(unsigned int level = 0) const = 0;

protected:
    // Вспомогательный метод для генерации сдвига, level - Уровень вложенности элемента
    // Возвращает строку с отступом
    virtual std::string generateShift(unsigned int level) const {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for (unsigned int i = 0; i < level; ++i) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_CPP
