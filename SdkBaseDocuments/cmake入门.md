# cmake入门

CMake是一个用于构建和管理C++项目的开源工具，它提供了一种跨平台的构建系统生成工具。CMake的配置文件被称为`CMakeLists.txt`，它描述了项目的结构和构建过程。下面是CMake的一些基本概念和用法：

### CMake基本结构

CMake项目通常包含以下文件和目录：

1. **CMakeLists.txt**: 主要的CMake配置文件，描述项目的结构和构建规则。
2. **Source文件夹**: 包含源代码文件的目录。
3. **Include文件夹**: 包含头文件的目录。
4. **Build文件夹（可选）**: 包含生成的中间和目标文件的目录，这是构建过程中的工作目录。

### 基本语法

#### 设置项目信息

```shell
# 设置项目的名称
project(MyProject)

# 指定最低的CMake版本
cmake_minimum_required(VERSION 3.0)

```

#### 添加可执行文件

```shell
# 添加可执行文件
add_executable(my_executable main.cpp)

# 或者对于多个源文件
# file(GLOB SOURCES "src/*.cpp")
# add_executable(my_executable ${SOURCES})

```

#### 添加库

```shell
# 添加库
add_library(my_library my_source.cpp)

# 链接库到可执行文件
target_link_libraries(my_executable my_library)

```

#### 包含头文件

```shell
# 包含头文件目录
include_directories(include)

```

#### 设置编译标志

```shell
# 设置编译标志
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

```

#### 定义变量

```shell
# 定义变量
set(SOURCE_FILES main.cpp)

```

### 构建项目

```shell
# 1、创建Build目录: 在项目根目录下创建一个用于构建的目录。
mkdir build
cd build
# 2、运行CMake: 在Build目录中运行cmake命令，指定项目的根目录。
cmake ..
# 3、生成项目文件: 根据你的操作系统和构建工具，可以得到不同类型的项目文件，比如Makefile、Visual Studio项目等。
# 4、构建项目: 使用生成的项目文件构建项目。
make
```

### 高级特性

```shell
# 1、查找第三方库
find_package(Boost REQUIRED COMPONENTS filesystem system)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(my_executable ${Boost_LIBRARIES})

# 2、条件编译
option(ENABLE_FEATURE "Enable Feature" ON)

if (ENABLE_FEATURE)
    add_definitions(-DENABLE_FEATURE)
endif()

# 3、生成安装目标
install(TARGETS my_executable DESTINATION bin)

```

这只是CMake的基础，CMake还支持更多高级特性，比如外部项目的集成、定制构建过程等。建议查阅CMake官方文档以获取更详细的信息。