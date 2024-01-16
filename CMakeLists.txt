cmake_minimum_required(VERSION 3.5)

project(DB_TOPIC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# mysql登录用户名
set(USER_VALUE "root")
# mysql登录密码
set(PASSWORD_VALUE "123456")
# mysql登录ip
set(IP_VALUE "127.0.0.1")
# mysql选择连接的数据库
set(DATABASE_VALUE "topic")
# mysql端口号
set(PORT_VALUE "3306")
# mysql安装的路径（有include lib文件夹的路径）
# 我安装的位置为"D:\Program Files\MySQL\MySQL Server 8.0"
# 但是目录有空格编译不成功，建议单独复制一份出来然后修改一下MYSQL_PATH
set(MYSQL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/mysql")

# 生成exe图标文件
set(ICO_FILE "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")

# mysql的库文件目录
link_directories(${MYSQL_PATH}/lib)
# 链接到mysql库
link_libraries(libmysql)

set(PUBLISH_BIN_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PUBLISH_BIN_RELEASE})

# 设置项目ui文件的路径
set(UI_PATH    "${CMAKE_CURRENT_SOURCE_DIR}/ui")

# 项目中头文件路径
include_directories(
    "${MYSQL_PATH}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/view"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/view/student"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/view/teacher"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/view/admin"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/model"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/model/entity"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/db"
)

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS "${UI_PATH}")

# 递归搜索所有子目录的文件
file(GLOB_RECURSE INCLUDE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCES_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE IMAGE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/image/*.qrc")
file(GLOB_RECURSE UI_FILES "${UI_PATH}/*.ui")


set(PROJECT_SOURCES
   # topic_win32.rc # 设置生成exe文件图标的文件
    ${IMAGE_FILES}
    ${INCLUDE_FILES}
    ${SOURCES_FILES}
    ${UI_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DB_TOPIC
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DB_TOPIC APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DB_TOPIC SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DB_TOPIC
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# 编译时将代码中的宏全部替换为上面的值
target_compile_definitions(DB_TOPIC PUBLIC
    USER="${USER_VALUE}"
    PASSWORD="${PASSWORD_VALUE}"
    IP="${IP_VALUE}"
    PORT=${PORT_VALUE}
    DATABASE="${DATABASE_VALUE}"
)

target_link_libraries(DB_TOPIC PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(DB_TOPIC PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    ICON ICO_FILE # exe图标文件
)

install(TARGETS DB_TOPIC
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DB_TOPIC)
endif()
