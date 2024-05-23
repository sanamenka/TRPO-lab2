TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        classunit.cpp \
        cppclassunit.cpp \
        csclassunit.cpp \
        javaclassunit.cpp \
        main.cpp \
        methodunit.cpp \
        printoperatorunit.cpp \
        unit.cpp

HEADERS += \
    classunit.h \
    cppclassunit.h \
    csclassunit.h \
    javaclassunit.h \
    methodunit.h \
    printoperatorunit.h \
    unit.h
