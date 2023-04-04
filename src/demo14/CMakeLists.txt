project(demo14)

# 设置源文件
set(SOURCES 
    main.cpp
    Renderer.h
    Renderer.cpp
    VertexBuffer.h
    VertexBuffer.cpp
	IndexBuffer.h
	IndexBuffer.cpp
	VertexArray.h
	VertexArray.cpp
	VertexBufferLayout.h
)

add_definitions(-DSRC_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接GLFW和OpenGL库
target_link_libraries(${PROJECT_NAME} glfw glew32s ${OPENGL_LIBRARY})
