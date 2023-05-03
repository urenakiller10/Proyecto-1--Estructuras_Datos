cmake_minimum_required(VERSION 3.5)

project(Proyecto1_ED VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        proyecto_ed.cpp
        timeStamp.cpp
        isInt.cpp
        proyecto_ed.h
        proyecto_ed.ui
        includes.h
        timeStamp.h
        BalanceadorDecisiones.h
        ColaFacturacion.h
        CargarClientesMemoria.h
        HiloPedidos.h
        FabricasProductos.h
        calcularTiempo.h
        ColaFabricas.h
        articulos.h
        auxiliaries.h
        colaPedidos.h
        pedidos.h
        alistadores.h
        GenerarFacturasThread.h
        AsignarPedidoThread.h
        calcularTiempo.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Proyecto1_ED
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Proyecto1_ED APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Proyecto1_ED SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Proyecto1_ED
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Proyecto1_ED PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Proyecto1_ED PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Proyecto1_ED
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Proyecto1_ED)
endif()
