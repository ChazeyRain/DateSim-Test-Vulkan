#include <iostream>

#include "VulkanDevicePicker.h"


bool VulkanDevicePicker::isDeviceSuitable(VkPhysicalDevice physicalDevice) {
	return true;
}


void VulkanDevicePicker::getDeviceList(VkInstance* instance, std::vector<VkPhysicalDevice>* physicalDevices) {
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(*instance, &deviceCount, nullptr);

	if (deviceCount == 0) {
		throw std::runtime_error("Failed to find GPUs with Vukan support!");
	}

	*physicalDevices = std::vector<VkPhysicalDevice>(deviceCount);
	vkEnumeratePhysicalDevices(*instance, &deviceCount, (*physicalDevices).data());
}


void VulkanDevicePicker::getBestDevice(std::vector<VkPhysicalDevice>* physicalDevices, VkPhysicalDevice* physicalDevice) {
	*physicalDevice = VK_NULL_HANDLE;

	for (const auto& device : *physicalDevices) {
		if (isDeviceSuitable(device)) {
			*physicalDevice = device;
		}
	}
	if (*physicalDevice == VK_NULL_HANDLE) {
		throw std::runtime_error("Failed to find a suitable GPU");
	}
}