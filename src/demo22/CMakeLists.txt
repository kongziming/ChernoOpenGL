project(demo22)

file(GLOB IMGUI_HEADER_FILES ${CMAKE_SOURCE_DIR}/vendor/imgui/*.h)
file(GLOB IMGUI_SOURCE_FILES ${CMAKE_SOURCE_DIR}/vendor/imgui/*.cpp)

source_group("imgui/Header Files" FILES ${IMGUI_HEADER_FILES})
source_group("imgui/Source Files" FILES ${IMGUI_SOURCE_FILES})

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
	Shader.h
	Shader.cpp
	Texture.h
	Texture.cpp
	${CMAKE_SOURCE_DIR}/vendor/stb_image/stb_image.h
	${CMAKE_SOURCE_DIR}/vendor/stb_image/stb_image.cpp
	${IMGUI_HEADER_FILES}
	${IMGUI_SOURCE_FILES}
)

add_definitions(-DSRC_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接GLFW和OpenGL库
target_link_libraries(${PROJECT_NAME} glfw glew32s ${OPENGL_LIBRARY})

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
	${CMAKE_SOURCE_DIR}/vendor/stb_image
	${CMAKE_SOURCE_DIR}/vendor/glm
	${CMAKE_SOURCE_DIR}/vendor/imgui
)
