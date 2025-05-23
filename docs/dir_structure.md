# ZNote


ZNote/ 
├── CMakeLists.txt 
├── README.md 
├── LICENSE
├── src/
|    ├── config/
|    |    └── app_settings.h
|    ├── resources/
|    |    └── style.qss
|    ├── main.cpp
|    ├── main_window.cpp
|    ├── main_window.h
|    ├── main_window.ui
|    └── ZNote.qrc
├── vs/
|    ├── ZNote/
|    |    ├── ZNote.vcxproj
|    |    └── ZNote.vcxproj.filters
|    └── ZNote.sln

```
ZNote/
├── CMakeLists.txt
├── README.md
├── LICENSE
├── src/
│   ├── main.cpp
│   ├── ui/                      # UI 相关文件集中管理
│   │   ├── mainwindow/
│   │   │   ├── main_window.cpp
│   │   │   ├── main_window.h
│   │   │   └── main_window.ui
│   │   └── dialogs/            # 对话框类
│   │       └── about_dialog.h
│   ├── core/                   # 核心业务逻辑
│   │   └── note_manager.h
│   ├── config/
│   │   └── app_settings.h
│   └── utils/                  # 工具类
│       └── file_utils.h
├── resources/                  # 资源文件移到顶层
│   ├── icons/
│   ├── styles/
│   │   └── style.qss
│   ├── translations/
│   └── ZNote.qrc
└── vs/                        # Visual Studio 项目文件
    ├── ZNote/
    │   ├── ZNote.vcxproj
    │   └── ZNote.vcxproj.filters
    └── ZNote.sln
```