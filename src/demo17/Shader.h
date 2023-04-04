#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string vertexSource;
    std::string fragmentSource;
};

/**
* @class Shader
* @brief 
* @details 描述
* @author 
*/
class Shader
{
public:
    Shader(const std::string& filePath);

    ~Shader();

    void bind() const;

    void unBind() const;

    void setUniform1i(const std::string& name, int value);

    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:
    int getUniformLocation(const std::string& name);

    ShaderProgramSource parseShader(const std::string& filePath);

    unsigned int compileShader(unsigned int type, const std::string& source);

    unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);

private:
    unsigned int m_rendererId;
    std::string m_filePath;
    std::unordered_map<std::string, int> m_uniformLocationCache;
};

#endif // SHADER_H
