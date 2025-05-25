add_subdirectory(dialogs)
add_subdirectory(widgets)
add_subdirectory(mainwindow)

# 汇总本目录及子目录的源文件
set(UI_SOURCES
    ${DIALOGS_SOURCES}
    ${WIDGETS_SOURCES}
    ${MAINWINDOW_SOURCES}
    PARENT_SCOPE
)