set(WIDGETS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/tool_button.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tool_button.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tab_widget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tab_widget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tab_page.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tab_page.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tab_page.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/text_editor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/text_editor.h
)

# 让上级目录可以访问这些源文件
set(WIDGETS_SOURCES ${WIDGETS_SOURCES} PARENT_SCOPE)