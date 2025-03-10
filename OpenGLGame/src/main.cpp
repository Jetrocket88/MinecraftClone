#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../vendor/stb_image.h"

#include <iostream>
#include <direct.h>

#include "shader.h"
#include "texture.h"
#include "indexBuffer.h"
#include "vertexBuffer.h"
#include "vertexArray.h"
#include "vertexBufferLayout.h"
#include "vertex.h"
#include "block.h"
#include "face.h"

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float deltaTime = 0.0f;
float lastFrame = 0.0f;

bool firstMouse = true;
float lastX = 400.0f, lastY = 300.0f;
float yaw = -90.0f;
float pitch = 0.0f;
float fov = 45.0f;

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = static_cast<float>(xpos);
        lastY = static_cast<float>(ypos);
        firstMouse = false;
    }

    float xoffset = static_cast<float>(xpos) - lastX;
    float yoffset = lastY - static_cast<float>(ypos);
    lastX = static_cast<float>(xpos);
    lastY = static_cast<float>(ypos);

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    fov -= static_cast<float>(yoffset);
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    float cameraSpeed = 5.0f * deltaTime; // adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        cameraSpeed *= 2;
    }
    float verticalSpeed = cameraSpeed * 0.5f;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        cameraPos += verticalSpeed * cameraUp;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        cameraPos -= verticalSpeed * cameraUp;
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    unsigned int numCubes = 0;
    std::vector<Vertex> verticesStruct;
    std::vector<face> faces;
    faces.push_back(face(0, 0, 0, verticesStruct, numCubes, TOP));
    //faces.push_back(face(0, 0, 0, verticesStruct, numCubes, BACK));
    //faces.push_back(face(0, 0, 0, verticesStruct, numCubes, FRONT));
    //faces.push_back(face(0, 0, 0, verticesStruct, numCubes, RIGHT));
    //faces.push_back(face(0, 0, 0, verticesStruct, numCubes, LEFT));
    //faces.push_back(face(0, 0, 0, verticesStruct, numCubes, BOTTOM));

    Texture tex1("res/sillyCat.jpg", "jpg");

    std::vector<unsigned int> indices = 
    {
        0, 1, 2, // First triangle
        2, 3, 0  // Second triangle
    };

    IndexBuffer IBO(numCubes);
    IBO.vecData = indices;

    VertexBuffer VBO(verticesStruct.size() * sizeof(Vertex), verticesStruct.data());

    VertexArray VAO;
    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(4);
    layout.Push<float>(2);
    VAO.addBuffer(VBO, layout);

    IBO.bind();
    VBO.unBind();
    VAO.bind();

    Shader shader("shaders//vertex.shader", "shaders//fragment.shader");

    shader.use();
    shader.setInt("texture1", 0);

    glEnable(GL_DEPTH_TEST);
    // Render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glfwSetCursorPosCallback(window, mouse_callback);
        glfwSetScrollCallback(window, scroll_callback);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        shader.use();

        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
        glm::mat4 view;
        const float radius = 10.0f;
        float camX = sin(static_cast<float>(glfwGetTime())) * radius;
        float camZ = cos(static_cast<float>(glfwGetTime())) * radius;
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        shader.setMat4f("view", view);
        glm::mat4 projection;
        projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);

        shader.setMat4f("projection", projection);
        glm::mat4 model = glm::mat4(1.0f);
        shader.setMat4f("model", model);

        float vector[4] = { sin(static_cast<float>(glfwGetTime())), cos(static_cast<float>(glfwGetTime())), acos(static_cast<float>(glfwGetTime())), 1.0f };

        VAO.bind();
        tex1.bind(0);
        glDrawElements(GL_TRIANGLES, numCubes * 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
