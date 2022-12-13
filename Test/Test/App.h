
#ifndef APP_H
#define APP_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <memory>

class App {
public:
	void run();
private:
	GLFWwindow* window;
	VkInstance instance;

	bool checkValidationSupport();

	bool isDeviceSuitable(VkPhysicalDevice device);

	void initWindow();

	void initVulkan();

	void pickPhysicalDevice();

	void createInstance();

	void mainLoop();

	void cleanup();
};

#endif