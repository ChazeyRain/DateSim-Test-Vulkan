#ifndef VULKAN_CREATOR_H
#define VULKAN_CREATOR_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class VulkanCreator {

public:
	bool checkValidationSupport();
	bool isDeviceSuitable(VkPhysicalDevice device);
	void pickPhysicalDevice(VkPhysicalDevice* physicalDevice, VkInstance* instance);

	void createInstance(VkInstance* instance);
};

#endif