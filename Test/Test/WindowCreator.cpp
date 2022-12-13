#include "WindowCreator.h"
#include "VulkanCreator.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

struct WindowCreator::impl {
	GLFWwindow* window;
	VkInstance instance;
	VkPhysicalDevice physicalDevice;

	void initWindow() {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(800, 600, "Project test", nullptr, nullptr);
	}

	void initVulkan() {
		VulkanCreator vk_create = VulkanCreator();
		
		vk_create.createInstance(&instance);
		vk_create.pickPhysicalDevice(&physicalDevice, &instance);
	}


	void cleanup() {
		vkDestroyInstance(instance, nullptr);
		
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void mainLoop() {
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}
	}
};


WindowCreator::WindowCreator() : pimpl(new impl) {}

WindowCreator::~WindowCreator() = default;


void WindowCreator::run() {
	pimpl-> initWindow();
	pimpl-> initVulkan();
	pimpl-> mainLoop();
	pimpl-> cleanup();
}