#ifndef VULKAN_DEVICE_PICKER_H
#define VULKAN_DEVICE_PICKER_H

#include <vulkan/vulkan.h>
#include <vector>

class VulkanDevicePicker {

public:
	bool isDeviceSuitable(VkPhysicalDevice physicalDevice);
	void getDeviceList(VkInstance* instance, std::vector<VkPhysicalDevice>* physicalDevices);
	void getBestDevice(std::vector<VkPhysicalDevice>* physicalDevices, VkPhysicalDevice* physicalDevice);
};

#endif