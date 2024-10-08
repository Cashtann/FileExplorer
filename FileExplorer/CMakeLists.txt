cmake_minimum_required(VERSION 3.16)

project(FileExplorer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH )

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appFileExplorer
    main.cpp
)

qt_add_qml_module(appFileExplorer
    URI FileExplorer
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES FileSystem.h FileSystem.cpp
        SOURCES PathInfo.h PathInfo.cpp
        SOURCES
        QML_FILES ShortcutButton.qml
        QML_FILES ImageButton.qml
        RESOURCES
        assets/icons/app_generic.png
        assets/icons/folder_generic.png
        assets/icons/error.png
        assets/icons/back_symbol.png
        assets/icons/next_symbol.png
        assets/icons/go_previous.png
        assets/icons/refresh.png
        assets/icons/search.png
        assets/icons/cpp.png
        assets/icons/hpp.png
        SOURCES ShortcutInfo.h ShortcutInfo.cpp
        SOURCES FilesController.h FilesController.cpp
        QML_FILES FilesPanel.qml
        SOURCES ShortcutsController.h ShortcutsController.cpp
        QML_FILES ShortcutsPanel.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appFileExplorer PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appFileExplorer
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appFileExplorer
    PRIVATE Qt6::Quick Qt6::Core
)

include(GNUInstallDirs)
install(TARGETS appFileExplorer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
