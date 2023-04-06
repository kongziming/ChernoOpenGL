# Cherno's OpenGL

按照[Cherno的OpenGL教程](https://www.youtube.com/playlist?list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2)编写的源码，英语不好的同学建议参考[B站的翻译视频](https://www.bilibili.com/video/BV1Ni4y1o7Au/)来学习。

说明：源码仅在**Windows10**系统下，使用**VS2019**经验证编译通过。

## 编译

使用CMake构建工程。

## 工程说明

源码的序号与视频教程的编号一致。

### demo02

Setting up OpenGL and Creating a Window in C++

GLFW是一个开放源码的、多平台的库，用于在桌面上开发OpenGL、OpenGL ES和Vulkan。它提供了一个简单的API来创建窗口、上下文和渲染表面，接收输入和事件。可以在[这里](https://www.glfw.org/download.html)下载源码，本工程使用的是3.3.8版本的GLFW静态库。

编好的库位于 <root>/dependencies/glfw 文件夹下。

### demo03

Using Modern OpenGL in C++

OpenGL Extension Wrangler Library（GLEW）是一个跨平台的开源C/C++扩展加载库。GLEW提供了高效的运行时机制，用于确定目标平台支持哪些OpenGL扩展。在[这里](https://glew.sourceforge.net/)下载编好的库，本工程使用的是2.1.0版本的GLEW库。

编好的库位于 <root>/dependencies/glew 文件夹下。

### demo04

Vertex Buffers and Drawing a Triangle in OpenGL

### demo05

Vertex Attributes and Layouts in OpenGL

### demo07

Writing a Shader in OpenGL

### demo08

How I Deal with Shaders in OpenGL

### demo09

Index Buffers in OpenGL

### demo11

Uniforms in OpenGL

### demo12

Vertex Arrays in OpenGL

### demo13

Abstracting OpenGL into Classes

### demo14

Buffer Layout Abstraction in OpenGL

### demo15

Shader Abstraction in OpenGL

### demo16

Writing a Basic Renderer in OpenGL

### demo17

Textures in OpenGL

Blending in OpenGL

从第19节开始，需用到[OpenGL Mathematics](https://github.com/g-truc/glm) (GLM) ，它是一个仅包含头文件的C++数学库。

源码位于 <root>/vendor/glm 目录下。

### demo20

Projection Matrices in OpenGL

### demo21

Model View Projection Matrices in OpenGL

### demo22

ImGui in OpenGL

本人使用ImGui的1.89.4版本。从[这里](https://github.com/ocornut/imgui)下载ImGui，并将ImGui的部分源码拷贝到我们的工程里，位于 <root>/vendor/imgui 目录。

需拷贝的文件有ImGui根目录下的所有.h和.cpp文件，以及backends目录下imgui_impl_glfw、imgui_impl_opengl3相关的几个文件。

### demo23

Rendering Multiple Objects in OpenGL

