#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

//  width and height of window
const int WIDTH = 800;
const int HEIGHT = 600;


// call everytime when window  is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// process input

void processInput(GLFWwindow *window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }
}


int main(){
    

    if (!glfwInit()) {
        std::cout << "GLFW failed!" << std::endl;
        return -1;
    }

    // init glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR , 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    

    // create window
    GLFWwindow * window =glfwCreateWindow(WIDTH,HEIGHT,"Mine craft clone",NULL,NULL);

    if(window == NULL){
        std::cout<<"Failed to create window"<<std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // init glad
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        std::cout<<"Failed to init GLAD"<<std::endl;
    }

    // set view port
    glViewport(0,0,WIDTH,HEIGHT);
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

    while(!glfwWindowShouldClose(window)){
        processInput(window);

    
        glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    return 0;
}

