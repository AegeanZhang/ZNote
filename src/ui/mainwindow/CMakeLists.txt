set(MAINWINDOW_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main_window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main_window.h
    ${CMAKE_CURRENT_SOURCE_DIR}/main_window.ui
)

# 让上级目录可以访问这些源文件
set(MAINWINDOW_SOURCES ${MAINWINDOW_SOURCES} PARENT_SCOPE)