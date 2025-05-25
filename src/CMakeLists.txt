add_subdirectory(ui)

set(SRC_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/config/app_settings.h
    ${UI_SOURCES}
    PARENT_SCOPE
)