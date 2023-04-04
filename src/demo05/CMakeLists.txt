project(demo05)

# 设置源文件
set(SOURCES 
    main.cpp
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接GLFW和OpenGL库
target_link_libraries(${PROJECT_NAME} glfw glew32s ${OPENGL_LIBRARY})
