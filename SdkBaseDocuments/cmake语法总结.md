# cmake语法总结

CMake语法主要涉及到以下几个方面，包括项目信息设置、目标的定义、条件判断、变量的定义和引用等。

### 1. 设置项目信息

- **project(name [LANGUAGES lang1 lang2 ...])**: 设置项目名称和支持的编程语言。

  ```shell
  project(MyProject LANGUAGES CXX)
  ```

  

- **cmake_minimum_required(VERSION version)**: 设置CMake的最低版本要求。

  ```shell
  cmake_minimum_required(VERSION 3.0)
  ```

### 2. 定义变量

- **set(variable value)**: 定义变量。

  ```shell
  set(SOURCES main.cpp foo.cpp)
  ```

### 3. 添加可执行文件和库

- **add_executable(target sources)**: 定义可执行文件。

  ```shell
  add_executable(my_executable main.cpp)
  ```

- **add_library(target type sources)**: 定义库。

  ```shell
  add_library(my_library STATIC my_source.cpp)
  ```

### 4. 包含头文件

- **include_directories(directory1 [directory2 ...])**: 添加头文件搜索路径。

  ```shell
  include_directories(include)
  ```

### 5. 设置编译标志

- **set(CMAKE_CXX_FLAGS "flags")**: 设置编译标志。

  ```shell
  set(CMAKE_CXX_FLAGS "-std=c++11")
  ```

### 6. 链接库

- **target_link_libraries(target library1 [library2 ...])**: 链接库到目标。

  ```
  cmakeCopy code
  target_link_libraries(my_executable my_library)
  ```

### 7. 安装目标

- **install(TARGETS ... DESTINATION ...)**: 安装目标文件。

  ```
  cmakeCopy code
  install(TARGETS my_executable DESTINATION bin)
  ```

### 8. 外部项目集成

- **find_package(package [version] [EXACT] [QUIET] [MODULE])**: 查找并加载第三方包。

  ```
  cmakeCopy codefind_package(Boost REQUIRED COMPONENTS filesystem system)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(my_executable ${Boost_LIBRARIES})
  ```

### 9. 条件判断

- **if(condition)**: 条件判断。

  ```
  cmakeCopy codeif(ENABLE_FEATURE)
      add_definitions(-DENABLE_FEATURE)
  endif()
  ```

### 10. 循环

- **foreach(variable range)**: 循环。

  ```
  cmakeCopy codeset(SOURCES main.cpp foo.cpp bar.cpp)
  foreach(src ${SOURCES})
      message("Source file: ${src}")
  endforeach()
  ```

这只是CMake语法的一小部分，更详细的内容可以参考CMake官方文档。 CMake的语法设计得相当灵活，可以满足复杂项目的需求。