#include "VulkanCreator.h"

#include <vector>
#include <iostream>

#include "VulkanDevicePicker.h"

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};


bool VulkanCreator::checkValidationSupport() {

	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validationLayers) {

		bool layerFound = false;

		for (const auto& layerProperties : availableLayers) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}

		if (!layerFound) {
			return false;
		}
	}

	return true;
}


void VulkanCreator::pickPhysicalDevice(VkPhysicalDevice* physicalDevice, VkInstance* instance) {
	VulkanDevicePicker picker;

	std::vector<VkPhysicalDevice> devices;
	picker.getDeviceList(instance, &devices);
	picker.getBestDevice(&devices, physicalDevice);
}


void VulkanCreator::createInstance(VkInstance* instance) {

	if (enableValidationLayers && !checkValidationSupport()) {
		throw std::runtime_error("Validation layers requested, but not available");
	}

	VkApplicationInfo appInfo{};

	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Test";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;


	VkInstanceCreateInfo createInfo{};

	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtencionCount = 0;
	const char** glfwExtensions;


	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtencionCount);

	createInfo.enabledExtensionCount = glfwExtencionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;


	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else {
		createInfo.enabledLayerCount = 0;
	}

	if (vkCreateInstance(&createInfo, nullptr, instance) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create an instance");
	}
}