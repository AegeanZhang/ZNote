set(DIALOGS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/about_dialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/about_dialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/about_dialog.ui
)

# 让上级目录可以访问这些源文件
set(DIALOGS_SOURCES ${DIALOGS_SOURCES} PARENT_SCOPE)