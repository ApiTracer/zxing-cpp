#cmake_minimum_required(VERSION 3.16)

#project(ZXingQtCamReader VERSION 1.0 LANGUAGES CXX)

##show that it is possible to use the library (in its simples form) with a c++-11 compiler
#set (CMAKE_CXX_STANDARD 11)

#zxing_add_package_stb()

#include (GNUInstallDirs)

#if (BUILD_WRITERS)
#    add_executable (ZXingWriter ZXingWriter.cpp)

#    target_link_libraries (ZXingWriter ZXing::ZXing stb::stb)
#    set_target_properties(ZXingWriter PROPERTIES
#        MACOSX_BUNDLE_GUI_IDENTIFIER ZXingWriter
#    )

#    add_test(NAME ZXingWriterTest COMMAND ZXingWriter qrcode "I have the best words." test.png)

##    install(TARGETS ZXingWriter DESTINATION ${CMAKE_INSTALL_BINDIR})
#endif()

#if (BUILD_READERS)
#    add_executable (ZXingReader ZXingReader.cpp)

#    target_link_libraries (ZXingReader ZXing::ZXing stb::stb)
#    set_target_properties(ZXingReader PROPERTIES
#        MACOSX_BUNDLE_GUI_IDENTIFIER ZXingReader
#    )

#    add_test(NAME ZXingReaderTest COMMAND ZXingReader -fast -format qrcode test.png) # see above

##    install(TARGETS ZXingReader DESTINATION ${CMAKE_INSTALL_BINDIR})
#endif()

#if (BUILD_READERS)
#    find_package(QT NAMES Qt5 Qt6 COMPONENTS Core Gui Multimedia Quick REQUIRED)
#    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Multimedia Quick REQUIRED)
#    set(CMAKE_AUTOMOC ON)
#    set(CMAKE_AUTORCC ON)

##    if (TARGET Qt::Gui)
##        add_executable (ZXingQtReader ZXingQtReader.cpp ZXingQtReader.h)
##        target_link_libraries(ZXingQtReader ZXing::ZXing Qt::Gui)
##    endif()

#    if (TARGET Qt::Multimedia AND TARGET Qt::Quick)
#        qt_add_executable(ZXingQtCamReader ZXingQtCamReader.cpp ZXingQtReader.h ZXingWriter.cpp)
#        qt_add_qml_module(ZXingQtCamReader
#            URI ZXingQtCamReader
#            VERSION 1.0
#            QML_FILES ZXingQt6CamReader.qml
#        )
#        set_target_properties(ZXingQtCamReader PROPERTIES
#            MACOSX_BUNDLE_GUI_IDENTIFIER ZXingQtCamReader
#            MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/ios/Info.plist"
#        )
#        target_compile_definitions(ZXingQtCamReader
#            PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
#        target_link_libraries(ZXingQtCamReader PRIVATE ZXing::ZXing Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Multimedia Qt${QT_VERSION_MAJOR}::Quick)
##        add_executable(ZXingQtCamReader ZXingQtCamReader.cpp ZXingQtCamReader.qrc ZXingQtReader.h)
##        target_link_libraries(ZXingQtCamReader ZXing::ZXing Qt::Gui Qt::Multimedia Qt::Quick)
#    endif()

##    find_package(OpenCV)
##    if (OpenCV_FOUND)
##        add_executable (ZXingOpenCV ZXingOpenCV.cpp)
##        target_include_directories (ZXingOpenCV PRIVATE ${OpenCV_INCLUDE_DIRS})
##        target_link_libraries (ZXingOpenCV ZXing::ZXing ${OpenCV_LIBS})
##    endif()
#endif()
