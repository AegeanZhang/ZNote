add_subdirectory(ui)

set(SRC_SOURCES
    src/main.cpp
    src/StyleManager.cpp
    src/StyleManager.h
    src/config/app_settings.h
    ${UI_SOURCES}
    PARENT_SCOPE
)