/* clang-format off */
#pragma once
#ifndef VULKAN_EXPRESS_H_
#define VULKAN_EXPRESS_H_ 1

//------------------------------------------------------------------------------

#if defined(_WIN32)
    #if !defined(VK_USE_PLATFORM_WIN32_KHR)
        #define  VK_USE_PLATFORM_WIN32_KHR
    #endif
#elif defined(__APPLE__)
    #include <TargetConditionals.h>
    #if defined(TARGET_OS_MAC)
        #if !defined(VK_USE_PLATFORM_MACOS_MVK)
            #define  VK_USE_PLATFORM_MACOS_MVK
        #endif
    #elif defined(TARGET_OS_IPHONE) 
        #if !defined(VK_USE_PLATFORM_IOS_MVK)
            #define  VK_USE_PLATFORM_IOS_MVK
        #endif
    #endif
#elif defined(__linux)
    #if !defined(VK_USE_PLATFORM_XLIB_KHR) && \
        !defined(VK_USE_PLATFORM_WAYLAND_KHR)
        #define  VK_USE_PLATFORM_XLIB_KHR
    #endif
#else
    #error "unsupported platform"
#endif

//------------------------------------------------------------------------------

#ifdef VX_USE_VOLK
#ifdef VX_IMPLEMENTATION
#define VOLK_IMPLEMENTATION
#endif
#include <Volk/volk.h>
#endif

#ifdef VX_USE_GLFW3
#include <GLFW/glfw3.h>
#endif

#include <stdbool.h>

//------------------------------------------------------------------------------

#define VX_HEADER_VERSION 100

//------------------------------------------------------------------------------

#ifdef __cplusplus

    template<typename T>
    struct VxInlineArrayCast {
        template<typename A>
        const T* operator<<(const A& a) { return &a._0; }
    };

    #define VxInlineArrayCast(T) (VxInlineArrayCast<T>())<<

    template<typename T>
    struct VxInlinePtrCast {
        const T* operator<<(const T& t) { return &t; }
    };

    #define VxInlinePtrCast(T) (VxInlinePtrCast<T>())<<

#else

    #define VxInlineArrayCast(T) (const T*)&

    #define VxInlinePtrCast(T) (const T*)&

#endif

//------------------------------------------------------------------------------

#ifndef VX_INLINE_ARRAY_ELEMENTS
#define VX_INLINE_ARRAY_ELEMENTS _0,_1,_2,_3,_4,_5,_6,_7
#endif

#define VxInlineArrayDef(T) \
        typedef struct VxInlineArrayOf##T { \
            T VX_INLINE_ARRAY_ELEMENTS; \
        } VxInlineArrayOf##T;

#define VxInlineArray(T) VxInlineArrayCast(T)(VxInlineArrayOf##T)

#define VxInlinePtr(T) VxInlinePtrCast(T)(T)

VxInlineArrayDef(VkAccelerationStructureBuildGeometryInfoKHR)
VxInlineArrayDef(VkAccelerationStructureBuildRangeInfoKHR)
VxInlineArrayDef(VkAccelerationStructureCaptureDescriptorDataInfoEXT)
VxInlineArrayDef(VkAccelerationStructureCreateInfoKHR)
VxInlineArrayDef(VkAccelerationStructureCreateInfoNV)
VxInlineArrayDef(VkAccelerationStructureDeviceAddressInfoKHR)
VxInlineArrayDef(VkAccelerationStructureGeometryKHR)
VxInlineArrayDef(VkAccelerationStructureInfoNV)
VxInlineArrayDef(VkAccelerationStructureKHR)
VxInlineArrayDef(VkAccelerationStructureMemoryRequirementsInfoNV)
VxInlineArrayDef(VkAccelerationStructureNV)
VxInlineArrayDef(VkAccelerationStructureVersionInfoKHR)
VxInlineArrayDef(VkAcquireNextImageInfoKHR)
VxInlineArrayDef(VkAcquireProfilingLockInfoKHR)
VxInlineArrayDef(VkAllocationCallbacks)
VxInlineArrayDef(VkApplicationInfo)
VxInlineArrayDef(VkAttachmentDescription)
VxInlineArrayDef(VkAttachmentDescription2)
VxInlineArrayDef(VkAttachmentReference)
VxInlineArrayDef(VkAttachmentReference2)
VxInlineArrayDef(VkAttachmentSampleLocationsEXT)
VxInlineArrayDef(VkBindAccelerationStructureMemoryInfoNV)
VxInlineArrayDef(VkBindBufferMemoryInfo)
VxInlineArrayDef(VkBindImageMemoryInfo)
VxInlineArrayDef(VkBindSparseInfo)
VxInlineArrayDef(VkBindVideoSessionMemoryInfoKHR)
VxInlineArrayDef(VkBlitImageInfo2)
VxInlineArrayDef(VkBool32)
VxInlineArrayDef(VkBuffer)
VxInlineArrayDef(VkBufferCaptureDescriptorDataInfoEXT)
VxInlineArrayDef(VkBufferCopy)
VxInlineArrayDef(VkBufferCopy2)
VxInlineArrayDef(VkBufferCreateInfo)
VxInlineArrayDef(VkBufferDeviceAddressInfo)
VxInlineArrayDef(VkBufferImageCopy)
VxInlineArrayDef(VkBufferImageCopy2)
VxInlineArrayDef(VkBufferMemoryBarrier)
VxInlineArrayDef(VkBufferMemoryBarrier2)
VxInlineArrayDef(VkBufferMemoryRequirementsInfo2)
VxInlineArrayDef(VkBufferView)
VxInlineArrayDef(VkBufferViewCreateInfo)
VxInlineArrayDef(VkCalibratedTimestampInfoEXT)
VxInlineArrayDef(VkClearAttachment)
VxInlineArrayDef(VkClearColorValue)
VxInlineArrayDef(VkClearDepthStencilValue)
VxInlineArrayDef(VkClearRect)
VxInlineArrayDef(VkClearValue)
VxInlineArrayDef(VkCoarseSampleLocationNV)
VxInlineArrayDef(VkCoarseSampleOrderCustomNV)
VxInlineArrayDef(VkColorBlendAdvancedEXT)
VxInlineArrayDef(VkColorBlendEquationEXT)
VxInlineArrayDef(VkColorComponentFlags)
VxInlineArrayDef(VkCommandBuffer)
VxInlineArrayDef(VkCommandBufferAllocateInfo)
VxInlineArrayDef(VkCommandBufferBeginInfo)
VxInlineArrayDef(VkCommandBufferInheritanceInfo)
VxInlineArrayDef(VkCommandBufferSubmitInfo)
VxInlineArrayDef(VkCommandPoolCreateInfo)
VxInlineArrayDef(VkComputePipelineCreateInfo)
VxInlineArrayDef(VkConditionalRenderingBeginInfoEXT)
VxInlineArrayDef(VkCopyAccelerationStructureInfoKHR)
VxInlineArrayDef(VkCopyAccelerationStructureToMemoryInfoKHR)
VxInlineArrayDef(VkCopyBufferInfo2)
VxInlineArrayDef(VkCopyBufferToImageInfo2)
VxInlineArrayDef(VkCopyDescriptorSet)
VxInlineArrayDef(VkCopyImageInfo2)
VxInlineArrayDef(VkCopyImageToBufferInfo2)
VxInlineArrayDef(VkCopyMemoryToAccelerationStructureInfoKHR)
VxInlineArrayDef(VkCopyMemoryToMicromapInfoEXT)
VxInlineArrayDef(VkCopyMicromapInfoEXT)
VxInlineArrayDef(VkCopyMicromapToMemoryInfoEXT)
VxInlineArrayDef(VkCuFunctionCreateInfoNVX)
VxInlineArrayDef(VkCuLaunchInfoNVX)
VxInlineArrayDef(VkCuModuleCreateInfoNVX)
VxInlineArrayDef(VkDebugMarkerMarkerInfoEXT)
VxInlineArrayDef(VkDebugMarkerObjectNameInfoEXT)
VxInlineArrayDef(VkDebugMarkerObjectTagInfoEXT)
VxInlineArrayDef(VkDebugReportCallbackCreateInfoEXT)
VxInlineArrayDef(VkDebugUtilsLabelEXT)
VxInlineArrayDef(VkDebugUtilsMessengerCallbackDataEXT)
VxInlineArrayDef(VkDebugUtilsMessengerCreateInfoEXT)
VxInlineArrayDef(VkDebugUtilsObjectNameInfoEXT)
VxInlineArrayDef(VkDebugUtilsObjectTagInfoEXT)
VxInlineArrayDef(VkDecompressMemoryRegionNV)
VxInlineArrayDef(VkDependencyInfo)
VxInlineArrayDef(VkDescriptorAddressInfoEXT)
VxInlineArrayDef(VkDescriptorBindingFlags)
VxInlineArrayDef(VkDescriptorBufferBindingInfoEXT)
VxInlineArrayDef(VkDescriptorBufferInfo)
VxInlineArrayDef(VkDescriptorGetInfoEXT)
VxInlineArrayDef(VkDescriptorImageInfo)
VxInlineArrayDef(VkDescriptorPoolCreateInfo)
VxInlineArrayDef(VkDescriptorPoolSize)
VxInlineArrayDef(VkDescriptorSet)
VxInlineArrayDef(VkDescriptorSetAllocateInfo)
VxInlineArrayDef(VkDescriptorSetBindingReferenceVALVE)
VxInlineArrayDef(VkDescriptorSetLayout)
VxInlineArrayDef(VkDescriptorSetLayoutBinding)
VxInlineArrayDef(VkDescriptorSetLayoutCreateInfo)
VxInlineArrayDef(VkDescriptorType)
VxInlineArrayDef(VkDescriptorUpdateTemplateCreateInfo)
VxInlineArrayDef(VkDescriptorUpdateTemplateEntry)
VxInlineArrayDef(VkDeviceAddress)
VxInlineArrayDef(VkDeviceBufferMemoryRequirements)
VxInlineArrayDef(VkDeviceCreateInfo)
VxInlineArrayDef(VkDeviceEventInfoEXT)
VxInlineArrayDef(VkDeviceImageMemoryRequirements)
VxInlineArrayDef(VkDeviceMemoryOpaqueCaptureAddressInfo)
VxInlineArrayDef(VkDeviceMemoryReportCallbackDataEXT)
VxInlineArrayDef(VkDeviceQueueCreateInfo)
VxInlineArrayDef(VkDeviceQueueInfo2)
VxInlineArrayDef(VkDeviceSize)
VxInlineArrayDef(VkDirectDriverLoadingInfoLUNARG)
VxInlineArrayDef(VkDisplayEventInfoEXT)
VxInlineArrayDef(VkDisplayModeCreateInfoKHR)
VxInlineArrayDef(VkDisplayPlaneInfo2KHR)
VxInlineArrayDef(VkDisplayPowerInfoEXT)
VxInlineArrayDef(VkDisplaySurfaceCreateInfoKHR)
VxInlineArrayDef(VkDynamicState)
VxInlineArrayDef(VkEvent)
VxInlineArrayDef(VkEventCreateInfo)
VxInlineArrayDef(VkExtensionProperties)
VxInlineArrayDef(VkExtent2D)
VxInlineArrayDef(VkFence)
VxInlineArrayDef(VkFenceCreateInfo)
VxInlineArrayDef(VkFenceGetFdInfoKHR)
VxInlineArrayDef(VkFormat)
VxInlineArrayDef(VkFramebufferAttachmentImageInfo)
VxInlineArrayDef(VkFramebufferCreateInfo)
VxInlineArrayDef(VkGeneratedCommandsInfoNV)
VxInlineArrayDef(VkGeneratedCommandsMemoryRequirementsInfoNV)
VxInlineArrayDef(VkGeometryNV)
VxInlineArrayDef(VkGraphicsPipelineCreateInfo)
VxInlineArrayDef(VkGraphicsShaderGroupCreateInfoNV)
VxInlineArrayDef(VkHdrMetadataEXT)
VxInlineArrayDef(VkHeadlessSurfaceCreateInfoEXT)
VxInlineArrayDef(VkImageBlit)
VxInlineArrayDef(VkImageBlit2)
VxInlineArrayDef(VkImageCaptureDescriptorDataInfoEXT)
VxInlineArrayDef(VkImageCopy)
VxInlineArrayDef(VkImageCopy2)
VxInlineArrayDef(VkImageCreateInfo)
VxInlineArrayDef(VkImageMemoryBarrier)
VxInlineArrayDef(VkImageMemoryBarrier2)
VxInlineArrayDef(VkImageMemoryRequirementsInfo2)
VxInlineArrayDef(VkImageResolve)
VxInlineArrayDef(VkImageResolve2)
VxInlineArrayDef(VkImageSparseMemoryRequirementsInfo2)
VxInlineArrayDef(VkImageSubresource)
VxInlineArrayDef(VkImageSubresource2EXT)
VxInlineArrayDef(VkImageSubresourceLayers)
VxInlineArrayDef(VkImageSubresourceRange)
VxInlineArrayDef(VkImageView)
VxInlineArrayDef(VkImageViewCaptureDescriptorDataInfoEXT)
VxInlineArrayDef(VkImageViewCreateInfo)
VxInlineArrayDef(VkImageViewHandleInfoNVX)
VxInlineArrayDef(VkImportFenceFdInfoKHR)
VxInlineArrayDef(VkImportSemaphoreFdInfoKHR)
VxInlineArrayDef(VkIndexType)
VxInlineArrayDef(VkIndirectCommandsLayoutCreateInfoNV)
VxInlineArrayDef(VkIndirectCommandsLayoutTokenNV)
VxInlineArrayDef(VkIndirectCommandsStreamNV)
VxInlineArrayDef(VkInitializePerformanceApiInfoINTEL)
VxInlineArrayDef(VkInputAttachmentAspectReference)
VxInlineArrayDef(VkInstanceCreateInfo)
VxInlineArrayDef(VkMappedMemoryRange)
VxInlineArrayDef(VkMemoryAllocateInfo)
VxInlineArrayDef(VkMemoryBarrier)
VxInlineArrayDef(VkMemoryBarrier2)
VxInlineArrayDef(VkMemoryGetFdInfoKHR)
VxInlineArrayDef(VkMemoryGetRemoteAddressInfoNV)
VxInlineArrayDef(VkMicromapBuildInfoEXT)
VxInlineArrayDef(VkMicromapCreateInfoEXT)
VxInlineArrayDef(VkMicromapEXT)
VxInlineArrayDef(VkMicromapUsageEXT)
VxInlineArrayDef(VkMicromapVersionInfoEXT)
VxInlineArrayDef(VkMultiDrawIndexedInfoEXT)
VxInlineArrayDef(VkMultiDrawInfoEXT)
VxInlineArrayDef(VkMutableDescriptorTypeListEXT)
VxInlineArrayDef(VkOffset2D)
VxInlineArrayDef(VkOpticalFlowExecuteInfoNV)
VxInlineArrayDef(VkOpticalFlowImageFormatInfoNV)
VxInlineArrayDef(VkOpticalFlowSessionCreateInfoNV)
VxInlineArrayDef(VkPerformanceConfigurationAcquireInfoINTEL)
VxInlineArrayDef(VkPerformanceMarkerInfoINTEL)
VxInlineArrayDef(VkPerformanceOverrideInfoINTEL)
VxInlineArrayDef(VkPerformanceStreamMarkerInfoINTEL)
VxInlineArrayDef(VkPhysicalDevice)
VxInlineArrayDef(VkPhysicalDeviceExternalBufferInfo)
VxInlineArrayDef(VkPhysicalDeviceExternalFenceInfo)
VxInlineArrayDef(VkPhysicalDeviceExternalSemaphoreInfo)
VxInlineArrayDef(VkPhysicalDeviceFeatures)
VxInlineArrayDef(VkPhysicalDeviceImageFormatInfo2)
VxInlineArrayDef(VkPhysicalDeviceSparseImageFormatInfo2)
VxInlineArrayDef(VkPhysicalDeviceSurfaceInfo2KHR)
VxInlineArrayDef(VkPhysicalDeviceVideoFormatInfoKHR)
VxInlineArrayDef(VkPipeline)
VxInlineArrayDef(VkPipelineCache)
VxInlineArrayDef(VkPipelineCacheCreateInfo)
VxInlineArrayDef(VkPipelineColorBlendAttachmentState)
VxInlineArrayDef(VkPipelineColorBlendStateCreateInfo)
VxInlineArrayDef(VkPipelineDepthStencilStateCreateInfo)
VxInlineArrayDef(VkPipelineDynamicStateCreateInfo)
VxInlineArrayDef(VkPipelineExecutableInfoKHR)
VxInlineArrayDef(VkPipelineInfoEXT)
VxInlineArrayDef(VkPipelineInfoKHR)
VxInlineArrayDef(VkPipelineInputAssemblyStateCreateInfo)
VxInlineArrayDef(VkPipelineLayoutCreateInfo)
VxInlineArrayDef(VkPipelineLibraryCreateInfoKHR)
VxInlineArrayDef(VkPipelineMultisampleStateCreateInfo)
VxInlineArrayDef(VkPipelineRasterizationStateCreateInfo)
VxInlineArrayDef(VkPipelineShaderStageCreateInfo)
VxInlineArrayDef(VkPipelineStageFlags)
VxInlineArrayDef(VkPipelineTessellationStateCreateInfo)
VxInlineArrayDef(VkPipelineVertexInputStateCreateInfo)
VxInlineArrayDef(VkPipelineViewportStateCreateInfo)
VxInlineArrayDef(VkPresentInfoKHR)
VxInlineArrayDef(VkPresentModeKHR)
VxInlineArrayDef(VkPresentRegionKHR)
VxInlineArrayDef(VkPresentTimeGOOGLE)
VxInlineArrayDef(VkPrivateDataSlotCreateInfo)
VxInlineArrayDef(VkPushConstantRange)
VxInlineArrayDef(VkQueryPoolCreateInfo)
VxInlineArrayDef(VkQueryPoolPerformanceCreateInfoKHR)
VxInlineArrayDef(VkRayTracingPipelineCreateInfoKHR)
VxInlineArrayDef(VkRayTracingPipelineCreateInfoNV)
VxInlineArrayDef(VkRayTracingPipelineInterfaceCreateInfoKHR)
VxInlineArrayDef(VkRayTracingShaderGroupCreateInfoKHR)
VxInlineArrayDef(VkRayTracingShaderGroupCreateInfoNV)
VxInlineArrayDef(VkRect2D)
VxInlineArrayDef(VkRectLayerKHR)
VxInlineArrayDef(VkReleaseSwapchainImagesInfoEXT)
VxInlineArrayDef(VkRenderingAttachmentInfo)
VxInlineArrayDef(VkRenderingInfo)
VxInlineArrayDef(VkRenderPassBeginInfo)
VxInlineArrayDef(VkRenderPassCreateInfo)
VxInlineArrayDef(VkRenderPassCreateInfo2)
VxInlineArrayDef(VkResolveImageInfo2)
VxInlineArrayDef(VkSampleCountFlagBits)
VxInlineArrayDef(VkSampleLocationEXT)
VxInlineArrayDef(VkSampleLocationsInfoEXT)
VxInlineArrayDef(VkSampleMask)
VxInlineArrayDef(VkSampler)
VxInlineArrayDef(VkSamplerCaptureDescriptorDataInfoEXT)
VxInlineArrayDef(VkSamplerCreateInfo)
VxInlineArrayDef(VkSamplerYcbcrConversionCreateInfo)
VxInlineArrayDef(VkSemaphore)
VxInlineArrayDef(VkSemaphoreCreateInfo)
VxInlineArrayDef(VkSemaphoreGetFdInfoKHR)
VxInlineArrayDef(VkSemaphoreSignalInfo)
VxInlineArrayDef(VkSemaphoreSubmitInfo)
VxInlineArrayDef(VkSemaphoreWaitInfo)
VxInlineArrayDef(VkShaderModuleCreateInfo)
VxInlineArrayDef(VkShadingRatePaletteEntryNV)
VxInlineArrayDef(VkShadingRatePaletteNV)
VxInlineArrayDef(VkSparseBufferMemoryBindInfo)
VxInlineArrayDef(VkSparseImageMemoryBind)
VxInlineArrayDef(VkSparseImageMemoryBindInfo)
VxInlineArrayDef(VkSparseImageOpaqueMemoryBindInfo)
VxInlineArrayDef(VkSparseMemoryBind)
VxInlineArrayDef(VkSpecializationInfo)
VxInlineArrayDef(VkSpecializationMapEntry)
VxInlineArrayDef(VkStridedDeviceAddressRegionKHR)
VxInlineArrayDef(VkSubmitInfo)
VxInlineArrayDef(VkSubmitInfo2)
VxInlineArrayDef(VkSubpassBeginInfo)
VxInlineArrayDef(VkSubpassDependency)
VxInlineArrayDef(VkSubpassDependency2)
VxInlineArrayDef(VkSubpassDescription)
VxInlineArrayDef(VkSubpassDescription2)
VxInlineArrayDef(VkSubpassEndInfo)
VxInlineArrayDef(VkSubpassSampleLocationsEXT)
VxInlineArrayDef(VkSubresourceLayout)
VxInlineArrayDef(VkSwapchainCreateInfoKHR)
VxInlineArrayDef(VkSwapchainKHR)
VxInlineArrayDef(VkValidationCacheCreateInfoEXT)
VxInlineArrayDef(VkValidationCacheEXT)
VxInlineArrayDef(VkValidationCheckEXT)
VxInlineArrayDef(VkValidationFeatureDisableEXT)
VxInlineArrayDef(VkValidationFeatureEnableEXT)
VxInlineArrayDef(VkVertexInputAttributeDescription)
VxInlineArrayDef(VkVertexInputAttributeDescription2EXT)
VxInlineArrayDef(VkVertexInputBindingDescription)
VxInlineArrayDef(VkVertexInputBindingDescription2EXT)
VxInlineArrayDef(VkVertexInputBindingDivisorDescriptionEXT)
VxInlineArrayDef(VkVideoBeginCodingInfoKHR)
VxInlineArrayDef(VkVideoCodingControlInfoKHR)
VxInlineArrayDef(VkVideoDecodeH264SessionParametersAddInfoKHR)
VxInlineArrayDef(VkVideoDecodeH265SessionParametersAddInfoKHR)
VxInlineArrayDef(VkVideoDecodeInfoKHR)
VxInlineArrayDef(VkVideoEndCodingInfoKHR)
VxInlineArrayDef(VkVideoPictureResourceInfoKHR)
VxInlineArrayDef(VkVideoProfileInfoKHR)
VxInlineArrayDef(VkVideoReferenceSlotInfoKHR)
VxInlineArrayDef(VkVideoSessionCreateInfoKHR)
VxInlineArrayDef(VkVideoSessionParametersCreateInfoKHR)
VxInlineArrayDef(VkVideoSessionParametersUpdateInfoKHR)
VxInlineArrayDef(VkViewport)
VxInlineArrayDef(VkViewportSwizzleNV)
VxInlineArrayDef(VkViewportWScalingNV)
VxInlineArrayDef(VkWriteDescriptorSet)

//------------------------------------------------------------------------------

#ifdef __cplusplus
    extern "C" {
#endif

//------------------------------------------------------------------------------

const char*
vxResultName(VkResult result);

const char*
vxFormatName(VkFormat format);

const char*
vxColorSpaceName(VkColorSpaceKHR colorSpace);

const char*
vxDescriptorTypeName(VkDescriptorType descriptorType);

//------------------------------------------------------------------------------

bool
vxExpectCallback(
    const char* file, const int line,
    const char* expr, const bool ok
);

#define vxExpect(expr) \
        vxExpectCallback(__FILE__,__LINE__,#expr,(expr))

//------------------------------------------------------------------------------

bool
vxAssertCallback(
    const char* file, const int line,
    const char* expr, const bool ok
);

#define vxAssert(expr) \
        vxAssertCallback(__FILE__,__LINE__,#expr,(expr))

//------------------------------------------------------------------------------

VkResult
vxExpectNonErrorCallback(
    const char* file, const int line,
    const char* expr, const VkResult result
);

#define vxExpectNonError(expr) \
        vxExpectNonErrorCallback(__FILE__,__LINE__,#expr,(expr))

#define vxExpectNonErrorOrReturn(expr, ...) \
        do { \
            VkResult result = vxExpectNonError(expr); \
            if (result < 0) { __VA_ARGS__ return result; } \
        } while (0)

//------------------------------------------------------------------------------

VkResult
vxExpectSuccessCallback(
    const char* file, const int line,
    const char* expr, const VkResult result
);

#define vxExpectSuccess(expr) \
        vxExpectSuccessCallback(__FILE__,__LINE__,#expr,(expr))

#define vxExpectSuccessOrReturn(expr, ...) \
        do { \
            VkResult result = vxExpectSuccess(expr); \
            if (result) { __VA_ARGS__ return result; } \
        } while (0)

//------------------------------------------------------------------------------

VkResult
vxAssertNonErrorCallback(
    const char* file, const int line,
    const char* expr, const VkResult result
);

#define vxAssertNonError(expr) \
        vxAssertNonErrorCallback(__FILE__,__LINE__,#expr,(expr))

//------------------------------------------------------------------------------

VkResult
vxAssertSuccessCallback(
    const char* file, const int line,
    const char* expr, const VkResult result
);

#define vxAssertSuccess(expr) \
        vxAssertSuccessCallback(__FILE__,__LINE__,#expr,(expr))

//------------------------------------------------------------------------------

VKAPI_ATTR VkBool32
VKAPI_CALL vxDebugUtilsMessengerCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData
);

//------------------------------------------------------------------------------

#ifndef VX_MAX_SURFACE_FORMAT_COUNT
#define VX_MAX_SURFACE_FORMAT_COUNT 8
#endif

typedef struct VxContextCreateInfo {
    const VkAllocationCallbacks*   pAllocator;             // optional
    const VkInstanceCreateInfo*    pInstanceCreateInfo;    // optional
    VkPhysicalDeviceType           preferredDeviceType;    // optional
    const VkDeviceCreateInfo*      pDeviceCreateInfo;      // optional
    const VkCommandPoolCreateInfo* pCommandPoolCreateInfo; // optional
} VxContextCreateInfo;

typedef struct VxContextSurfaceCapabilities {
    uint32_t                   minImageCount;
    uint32_t                   maxImageCount;
    uint32_t                   maxImageArrayLayers;
    VkSurfaceTransformFlagsKHR supportedTransforms;
    VkCompositeAlphaFlagsKHR   supportedCompositeAlpha;
    VkImageUsageFlags          supportedUsageFlags;
} VxContextSurfaceCapabilities;

typedef struct VxContext {
    const VkAllocationCallbacks*     pAllocator;
    VkInstance                       instance;
    VkPhysicalDevice                 physicalDevice;
    VkPhysicalDeviceProperties       physicalDeviceProperties;
    VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;
    VxContextSurfaceCapabilities     surfaceCapabilities;
    uint32_t                         surfaceFormatCount;
    VkSurfaceFormatKHR               surfaceFormats[VX_MAX_SURFACE_FORMAT_COUNT];
    VkDevice                         device;
    union {
        uint32_t                     queueFamilyIndices[2];
        struct {
            uint32_t                 graphicsQueueFamilyIndex;
            uint32_t                 computeQueueFamilyIndex;
            uint32_t                 transferQueueFamilyIndex;
        };
    };
    union {
        VkQueue                      queues[2];
        struct {
            VkQueue                  graphicsQueue;
            VkQueue                  computeQueue;
            VkQueue                  transferQueue;

        };
    };
    VkCommandPool                    commandPool;
    VkCommandBuffer                  commandBuffer;
    VkPipelineCache                  pipelineCache;
} VxContext;

VkResult
vxCreateContext(
    const VxContextCreateInfo* pCreateInfo, // optional
    VxContext*                 pContext
);

static inline
VxContext
vxContext(const VxContextCreateInfo createInfo) {
    VxContext context;
    vxAssertSuccess(
        vxCreateContext(
            &createInfo,
            &context
        )
    );
    return context;
}

void
vxDestroyContext(
    VxContext* pContext
);

//------------------------------------------------------------------------------

#ifndef VX_MAX_BIND_GROUP_BINDING_COUNT
#define VX_MAX_BIND_GROUP_BINDING_COUNT 8
#endif

typedef struct VxBinding {
    VkDescriptorType type;
    VkSampler        sampler;
    VkImageView      imageView;
    VkImageLayout    imageLayout;
    VkBuffer         buffer;
    VkDeviceSize     bufferOffset;
    VkDeviceSize     bufferRange;
} VxBinding;

typedef struct VxBindGroupCreateInfo {
    VkShaderStageFlags  stageFlags;
    uint32_t            bindingCount;
    VxBinding           bindings[VX_MAX_BIND_GROUP_BINDING_COUNT];
} VxBindGroupCreateInfo;

typedef struct VxBindGroup {
    VkDescriptorPool      descriptorPool;
    VkDescriptorSetLayout descriptorSetLayout;
    VkDescriptorSet       descriptorSet;
} VxBindGroup;

VkResult
vxCreateBindGroup(
    const VxContext*             pContext,
    const VxBindGroupCreateInfo* pCreateInfo,
    VxBindGroup*                 pBindGroup
);

static inline
VxBindGroup
vxBindGroup(
    const VxContext* pContext,
    const VxBindGroupCreateInfo createInfo
) {
    VxBindGroup bindGroup;
    vxAssertSuccess(
        vxCreateBindGroup(
            pContext,
            &createInfo,
            &bindGroup
        )
    );
    return bindGroup;
}

void
vxDestroyBindGroup(
    const VxContext* pContext,
    VxBindGroup*    pBindGroup
);

//------------------------------------------------------------------------------

#ifndef VX_MIN_CANVAS_FRAME_COUNT
#define VX_MIN_CANVAS_FRAME_COUNT 2
#endif

#ifndef VX_MAX_CANVAS_FRAME_COUNT
#define VX_MAX_CANVAS_FRAME_COUNT 3
#endif

#ifndef VX_MAX_CANVAS_ATTACHMENT_COUNT
#define VX_MAX_CANVAS_ATTACHMENT_COUNT 8
#endif

#ifndef VX_MAX_CANVAS_QUEUE_FAMILY_INDEX_COUNT
#define VX_MAX_CANVAS_QUEUE_FAMILY_INDEX_COUNT 8
#endif

#ifndef VX_MAX_CANVAS_PRESENT_MODE_COUNT
#define VX_MAX_CANVAS_PRESENT_MODE_COUNT 6
#endif

typedef enum VxWindowHandleType {
    VX_WINDOW_HANDLE_TYPE_PLATFORM_DEFAULT = 0,
    VX_WINDOW_HANDLE_TYPE_HWND = 1,
    VX_WINDOW_HANDLE_TYPE_NSWINDOW = 2,
    VX_WINDOW_HANDLE_TYPE_XLIB = 3,
    VX_WINDOW_HANDLE_TYPE_WAYLAND = 4,
    VX_WINDOW_HANDLE_TYPE_GLFW = 0x70000001,
    VX_WINDOW_HANDLE_TYPE_SDL = 0x70000002,
    VX_WINDOW_HANDLE_TYPE_MAX_ENUM = 0x7FFFFFFF,
} VxWindowHandleType;

typedef struct VxCanvasAttachmentCreateInfo {
    VkImageCreateFlags      imageCreateFlags;
    VkImageType             imageType;
    VkFormat                format;
    uint32_t                mipLevels; // 0 -> 1
    uint32_t                arrayLayers; // 0 -> 1
    VkSampleCountFlagBits   samples; // 0 -> 1
    VkImageTiling           tiling;
    VkImageUsageFlags       usage; // 0 -> based on format
    VkImageLayout           initialLayout;

    VkImageViewCreateFlags  imageViewCreateFlags;
    VkImageViewType         imageViewType;
    VkComponentMapping      components;
    VkImageSubresourceRange subresourceRange;
} VxCanvasAttachmentCreateInfo;

typedef struct VxCanvasCreateInfo {
    VxWindowHandleType           windowHandleType;
    void*                        windowHandle;
    VkSurfaceFormatKHR           surfaceFormat;
    uint32_t                     swapchainImageCount;
    uint32_t                     preferredPresentModeCount;
    VkPresentModeKHR             preferredPresentModes[VX_MAX_CANVAS_PRESENT_MODE_COUNT];
    VkRenderPass                 renderPass;
    uint32_t                     additionalAttachmentCount;
    VxCanvasAttachmentCreateInfo additionalAttachmentCreateInfo[VX_MAX_CANVAS_ATTACHMENT_COUNT-1];
} VxCanvasCreateInfo;

typedef struct VxCanvasFrame {
    VkCommandBuffer     commandBuffer;
    VkFramebuffer       framebuffer;
    uint32_t            frameIndex;
    uint32_t            attachmentCount;
    union {
        VkImage         attachmentImages[VX_MAX_CANVAS_ATTACHMENT_COUNT];
        struct {
            VkImage     swapchainImage;
            VkImage     additionalImages[VX_MAX_CANVAS_ATTACHMENT_COUNT-1];
        };
    };
    union {
        VkImageView     attachmentImageViews[VX_MAX_CANVAS_ATTACHMENT_COUNT];
        struct {
            VkImageView swapchainImageView;
            VkImageView additionalImageViews[VX_MAX_CANVAS_ATTACHMENT_COUNT-1];
        };
    };
    union { VkFence     acquireWaitFence,       submitSignalFence;    };
    union { VkSemaphore acquireSignalSemaphore, submitWaitSemaphore;  };
    union { VkSemaphore submitSignalSemaphore,  presentWaitSemaphore; };
} VxCanvasFrame;

typedef struct VxCanvas {
    VkRenderPass        renderPass;
    VkSurfaceKHR        surface;
    VkSurfaceFormatKHR  surfaceFormat;
    VkSwapchainKHR      swapchain;
    uint32_t            swapchainImageCount;
    uint32_t            swapchainImageIndex;
    VkPresentModeKHR    presentMode;
    VkExtent2D          extent;
    VkDeviceMemory      deviceMemory;
    uint32_t            frameCount;
    VxCanvasFrame       frames[VX_MAX_CANVAS_FRAME_COUNT];
} VxCanvas;

VkResult
vxCreateCanvas(
    const VxContext*          pContext,
    const VxCanvasCreateInfo* pCreateInfo,
    VxCanvas*                 pView
);

static inline
VxCanvas
vxCanvas(
    const VxContext* pContext,
    const VxCanvasCreateInfo createInfo
) {
    VxCanvas canvas;
    vxAssertSuccess(
        vxCreateCanvas(
            pContext,
            &createInfo,
            &canvas
        )
    );
    return canvas;
}

void
vxDestroyCanvas(
    const VxContext* pContext,
    VxCanvas*        pView
);

VkResult
vxResizeCanvas(
    const VxContext* pContext,
    VxCanvas*        pView
);

VkResult
vxAcquireNextFrame(
    const VxContext* pContext,
    VxCanvas*        pCanvas,
    VxCanvasFrame**  ppFrame // optional
);

VxCanvasFrame*
vxBeginFrame(
    const VxContext* pContext,
    VxCanvas*        pCanvas
);

VkCommandBuffer
vxCmdBeginFrameRenderPass(
    const VxCanvas*      pCanvas,
    const VxCanvasFrame* pFrame,
    uint32_t             clearValueCount,
    const VkClearValue*  pClearValues
);

VkResult
vxSubmitFrame(
    const VxContext* pContext,
    VxCanvas*        pCanvas,
    VxCanvasFrame*   pFrame
);

VkResult
vxPresentFrame(
    const VxContext* pContext,
    VxCanvas*        pCanvas,
    VxCanvasFrame*   pFrame
);

//------------------------------------------------------------------------------

VkResult
vxAllocateMemory(
    const VxContext*            pContext,
    const VkMemoryRequirements* pMemoryRequirements,
    const VkMemoryPropertyFlags memoryPropertyFlags,
    VkDeviceMemory*             pDeviceMemory
);

VkResult
vxAllocateBufferMemory(
    const VxContext*            pContext,
    const VkBuffer              buffer,
    const VkMemoryPropertyFlags memoryPropertyFlags,
    VkDeviceMemory*             pDeviceMemory
);

VkResult
vxAllocateImageMemory(
    const VxContext*            pContext,
    const VkImage               image,
    const VkMemoryPropertyFlags memoryPropertyFlags,
    VkDeviceMemory*             pDeviceMemory
);

//------------------------------------------------------------------------------

typedef struct VxBufferAllocationInfo {
    VkBufferCreateInfo    buffer;
    VkMemoryPropertyFlags memory;
} VxBufferAllocationInfo;

typedef struct VxBufferAllocation {
    VkBuffer       buffer;
    VkDeviceSize   size;
    VkDeviceMemory memory;
} VxBufferAllocation;

VkResult
vxCreateBufferAllocation(
    const VxContext*              pContext,
    const VxBufferAllocationInfo* pAllocationInfo,
    VxBufferAllocation*           pAllocation
);

static inline
VxBufferAllocation
vxBufferAllocation(
    const VxContext* pContext,
    const VxBufferAllocationInfo allocationInfo
) {
    VxBufferAllocation allocation;
    vxAssertSuccess(
        vxCreateBufferAllocation(
            pContext,
            &allocationInfo,
            &allocation
        )
    );
    return allocation;
}

void
vxDestroyBufferAllocation(
    const VxContext*    pContext,
    VxBufferAllocation* pAllocation
);

VkResult
vxCopyToBufferAllocation(
    const VxContext*          pContext,
    const VxBufferAllocation* pDstAllocation,
    VkDeviceSize              dstOffset,
    VkDeviceSize              size,
    const void*               pSrcData
);

//------------------------------------------------------------------------------

typedef struct VxImageAllocationInfo {
    VkImageCreateInfo       image;
    VkImageAspectFlags      imageAspectMask;
    VkImageViewType         imageViewType;
    VkMemoryPropertyFlags   memory;
} VxImageAllocationInfo;

typedef struct VxImageAllocation {
    VkImage         image;
    VkImageType     imageType;
    VkImageView     imageView;
    VkImageViewType imageViewType;
    VkFormat        format;
    VkExtent3D      extent;
    uint32_t        mipLevels;
    uint32_t        arrayLayers;
    VkDeviceMemory  memory;
} VxImageAllocation;

VkResult
vxCreateImageAllocation(
    const VxContext*             pContext,
    const VxImageAllocationInfo* pAllocationInfo,
    VxImageAllocation*           pAllocation
);

static inline
VxImageAllocation
vxImageAllocation(
    const VxContext* pContext,
    const VxImageAllocationInfo allocationInfo
) {
    VxImageAllocation allocation;
    vxAssertSuccess(
        vxCreateImageAllocation(
            pContext,
            &allocationInfo,
            &allocation
        )
    );
    return allocation;
}

void
vxDestroyImageAllocation(
    const VxContext*   pContext,
    VxImageAllocation* pAllocation
);

//------------------------------------------------------------------------------

VkResult
vxCreateShaderModule(
    const VxContext* pContext,
    const size_t     codeSize,
    const uint32_t*  pCode,
    VkShaderModule*  pShaderModule
);

//------------------------------------------------------------------------------

static inline void
vxDestroyDescriptorPool(const VxContext* pContext, VkDescriptorPool* pResource) {
    vkDestroyDescriptorPool(pContext->device, *pResource, pContext->pAllocator);
    *pResource = VK_NULL_HANDLE;
}

static inline void
vxDestroyDescriptorSetLayout(const VxContext* pContext, VkDescriptorSetLayout* pResource) {
    vkDestroyDescriptorSetLayout(pContext->device, *pResource, pContext->pAllocator);
    *pResource = VK_NULL_HANDLE;
}

static inline void
vxDestroyImage(const VxContext* pContext, VkImage* pResource) {
    vkDestroyImage(pContext->device, *pResource, pContext->pAllocator);
    *pResource = VK_NULL_HANDLE;
}

static inline void
vxDestroyImageView(const VxContext* pContext, VkImageView* pResource) {
    vkDestroyImageView(pContext->device, *pResource, pContext->pAllocator);
    *pResource = VK_NULL_HANDLE;
}

static inline void
vxDestroyPipeline(const VxContext* pContext, VkPipeline* pResource) {
    vkDestroyPipeline(pContext->device, *pResource, pContext->pAllocator);
    *pResource = VK_NULL_HANDLE;
}

static inline void
vxDestroyPipelineLayout(const VxContext* pContext, VkPipelineLayout* pResource) {
    vkDestroyPipelineLayout(pContext->device, *pResource, pContext->pAllocator);
    *pResource = VK_NULL_HANDLE;
}

static inline void
vxDestroyRenderPass(const VxContext* pContext, VkRenderPass* pResource) {
    vkDestroyRenderPass(pContext->device, *pResource, pContext->pAllocator);
    *pResource = VK_NULL_HANDLE;
}

static inline void
vxDestroySampler(const VxContext* pContext, VkSampler* pResource) {
    vkDestroySampler(pContext->device, *pResource, pContext->pAllocator);
    *pResource = VK_NULL_HANDLE;
}

static inline void
vxFreeMemory(const VxContext* pContext, VkDeviceMemory* pResource) {
    vkFreeMemory(pContext->device, *pResource, pContext->pAllocator);
    *pResource = VK_NULL_HANDLE;
}

#ifdef __cplusplus

    } // extern "C"

    static inline void
    vxDestroy(const VxContext* pContext, VxBindGroup* pResource) {
        vxDestroyBindGroup(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VxCanvas* pResource) {
        vxDestroyCanvas(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VxBufferAllocation* pResource) {
        vxDestroyBufferAllocation(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VxImageAllocation* pResource) {
        vxDestroyImageAllocation(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VkDescriptorPool* pResource) {
        vxDestroyDescriptorPool(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VkDescriptorSetLayout* pResource) {
        vxDestroyDescriptorSetLayout(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VkImage* pResource) {
        vxDestroyImage(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VkImageView* pResource) {
        vxDestroyImageView(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VkPipeline* pResource) {
        vxDestroyPipeline(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VkPipelineLayout* pResource) {
        vxDestroyPipelineLayout(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VkRenderPass* pResource) {
        vxDestroyRenderPass(pContext, pResource);
    }

    static inline void
    vxDestroy(const VxContext* pContext, VkSampler* pResource) {
        vxDestroySampler(pContext, pResource);
    }

#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) // C11

    #define vxDestroy(pContext, pResource) \
            (_Generic((pResource), \
                VxBindGroup*:           vxDestroyBindGroup, \
                VxCanvas*:              vxDestroyCanvas,\
                VxBufferAllocation*:    vxDestroyBufferAllocation, \
                VxImageAllocation*:     vxDestroyImageAllocation, \
                VkDescriptorPool*:      vxDestroyDescriptorPool, \
                VkDescriptorSetLayout*: vxDestroyDescriptorSetLayout, \
                VkImage*:               vxDestroyImage, \
                VkImageView*:           vxDestroyImageView, \
                VkPipeline*:            vxDestroyPipeline, \
                VkPipelineLayout*:      vxDestroyPipelineLayout, \
                VkRenderPass*:          vxDestroyRenderPass, \
                VkSampler*:             vxDestroySampler \
            )(pContext, pResource))

#endif // __cplusplus

//------------------------------------------------------------------------------

// Assert Vulkan API function pointers are not null at the callsite.
#if !defined(VX_NO_FUNCTION_POINTER_VALIDATION)
    #if defined(VK_VERSION_1_0)
        #define vkAllocateCommandBuffers (vxAssert(vkAllocateCommandBuffers),vkAllocateCommandBuffers)
        #define vkAllocateDescriptorSets (vxAssert(vkAllocateDescriptorSets),vkAllocateDescriptorSets)
        #define vkAllocateMemory (vxAssert(vkAllocateMemory),vkAllocateMemory)
        #define vkBeginCommandBuffer (vxAssert(vkBeginCommandBuffer),vkBeginCommandBuffer)
        #define vkBindBufferMemory (vxAssert(vkBindBufferMemory),vkBindBufferMemory)
        #define vkBindImageMemory (vxAssert(vkBindImageMemory),vkBindImageMemory)
        #define vkCmdBeginQuery (vxAssert(vkCmdBeginQuery),vkCmdBeginQuery)
        #define vkCmdBeginRenderPass (vxAssert(vkCmdBeginRenderPass),vkCmdBeginRenderPass)
        #define vkCmdBindDescriptorSets (vxAssert(vkCmdBindDescriptorSets),vkCmdBindDescriptorSets)
        #define vkCmdBindIndexBuffer (vxAssert(vkCmdBindIndexBuffer),vkCmdBindIndexBuffer)
        #define vkCmdBindPipeline (vxAssert(vkCmdBindPipeline),vkCmdBindPipeline)
        #define vkCmdBindVertexBuffers (vxAssert(vkCmdBindVertexBuffers),vkCmdBindVertexBuffers)
        #define vkCmdBlitImage (vxAssert(vkCmdBlitImage),vkCmdBlitImage)
        #define vkCmdClearAttachments (vxAssert(vkCmdClearAttachments),vkCmdClearAttachments)
        #define vkCmdClearColorImage (vxAssert(vkCmdClearColorImage),vkCmdClearColorImage)
        #define vkCmdClearDepthStencilImage (vxAssert(vkCmdClearDepthStencilImage),vkCmdClearDepthStencilImage)
        #define vkCmdCopyBuffer (vxAssert(vkCmdCopyBuffer),vkCmdCopyBuffer)
        #define vkCmdCopyBufferToImage (vxAssert(vkCmdCopyBufferToImage),vkCmdCopyBufferToImage)
        #define vkCmdCopyImage (vxAssert(vkCmdCopyImage),vkCmdCopyImage)
        #define vkCmdCopyImageToBuffer (vxAssert(vkCmdCopyImageToBuffer),vkCmdCopyImageToBuffer)
        #define vkCmdCopyQueryPoolResults (vxAssert(vkCmdCopyQueryPoolResults),vkCmdCopyQueryPoolResults)
        #define vkCmdDispatch (vxAssert(vkCmdDispatch),vkCmdDispatch)
        #define vkCmdDispatchIndirect (vxAssert(vkCmdDispatchIndirect),vkCmdDispatchIndirect)
        #define vkCmdDraw (vxAssert(vkCmdDraw),vkCmdDraw)
        #define vkCmdDrawIndexed (vxAssert(vkCmdDrawIndexed),vkCmdDrawIndexed)
        #define vkCmdDrawIndexedIndirect (vxAssert(vkCmdDrawIndexedIndirect),vkCmdDrawIndexedIndirect)
        #define vkCmdDrawIndirect (vxAssert(vkCmdDrawIndirect),vkCmdDrawIndirect)
        #define vkCmdEndQuery (vxAssert(vkCmdEndQuery),vkCmdEndQuery)
        #define vkCmdEndRenderPass (vxAssert(vkCmdEndRenderPass),vkCmdEndRenderPass)
        #define vkCmdExecuteCommands (vxAssert(vkCmdExecuteCommands),vkCmdExecuteCommands)
        #define vkCmdFillBuffer (vxAssert(vkCmdFillBuffer),vkCmdFillBuffer)
        #define vkCmdNextSubpass (vxAssert(vkCmdNextSubpass),vkCmdNextSubpass)
        #define vkCmdPipelineBarrier (vxAssert(vkCmdPipelineBarrier),vkCmdPipelineBarrier)
        #define vkCmdPushConstants (vxAssert(vkCmdPushConstants),vkCmdPushConstants)
        #define vkCmdResetEvent (vxAssert(vkCmdResetEvent),vkCmdResetEvent)
        #define vkCmdResetQueryPool (vxAssert(vkCmdResetQueryPool),vkCmdResetQueryPool)
        #define vkCmdResolveImage (vxAssert(vkCmdResolveImage),vkCmdResolveImage)
        #define vkCmdSetBlendConstants (vxAssert(vkCmdSetBlendConstants),vkCmdSetBlendConstants)
        #define vkCmdSetDepthBias (vxAssert(vkCmdSetDepthBias),vkCmdSetDepthBias)
        #define vkCmdSetDepthBounds (vxAssert(vkCmdSetDepthBounds),vkCmdSetDepthBounds)
        #define vkCmdSetEvent (vxAssert(vkCmdSetEvent),vkCmdSetEvent)
        #define vkCmdSetLineWidth (vxAssert(vkCmdSetLineWidth),vkCmdSetLineWidth)
        #define vkCmdSetScissor (vxAssert(vkCmdSetScissor),vkCmdSetScissor)
        #define vkCmdSetStencilCompareMask (vxAssert(vkCmdSetStencilCompareMask),vkCmdSetStencilCompareMask)
        #define vkCmdSetStencilReference (vxAssert(vkCmdSetStencilReference),vkCmdSetStencilReference)
        #define vkCmdSetStencilWriteMask (vxAssert(vkCmdSetStencilWriteMask),vkCmdSetStencilWriteMask)
        #define vkCmdSetViewport (vxAssert(vkCmdSetViewport),vkCmdSetViewport)
        #define vkCmdUpdateBuffer (vxAssert(vkCmdUpdateBuffer),vkCmdUpdateBuffer)
        #define vkCmdWaitEvents (vxAssert(vkCmdWaitEvents),vkCmdWaitEvents)
        #define vkCmdWriteTimestamp (vxAssert(vkCmdWriteTimestamp),vkCmdWriteTimestamp)
        #define vkCreateBuffer (vxAssert(vkCreateBuffer),vkCreateBuffer)
        #define vkCreateBufferView (vxAssert(vkCreateBufferView),vkCreateBufferView)
        #define vkCreateCommandPool (vxAssert(vkCreateCommandPool),vkCreateCommandPool)
        #define vkCreateComputePipelines (vxAssert(vkCreateComputePipelines),vkCreateComputePipelines)
        #define vkCreateDescriptorPool (vxAssert(vkCreateDescriptorPool),vkCreateDescriptorPool)
        #define vkCreateDescriptorSetLayout (vxAssert(vkCreateDescriptorSetLayout),vkCreateDescriptorSetLayout)
        #define vkCreateEvent (vxAssert(vkCreateEvent),vkCreateEvent)
        #define vkCreateFence (vxAssert(vkCreateFence),vkCreateFence)
        #define vkCreateFramebuffer (vxAssert(vkCreateFramebuffer),vkCreateFramebuffer)
        #define vkCreateGraphicsPipelines (vxAssert(vkCreateGraphicsPipelines),vkCreateGraphicsPipelines)
        #define vkCreateImage (vxAssert(vkCreateImage),vkCreateImage)
        #define vkCreateImageView (vxAssert(vkCreateImageView),vkCreateImageView)
        #define vkCreatePipelineCache (vxAssert(vkCreatePipelineCache),vkCreatePipelineCache)
        #define vkCreatePipelineLayout (vxAssert(vkCreatePipelineLayout),vkCreatePipelineLayout)
        #define vkCreateQueryPool (vxAssert(vkCreateQueryPool),vkCreateQueryPool)
        #define vkCreateRenderPass (vxAssert(vkCreateRenderPass),vkCreateRenderPass)
        #define vkCreateSampler (vxAssert(vkCreateSampler),vkCreateSampler)
        #define vkCreateSemaphore (vxAssert(vkCreateSemaphore),vkCreateSemaphore)
        #define vkCreateShaderModule (vxAssert(vkCreateShaderModule),vkCreateShaderModule)
        #define vkDestroyBuffer (vxAssert(vkDestroyBuffer),vkDestroyBuffer)
        #define vkDestroyBufferView (vxAssert(vkDestroyBufferView),vkDestroyBufferView)
        #define vkDestroyCommandPool (vxAssert(vkDestroyCommandPool),vkDestroyCommandPool)
        #define vkDestroyDescriptorPool (vxAssert(vkDestroyDescriptorPool),vkDestroyDescriptorPool)
        #define vkDestroyDescriptorSetLayout (vxAssert(vkDestroyDescriptorSetLayout),vkDestroyDescriptorSetLayout)
        #define vkDestroyDevice (vxAssert(vkDestroyDevice),vkDestroyDevice)
        #define vkDestroyEvent (vxAssert(vkDestroyEvent),vkDestroyEvent)
        #define vkDestroyFence (vxAssert(vkDestroyFence),vkDestroyFence)
        #define vkDestroyFramebuffer (vxAssert(vkDestroyFramebuffer),vkDestroyFramebuffer)
        #define vkDestroyImage (vxAssert(vkDestroyImage),vkDestroyImage)
        #define vkDestroyImageView (vxAssert(vkDestroyImageView),vkDestroyImageView)
        #define vkDestroyPipeline (vxAssert(vkDestroyPipeline),vkDestroyPipeline)
        #define vkDestroyPipelineCache (vxAssert(vkDestroyPipelineCache),vkDestroyPipelineCache)
        #define vkDestroyPipelineLayout (vxAssert(vkDestroyPipelineLayout),vkDestroyPipelineLayout)
        #define vkDestroyQueryPool (vxAssert(vkDestroyQueryPool),vkDestroyQueryPool)
        #define vkDestroyRenderPass (vxAssert(vkDestroyRenderPass),vkDestroyRenderPass)
        #define vkDestroySampler (vxAssert(vkDestroySampler),vkDestroySampler)
        #define vkDestroySemaphore (vxAssert(vkDestroySemaphore),vkDestroySemaphore)
        #define vkDestroyShaderModule (vxAssert(vkDestroyShaderModule),vkDestroyShaderModule)
        #define vkDeviceWaitIdle (vxAssert(vkDeviceWaitIdle),vkDeviceWaitIdle)
        #define vkEndCommandBuffer (vxAssert(vkEndCommandBuffer),vkEndCommandBuffer)
        #define vkFlushMappedMemoryRanges (vxAssert(vkFlushMappedMemoryRanges),vkFlushMappedMemoryRanges)
        #define vkFreeCommandBuffers (vxAssert(vkFreeCommandBuffers),vkFreeCommandBuffers)
        #define vkFreeDescriptorSets (vxAssert(vkFreeDescriptorSets),vkFreeDescriptorSets)
        #define vkFreeMemory (vxAssert(vkFreeMemory),vkFreeMemory)
        #define vkGetBufferMemoryRequirements (vxAssert(vkGetBufferMemoryRequirements),vkGetBufferMemoryRequirements)
        #define vkGetDeviceMemoryCommitment (vxAssert(vkGetDeviceMemoryCommitment),vkGetDeviceMemoryCommitment)
        #define vkGetDeviceQueue (vxAssert(vkGetDeviceQueue),vkGetDeviceQueue)
        #define vkGetEventStatus (vxAssert(vkGetEventStatus),vkGetEventStatus)
        #define vkGetFenceStatus (vxAssert(vkGetFenceStatus),vkGetFenceStatus)
        #define vkGetImageMemoryRequirements (vxAssert(vkGetImageMemoryRequirements),vkGetImageMemoryRequirements)
        #define vkGetImageSparseMemoryRequirements (vxAssert(vkGetImageSparseMemoryRequirements),vkGetImageSparseMemoryRequirements)
        #define vkGetImageSubresourceLayout (vxAssert(vkGetImageSubresourceLayout),vkGetImageSubresourceLayout)
        #define vkGetPipelineCacheData (vxAssert(vkGetPipelineCacheData),vkGetPipelineCacheData)
        #define vkGetQueryPoolResults (vxAssert(vkGetQueryPoolResults),vkGetQueryPoolResults)
        #define vkGetRenderAreaGranularity (vxAssert(vkGetRenderAreaGranularity),vkGetRenderAreaGranularity)
        #define vkInvalidateMappedMemoryRanges (vxAssert(vkInvalidateMappedMemoryRanges),vkInvalidateMappedMemoryRanges)
        #define vkMapMemory (vxAssert(vkMapMemory),vkMapMemory)
        #define vkMergePipelineCaches (vxAssert(vkMergePipelineCaches),vkMergePipelineCaches)
        #define vkQueueBindSparse (vxAssert(vkQueueBindSparse),vkQueueBindSparse)
        #define vkQueueSubmit (vxAssert(vkQueueSubmit),vkQueueSubmit)
        #define vkQueueWaitIdle (vxAssert(vkQueueWaitIdle),vkQueueWaitIdle)
        #define vkResetCommandBuffer (vxAssert(vkResetCommandBuffer),vkResetCommandBuffer)
        #define vkResetCommandPool (vxAssert(vkResetCommandPool),vkResetCommandPool)
        #define vkResetDescriptorPool (vxAssert(vkResetDescriptorPool),vkResetDescriptorPool)
        #define vkResetEvent (vxAssert(vkResetEvent),vkResetEvent)
        #define vkResetFences (vxAssert(vkResetFences),vkResetFences)
        #define vkSetEvent (vxAssert(vkSetEvent),vkSetEvent)
        #define vkUnmapMemory (vxAssert(vkUnmapMemory),vkUnmapMemory)
        #define vkUpdateDescriptorSets (vxAssert(vkUpdateDescriptorSets),vkUpdateDescriptorSets)
        #define vkWaitForFences (vxAssert(vkWaitForFences),vkWaitForFences)
    #endif /* defined(VK_VERSION_1_0) */
    #if defined(VK_VERSION_1_1)
        #define vkBindBufferMemory2 (vxAssert(vkBindBufferMemory2),vkBindBufferMemory2)
        #define vkBindImageMemory2 (vxAssert(vkBindImageMemory2),vkBindImageMemory2)
        #define vkCmdDispatchBase (vxAssert(vkCmdDispatchBase),vkCmdDispatchBase)
        #define vkCmdSetDeviceMask (vxAssert(vkCmdSetDeviceMask),vkCmdSetDeviceMask)
        #define vkCreateDescriptorUpdateTemplate (vxAssert(vkCreateDescriptorUpdateTemplate),vkCreateDescriptorUpdateTemplate)
        #define vkCreateSamplerYcbcrConversion (vxAssert(vkCreateSamplerYcbcrConversion),vkCreateSamplerYcbcrConversion)
        #define vkDestroyDescriptorUpdateTemplate (vxAssert(vkDestroyDescriptorUpdateTemplate),vkDestroyDescriptorUpdateTemplate)
        #define vkDestroySamplerYcbcrConversion (vxAssert(vkDestroySamplerYcbcrConversion),vkDestroySamplerYcbcrConversion)
        #define vkGetBufferMemoryRequirements2 (vxAssert(vkGetBufferMemoryRequirements2),vkGetBufferMemoryRequirements2)
        #define vkGetDescriptorSetLayoutSupport (vxAssert(vkGetDescriptorSetLayoutSupport),vkGetDescriptorSetLayoutSupport)
        #define vkGetDeviceGroupPeerMemoryFeatures (vxAssert(vkGetDeviceGroupPeerMemoryFeatures),vkGetDeviceGroupPeerMemoryFeatures)
        #define vkGetDeviceQueue2 (vxAssert(vkGetDeviceQueue2),vkGetDeviceQueue2)
        #define vkGetImageMemoryRequirements2 (vxAssert(vkGetImageMemoryRequirements2),vkGetImageMemoryRequirements2)
        #define vkGetImageSparseMemoryRequirements2 (vxAssert(vkGetImageSparseMemoryRequirements2),vkGetImageSparseMemoryRequirements2)
        #define vkTrimCommandPool (vxAssert(vkTrimCommandPool),vkTrimCommandPool)
        #define vkUpdateDescriptorSetWithTemplate (vxAssert(vkUpdateDescriptorSetWithTemplate),vkUpdateDescriptorSetWithTemplate)
    #endif /* defined(VK_VERSION_1_1) */
    #if defined(VK_VERSION_1_2)
        #define vkCmdBeginRenderPass2 (vxAssert(vkCmdBeginRenderPass2),vkCmdBeginRenderPass2)
        #define vkCmdDrawIndexedIndirectCount (vxAssert(vkCmdDrawIndexedIndirectCount),vkCmdDrawIndexedIndirectCount)
        #define vkCmdDrawIndirectCount (vxAssert(vkCmdDrawIndirectCount),vkCmdDrawIndirectCount)
        #define vkCmdEndRenderPass2 (vxAssert(vkCmdEndRenderPass2),vkCmdEndRenderPass2)
        #define vkCmdNextSubpass2 (vxAssert(vkCmdNextSubpass2),vkCmdNextSubpass2)
        #define vkCreateRenderPass2 (vxAssert(vkCreateRenderPass2),vkCreateRenderPass2)
        #define vkGetBufferDeviceAddress (vxAssert(vkGetBufferDeviceAddress),vkGetBufferDeviceAddress)
        #define vkGetBufferOpaqueCaptureAddress (vxAssert(vkGetBufferOpaqueCaptureAddress),vkGetBufferOpaqueCaptureAddress)
        #define vkGetDeviceMemoryOpaqueCaptureAddress (vxAssert(vkGetDeviceMemoryOpaqueCaptureAddress),vkGetDeviceMemoryOpaqueCaptureAddress)
        #define vkGetSemaphoreCounterValue (vxAssert(vkGetSemaphoreCounterValue),vkGetSemaphoreCounterValue)
        #define vkResetQueryPool (vxAssert(vkResetQueryPool),vkResetQueryPool)
        #define vkSignalSemaphore (vxAssert(vkSignalSemaphore),vkSignalSemaphore)
        #define vkWaitSemaphores (vxAssert(vkWaitSemaphores),vkWaitSemaphores)
    #endif /* defined(VK_VERSION_1_2) */
    #if defined(VK_VERSION_1_3)
        #define vkCmdBeginRendering (vxAssert(vkCmdBeginRendering),vkCmdBeginRendering)
        #define vkCmdBindVertexBuffers2 (vxAssert(vkCmdBindVertexBuffers2),vkCmdBindVertexBuffers2)
        #define vkCmdBlitImage2 (vxAssert(vkCmdBlitImage2),vkCmdBlitImage2)
        #define vkCmdCopyBuffer2 (vxAssert(vkCmdCopyBuffer2),vkCmdCopyBuffer2)
        #define vkCmdCopyBufferToImage2 (vxAssert(vkCmdCopyBufferToImage2),vkCmdCopyBufferToImage2)
        #define vkCmdCopyImage2 (vxAssert(vkCmdCopyImage2),vkCmdCopyImage2)
        #define vkCmdCopyImageToBuffer2 (vxAssert(vkCmdCopyImageToBuffer2),vkCmdCopyImageToBuffer2)
        #define vkCmdEndRendering (vxAssert(vkCmdEndRendering),vkCmdEndRendering)
        #define vkCmdPipelineBarrier2 (vxAssert(vkCmdPipelineBarrier2),vkCmdPipelineBarrier2)
        #define vkCmdResetEvent2 (vxAssert(vkCmdResetEvent2),vkCmdResetEvent2)
        #define vkCmdResolveImage2 (vxAssert(vkCmdResolveImage2),vkCmdResolveImage2)
        #define vkCmdSetCullMode (vxAssert(vkCmdSetCullMode),vkCmdSetCullMode)
        #define vkCmdSetDepthBiasEnable (vxAssert(vkCmdSetDepthBiasEnable),vkCmdSetDepthBiasEnable)
        #define vkCmdSetDepthBoundsTestEnable (vxAssert(vkCmdSetDepthBoundsTestEnable),vkCmdSetDepthBoundsTestEnable)
        #define vkCmdSetDepthCompareOp (vxAssert(vkCmdSetDepthCompareOp),vkCmdSetDepthCompareOp)
        #define vkCmdSetDepthTestEnable (vxAssert(vkCmdSetDepthTestEnable),vkCmdSetDepthTestEnable)
        #define vkCmdSetDepthWriteEnable (vxAssert(vkCmdSetDepthWriteEnable),vkCmdSetDepthWriteEnable)
        #define vkCmdSetEvent2 (vxAssert(vkCmdSetEvent2),vkCmdSetEvent2)
        #define vkCmdSetFrontFace (vxAssert(vkCmdSetFrontFace),vkCmdSetFrontFace)
        #define vkCmdSetPrimitiveRestartEnable (vxAssert(vkCmdSetPrimitiveRestartEnable),vkCmdSetPrimitiveRestartEnable)
        #define vkCmdSetPrimitiveTopology (vxAssert(vkCmdSetPrimitiveTopology),vkCmdSetPrimitiveTopology)
        #define vkCmdSetRasterizerDiscardEnable (vxAssert(vkCmdSetRasterizerDiscardEnable),vkCmdSetRasterizerDiscardEnable)
        #define vkCmdSetScissorWithCount (vxAssert(vkCmdSetScissorWithCount),vkCmdSetScissorWithCount)
        #define vkCmdSetStencilOp (vxAssert(vkCmdSetStencilOp),vkCmdSetStencilOp)
        #define vkCmdSetStencilTestEnable (vxAssert(vkCmdSetStencilTestEnable),vkCmdSetStencilTestEnable)
        #define vkCmdSetViewportWithCount (vxAssert(vkCmdSetViewportWithCount),vkCmdSetViewportWithCount)
        #define vkCmdWaitEvents2 (vxAssert(vkCmdWaitEvents2),vkCmdWaitEvents2)
        #define vkCmdWriteTimestamp2 (vxAssert(vkCmdWriteTimestamp2),vkCmdWriteTimestamp2)
        #define vkCreatePrivateDataSlot (vxAssert(vkCreatePrivateDataSlot),vkCreatePrivateDataSlot)
        #define vkDestroyPrivateDataSlot (vxAssert(vkDestroyPrivateDataSlot),vkDestroyPrivateDataSlot)
        #define vkGetDeviceBufferMemoryRequirements (vxAssert(vkGetDeviceBufferMemoryRequirements),vkGetDeviceBufferMemoryRequirements)
        #define vkGetDeviceImageMemoryRequirements (vxAssert(vkGetDeviceImageMemoryRequirements),vkGetDeviceImageMemoryRequirements)
        #define vkGetDeviceImageSparseMemoryRequirements (vxAssert(vkGetDeviceImageSparseMemoryRequirements),vkGetDeviceImageSparseMemoryRequirements)
        #define vkGetPrivateData (vxAssert(vkGetPrivateData),vkGetPrivateData)
        #define vkQueueSubmit2 (vxAssert(vkQueueSubmit2),vkQueueSubmit2)
        #define vkSetPrivateData (vxAssert(vkSetPrivateData),vkSetPrivateData)
    #endif /* defined(VK_VERSION_1_3) */
    #if defined(VK_AMD_buffer_marker)
        #define vkCmdWriteBufferMarkerAMD (vxAssert(vkCmdWriteBufferMarkerAMD),vkCmdWriteBufferMarkerAMD)
    #endif /* defined(VK_AMD_buffer_marker) */
    #if defined(VK_AMD_display_native_hdr)
        #define vkSetLocalDimmingAMD (vxAssert(vkSetLocalDimmingAMD),vkSetLocalDimmingAMD)
    #endif /* defined(VK_AMD_display_native_hdr) */
    #if defined(VK_AMD_draw_indirect_count)
        #define vkCmdDrawIndexedIndirectCountAMD (vxAssert(vkCmdDrawIndexedIndirectCountAMD),vkCmdDrawIndexedIndirectCountAMD)
        #define vkCmdDrawIndirectCountAMD (vxAssert(vkCmdDrawIndirectCountAMD),vkCmdDrawIndirectCountAMD)
    #endif /* defined(VK_AMD_draw_indirect_count) */
    #if defined(VK_AMD_shader_info)
        #define vkGetShaderInfoAMD (vxAssert(vkGetShaderInfoAMD),vkGetShaderInfoAMD)
    #endif /* defined(VK_AMD_shader_info) */
    #if defined(VK_ANDROID_external_memory_android_hardware_buffer)
        #define vkGetAndroidHardwareBufferPropertiesANDROID (vxAssert(vkGetAndroidHardwareBufferPropertiesANDROID),vkGetAndroidHardwareBufferPropertiesANDROID)
        #define vkGetMemoryAndroidHardwareBufferANDROID (vxAssert(vkGetMemoryAndroidHardwareBufferANDROID),vkGetMemoryAndroidHardwareBufferANDROID)
    #endif /* defined(VK_ANDROID_external_memory_android_hardware_buffer) */
    #if defined(VK_EXT_buffer_device_address)
        #define vkGetBufferDeviceAddressEXT (vxAssert(vkGetBufferDeviceAddressEXT),vkGetBufferDeviceAddressEXT)
    #endif /* defined(VK_EXT_buffer_device_address) */
    #if defined(VK_EXT_calibrated_timestamps)
        #define vkGetCalibratedTimestampsEXT (vxAssert(vkGetCalibratedTimestampsEXT),vkGetCalibratedTimestampsEXT)
    #endif /* defined(VK_EXT_calibrated_timestamps) */
    #if defined(VK_EXT_color_write_enable)
        #define vkCmdSetColorWriteEnableEXT (vxAssert(vkCmdSetColorWriteEnableEXT),vkCmdSetColorWriteEnableEXT)
    #endif /* defined(VK_EXT_color_write_enable) */
    #if defined(VK_EXT_conditional_rendering)
        #define vkCmdBeginConditionalRenderingEXT (vxAssert(vkCmdBeginConditionalRenderingEXT),vkCmdBeginConditionalRenderingEXT)
        #define vkCmdEndConditionalRenderingEXT (vxAssert(vkCmdEndConditionalRenderingEXT),vkCmdEndConditionalRenderingEXT)
    #endif /* defined(VK_EXT_conditional_rendering) */
    #if defined(VK_EXT_debug_marker)
        #define vkCmdDebugMarkerBeginEXT (vxAssert(vkCmdDebugMarkerBeginEXT),vkCmdDebugMarkerBeginEXT)
        #define vkCmdDebugMarkerEndEXT (vxAssert(vkCmdDebugMarkerEndEXT),vkCmdDebugMarkerEndEXT)
        #define vkCmdDebugMarkerInsertEXT (vxAssert(vkCmdDebugMarkerInsertEXT),vkCmdDebugMarkerInsertEXT)
        #define vkDebugMarkerSetObjectNameEXT (vxAssert(vkDebugMarkerSetObjectNameEXT),vkDebugMarkerSetObjectNameEXT)
        #define vkDebugMarkerSetObjectTagEXT (vxAssert(vkDebugMarkerSetObjectTagEXT),vkDebugMarkerSetObjectTagEXT)
    #endif /* defined(VK_EXT_debug_marker) */
    #if defined(VK_EXT_descriptor_buffer)
        #define vkCmdBindDescriptorBufferEmbeddedSamplersEXT (vxAssert(vkCmdBindDescriptorBufferEmbeddedSamplersEXT),vkCmdBindDescriptorBufferEmbeddedSamplersEXT)
        #define vkCmdBindDescriptorBuffersEXT (vxAssert(vkCmdBindDescriptorBuffersEXT),vkCmdBindDescriptorBuffersEXT)
        #define vkCmdSetDescriptorBufferOffsetsEXT (vxAssert(vkCmdSetDescriptorBufferOffsetsEXT),vkCmdSetDescriptorBufferOffsetsEXT)
        #define vkGetBufferOpaqueCaptureDescriptorDataEXT (vxAssert(vkGetBufferOpaqueCaptureDescriptorDataEXT),vkGetBufferOpaqueCaptureDescriptorDataEXT)
        #define vkGetDescriptorEXT (vxAssert(vkGetDescriptorEXT),vkGetDescriptorEXT)
        #define vkGetDescriptorSetLayoutBindingOffsetEXT (vxAssert(vkGetDescriptorSetLayoutBindingOffsetEXT),vkGetDescriptorSetLayoutBindingOffsetEXT)
        #define vkGetDescriptorSetLayoutSizeEXT (vxAssert(vkGetDescriptorSetLayoutSizeEXT),vkGetDescriptorSetLayoutSizeEXT)
        #define vkGetImageOpaqueCaptureDescriptorDataEXT (vxAssert(vkGetImageOpaqueCaptureDescriptorDataEXT),vkGetImageOpaqueCaptureDescriptorDataEXT)
        #define vkGetImageViewOpaqueCaptureDescriptorDataEXT (vxAssert(vkGetImageViewOpaqueCaptureDescriptorDataEXT),vkGetImageViewOpaqueCaptureDescriptorDataEXT)
        #define vkGetSamplerOpaqueCaptureDescriptorDataEXT (vxAssert(vkGetSamplerOpaqueCaptureDescriptorDataEXT),vkGetSamplerOpaqueCaptureDescriptorDataEXT)
    #endif /* defined(VK_EXT_descriptor_buffer) */
    #if defined(VK_EXT_descriptor_buffer) && defined(VK_KHR_acceleration_structure) && defined(VK_NV_ray_tracing)
        #define vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT (vxAssert(vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT),vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT)
    #endif /* defined(VK_EXT_descriptor_buffer) && defined(VK_KHR_acceleration_structure) && defined(VK_NV_ray_tracing) */
    #if defined(VK_EXT_device_fault)
        #define vkGetDeviceFaultInfoEXT (vxAssert(vkGetDeviceFaultInfoEXT),vkGetDeviceFaultInfoEXT)
    #endif /* defined(VK_EXT_device_fault) */
    #if defined(VK_EXT_discard_rectangles)
        #define vkCmdSetDiscardRectangleEXT (vxAssert(vkCmdSetDiscardRectangleEXT),vkCmdSetDiscardRectangleEXT)
    #endif /* defined(VK_EXT_discard_rectangles) */
    #if defined(VK_EXT_display_control)
        #define vkDisplayPowerControlEXT (vxAssert(vkDisplayPowerControlEXT),vkDisplayPowerControlEXT)
        #define vkGetSwapchainCounterEXT (vxAssert(vkGetSwapchainCounterEXT),vkGetSwapchainCounterEXT)
        #define vkRegisterDeviceEventEXT (vxAssert(vkRegisterDeviceEventEXT),vkRegisterDeviceEventEXT)
        #define vkRegisterDisplayEventEXT (vxAssert(vkRegisterDisplayEventEXT),vkRegisterDisplayEventEXT)
    #endif /* defined(VK_EXT_display_control) */
    #if defined(VK_EXT_extended_dynamic_state)
        #define vkCmdBindVertexBuffers2EXT (vxAssert(vkCmdBindVertexBuffers2EXT),vkCmdBindVertexBuffers2EXT)
        #define vkCmdSetCullModeEXT (vxAssert(vkCmdSetCullModeEXT),vkCmdSetCullModeEXT)
        #define vkCmdSetDepthBoundsTestEnableEXT (vxAssert(vkCmdSetDepthBoundsTestEnableEXT),vkCmdSetDepthBoundsTestEnableEXT)
        #define vkCmdSetDepthCompareOpEXT (vxAssert(vkCmdSetDepthCompareOpEXT),vkCmdSetDepthCompareOpEXT)
        #define vkCmdSetDepthTestEnableEXT (vxAssert(vkCmdSetDepthTestEnableEXT),vkCmdSetDepthTestEnableEXT)
        #define vkCmdSetDepthWriteEnableEXT (vxAssert(vkCmdSetDepthWriteEnableEXT),vkCmdSetDepthWriteEnableEXT)
        #define vkCmdSetFrontFaceEXT (vxAssert(vkCmdSetFrontFaceEXT),vkCmdSetFrontFaceEXT)
        #define vkCmdSetPrimitiveTopologyEXT (vxAssert(vkCmdSetPrimitiveTopologyEXT),vkCmdSetPrimitiveTopologyEXT)
        #define vkCmdSetScissorWithCountEXT (vxAssert(vkCmdSetScissorWithCountEXT),vkCmdSetScissorWithCountEXT)
        #define vkCmdSetStencilOpEXT (vxAssert(vkCmdSetStencilOpEXT),vkCmdSetStencilOpEXT)
        #define vkCmdSetStencilTestEnableEXT (vxAssert(vkCmdSetStencilTestEnableEXT),vkCmdSetStencilTestEnableEXT)
        #define vkCmdSetViewportWithCountEXT (vxAssert(vkCmdSetViewportWithCountEXT),vkCmdSetViewportWithCountEXT)
    #endif /* defined(VK_EXT_extended_dynamic_state) */
    #if defined(VK_EXT_extended_dynamic_state2)
        #define vkCmdSetDepthBiasEnableEXT (vxAssert(vkCmdSetDepthBiasEnableEXT),vkCmdSetDepthBiasEnableEXT)
        #define vkCmdSetLogicOpEXT (vxAssert(vkCmdSetLogicOpEXT),vkCmdSetLogicOpEXT)
        #define vkCmdSetPatchControlPointsEXT (vxAssert(vkCmdSetPatchControlPointsEXT),vkCmdSetPatchControlPointsEXT)
        #define vkCmdSetPrimitiveRestartEnableEXT (vxAssert(vkCmdSetPrimitiveRestartEnableEXT),vkCmdSetPrimitiveRestartEnableEXT)
        #define vkCmdSetRasterizerDiscardEnableEXT (vxAssert(vkCmdSetRasterizerDiscardEnableEXT),vkCmdSetRasterizerDiscardEnableEXT)
    #endif /* defined(VK_EXT_extended_dynamic_state2) */
    #if defined(VK_EXT_extended_dynamic_state3)
        #define vkCmdSetAlphaToCoverageEnableEXT (vxAssert(vkCmdSetAlphaToCoverageEnableEXT),vkCmdSetAlphaToCoverageEnableEXT)
        #define vkCmdSetAlphaToOneEnableEXT (vxAssert(vkCmdSetAlphaToOneEnableEXT),vkCmdSetAlphaToOneEnableEXT)
        #define vkCmdSetColorBlendAdvancedEXT (vxAssert(vkCmdSetColorBlendAdvancedEXT),vkCmdSetColorBlendAdvancedEXT)
        #define vkCmdSetColorBlendEnableEXT (vxAssert(vkCmdSetColorBlendEnableEXT),vkCmdSetColorBlendEnableEXT)
        #define vkCmdSetColorBlendEquationEXT (vxAssert(vkCmdSetColorBlendEquationEXT),vkCmdSetColorBlendEquationEXT)
        #define vkCmdSetColorWriteMaskEXT (vxAssert(vkCmdSetColorWriteMaskEXT),vkCmdSetColorWriteMaskEXT)
        #define vkCmdSetConservativeRasterizationModeEXT (vxAssert(vkCmdSetConservativeRasterizationModeEXT),vkCmdSetConservativeRasterizationModeEXT)
        #define vkCmdSetCoverageModulationModeNV (vxAssert(vkCmdSetCoverageModulationModeNV),vkCmdSetCoverageModulationModeNV)
        #define vkCmdSetCoverageModulationTableEnableNV (vxAssert(vkCmdSetCoverageModulationTableEnableNV),vkCmdSetCoverageModulationTableEnableNV)
        #define vkCmdSetCoverageModulationTableNV (vxAssert(vkCmdSetCoverageModulationTableNV),vkCmdSetCoverageModulationTableNV)
        #define vkCmdSetCoverageReductionModeNV (vxAssert(vkCmdSetCoverageReductionModeNV),vkCmdSetCoverageReductionModeNV)
        #define vkCmdSetCoverageToColorEnableNV (vxAssert(vkCmdSetCoverageToColorEnableNV),vkCmdSetCoverageToColorEnableNV)
        #define vkCmdSetCoverageToColorLocationNV (vxAssert(vkCmdSetCoverageToColorLocationNV),vkCmdSetCoverageToColorLocationNV)
        #define vkCmdSetDepthClampEnableEXT (vxAssert(vkCmdSetDepthClampEnableEXT),vkCmdSetDepthClampEnableEXT)
        #define vkCmdSetDepthClipEnableEXT (vxAssert(vkCmdSetDepthClipEnableEXT),vkCmdSetDepthClipEnableEXT)
        #define vkCmdSetDepthClipNegativeOneToOneEXT (vxAssert(vkCmdSetDepthClipNegativeOneToOneEXT),vkCmdSetDepthClipNegativeOneToOneEXT)
        #define vkCmdSetExtraPrimitiveOverestimationSizeEXT (vxAssert(vkCmdSetExtraPrimitiveOverestimationSizeEXT),vkCmdSetExtraPrimitiveOverestimationSizeEXT)
        #define vkCmdSetLineRasterizationModeEXT (vxAssert(vkCmdSetLineRasterizationModeEXT),vkCmdSetLineRasterizationModeEXT)
        #define vkCmdSetLineStippleEnableEXT (vxAssert(vkCmdSetLineStippleEnableEXT),vkCmdSetLineStippleEnableEXT)
        #define vkCmdSetLogicOpEnableEXT (vxAssert(vkCmdSetLogicOpEnableEXT),vkCmdSetLogicOpEnableEXT)
        #define vkCmdSetPolygonModeEXT (vxAssert(vkCmdSetPolygonModeEXT),vkCmdSetPolygonModeEXT)
        #define vkCmdSetProvokingVertexModeEXT (vxAssert(vkCmdSetProvokingVertexModeEXT),vkCmdSetProvokingVertexModeEXT)
        #define vkCmdSetRasterizationSamplesEXT (vxAssert(vkCmdSetRasterizationSamplesEXT),vkCmdSetRasterizationSamplesEXT)
        #define vkCmdSetRasterizationStreamEXT (vxAssert(vkCmdSetRasterizationStreamEXT),vkCmdSetRasterizationStreamEXT)
        #define vkCmdSetRepresentativeFragmentTestEnableNV (vxAssert(vkCmdSetRepresentativeFragmentTestEnableNV),vkCmdSetRepresentativeFragmentTestEnableNV)
        #define vkCmdSetSampleLocationsEnableEXT (vxAssert(vkCmdSetSampleLocationsEnableEXT),vkCmdSetSampleLocationsEnableEXT)
        #define vkCmdSetSampleMaskEXT (vxAssert(vkCmdSetSampleMaskEXT),vkCmdSetSampleMaskEXT)
        #define vkCmdSetShadingRateImageEnableNV (vxAssert(vkCmdSetShadingRateImageEnableNV),vkCmdSetShadingRateImageEnableNV)
        #define vkCmdSetTessellationDomainOriginEXT (vxAssert(vkCmdSetTessellationDomainOriginEXT),vkCmdSetTessellationDomainOriginEXT)
        #define vkCmdSetViewportSwizzleNV (vxAssert(vkCmdSetViewportSwizzleNV),vkCmdSetViewportSwizzleNV)
        #define vkCmdSetViewportWScalingEnableNV (vxAssert(vkCmdSetViewportWScalingEnableNV),vkCmdSetViewportWScalingEnableNV)
    #endif /* defined(VK_EXT_extended_dynamic_state3) */
    #if defined(VK_EXT_external_memory_host)
        #define vkGetMemoryHostPointerPropertiesEXT (vxAssert(vkGetMemoryHostPointerPropertiesEXT),vkGetMemoryHostPointerPropertiesEXT)
    #endif /* defined(VK_EXT_external_memory_host) */
    #if defined(VK_EXT_full_screen_exclusive)
        #define vkAcquireFullScreenExclusiveModeEXT (vxAssert(vkAcquireFullScreenExclusiveModeEXT),vkAcquireFullScreenExclusiveModeEXT)
        #define vkReleaseFullScreenExclusiveModeEXT (vxAssert(vkReleaseFullScreenExclusiveModeEXT),vkReleaseFullScreenExclusiveModeEXT)
    #endif /* defined(VK_EXT_full_screen_exclusive) */
    #if defined(VK_EXT_hdr_metadata)
        #define vkSetHdrMetadataEXT (vxAssert(vkSetHdrMetadataEXT),vkSetHdrMetadataEXT)
    #endif /* defined(VK_EXT_hdr_metadata) */
    #if defined(VK_EXT_host_query_reset)
        #define vkResetQueryPoolEXT (vxAssert(vkResetQueryPoolEXT),vkResetQueryPoolEXT)
    #endif /* defined(VK_EXT_host_query_reset) */
    #if defined(VK_EXT_image_compression_control)
        #define vkGetImageSubresourceLayout2EXT (vxAssert(vkGetImageSubresourceLayout2EXT),vkGetImageSubresourceLayout2EXT)
    #endif /* defined(VK_EXT_image_compression_control) */
    #if defined(VK_EXT_image_drm_format_modifier)
        #define vkGetImageDrmFormatModifierPropertiesEXT (vxAssert(vkGetImageDrmFormatModifierPropertiesEXT),vkGetImageDrmFormatModifierPropertiesEXT)
    #endif /* defined(VK_EXT_image_drm_format_modifier) */
    #if defined(VK_EXT_line_rasterization)
        #define vkCmdSetLineStippleEXT (vxAssert(vkCmdSetLineStippleEXT),vkCmdSetLineStippleEXT)
    #endif /* defined(VK_EXT_line_rasterization) */
    #if defined(VK_EXT_mesh_shader)
        #define vkCmdDrawMeshTasksEXT (vxAssert(vkCmdDrawMeshTasksEXT),vkCmdDrawMeshTasksEXT)
        #define vkCmdDrawMeshTasksIndirectCountEXT (vxAssert(vkCmdDrawMeshTasksIndirectCountEXT),vkCmdDrawMeshTasksIndirectCountEXT)
        #define vkCmdDrawMeshTasksIndirectEXT (vxAssert(vkCmdDrawMeshTasksIndirectEXT),vkCmdDrawMeshTasksIndirectEXT)
    #endif /* defined(VK_EXT_mesh_shader) */
    #if defined(VK_EXT_metal_objects)
        #define vkExportMetalObjectsEXT (vxAssert(vkExportMetalObjectsEXT),vkExportMetalObjectsEXT)
    #endif /* defined(VK_EXT_metal_objects) */
    #if defined(VK_EXT_multi_draw)
        #define vkCmdDrawMultiEXT (vxAssert(vkCmdDrawMultiEXT),vkCmdDrawMultiEXT)
        #define vkCmdDrawMultiIndexedEXT (vxAssert(vkCmdDrawMultiIndexedEXT),vkCmdDrawMultiIndexedEXT)
    #endif /* defined(VK_EXT_multi_draw) */
    #if defined(VK_EXT_opacity_micromap)
        #define vkBuildMicromapsEXT (vxAssert(vkBuildMicromapsEXT),vkBuildMicromapsEXT)
        #define vkCmdBuildMicromapsEXT (vxAssert(vkCmdBuildMicromapsEXT),vkCmdBuildMicromapsEXT)
        #define vkCmdCopyMemoryToMicromapEXT (vxAssert(vkCmdCopyMemoryToMicromapEXT),vkCmdCopyMemoryToMicromapEXT)
        #define vkCmdCopyMicromapEXT (vxAssert(vkCmdCopyMicromapEXT),vkCmdCopyMicromapEXT)
        #define vkCmdCopyMicromapToMemoryEXT (vxAssert(vkCmdCopyMicromapToMemoryEXT),vkCmdCopyMicromapToMemoryEXT)
        #define vkCmdWriteMicromapsPropertiesEXT (vxAssert(vkCmdWriteMicromapsPropertiesEXT),vkCmdWriteMicromapsPropertiesEXT)
        #define vkCopyMemoryToMicromapEXT (vxAssert(vkCopyMemoryToMicromapEXT),vkCopyMemoryToMicromapEXT)
        #define vkCopyMicromapEXT (vxAssert(vkCopyMicromapEXT),vkCopyMicromapEXT)
        #define vkCopyMicromapToMemoryEXT (vxAssert(vkCopyMicromapToMemoryEXT),vkCopyMicromapToMemoryEXT)
        #define vkCreateMicromapEXT (vxAssert(vkCreateMicromapEXT),vkCreateMicromapEXT)
        #define vkDestroyMicromapEXT (vxAssert(vkDestroyMicromapEXT),vkDestroyMicromapEXT)
        #define vkGetDeviceMicromapCompatibilityEXT (vxAssert(vkGetDeviceMicromapCompatibilityEXT),vkGetDeviceMicromapCompatibilityEXT)
        #define vkGetMicromapBuildSizesEXT (vxAssert(vkGetMicromapBuildSizesEXT),vkGetMicromapBuildSizesEXT)
        #define vkWriteMicromapsPropertiesEXT (vxAssert(vkWriteMicromapsPropertiesEXT),vkWriteMicromapsPropertiesEXT)
    #endif /* defined(VK_EXT_opacity_micromap) */
    #if defined(VK_EXT_pageable_device_local_memory)
        #define vkSetDeviceMemoryPriorityEXT (vxAssert(vkSetDeviceMemoryPriorityEXT),vkSetDeviceMemoryPriorityEXT)
    #endif /* defined(VK_EXT_pageable_device_local_memory) */
    #if defined(VK_EXT_pipeline_properties)
        #define vkGetPipelinePropertiesEXT (vxAssert(vkGetPipelinePropertiesEXT),vkGetPipelinePropertiesEXT)
    #endif /* defined(VK_EXT_pipeline_properties) */
    #if defined(VK_EXT_private_data)
        #define vkCreatePrivateDataSlotEXT (vxAssert(vkCreatePrivateDataSlotEXT),vkCreatePrivateDataSlotEXT)
        #define vkDestroyPrivateDataSlotEXT (vxAssert(vkDestroyPrivateDataSlotEXT),vkDestroyPrivateDataSlotEXT)
        #define vkGetPrivateDataEXT (vxAssert(vkGetPrivateDataEXT),vkGetPrivateDataEXT)
        #define vkSetPrivateDataEXT (vxAssert(vkSetPrivateDataEXT),vkSetPrivateDataEXT)
    #endif /* defined(VK_EXT_private_data) */
    #if defined(VK_EXT_sample_locations)
        #define vkCmdSetSampleLocationsEXT (vxAssert(vkCmdSetSampleLocationsEXT),vkCmdSetSampleLocationsEXT)
    #endif /* defined(VK_EXT_sample_locations) */
    #if defined(VK_EXT_shader_module_identifier)
        #define vkGetShaderModuleCreateInfoIdentifierEXT (vxAssert(vkGetShaderModuleCreateInfoIdentifierEXT),vkGetShaderModuleCreateInfoIdentifierEXT)
        #define vkGetShaderModuleIdentifierEXT (vxAssert(vkGetShaderModuleIdentifierEXT),vkGetShaderModuleIdentifierEXT)
    #endif /* defined(VK_EXT_shader_module_identifier) */
    #if defined(VK_EXT_swapchain_maintenance1)
        #define vkReleaseSwapchainImagesEXT (vxAssert(vkReleaseSwapchainImagesEXT),vkReleaseSwapchainImagesEXT)
    #endif /* defined(VK_EXT_swapchain_maintenance1) */
    #if defined(VK_EXT_transform_feedback)
        #define vkCmdBeginQueryIndexedEXT (vxAssert(vkCmdBeginQueryIndexedEXT),vkCmdBeginQueryIndexedEXT)
        #define vkCmdBeginTransformFeedbackEXT (vxAssert(vkCmdBeginTransformFeedbackEXT),vkCmdBeginTransformFeedbackEXT)
        #define vkCmdBindTransformFeedbackBuffersEXT (vxAssert(vkCmdBindTransformFeedbackBuffersEXT),vkCmdBindTransformFeedbackBuffersEXT)
        #define vkCmdDrawIndirectByteCountEXT (vxAssert(vkCmdDrawIndirectByteCountEXT),vkCmdDrawIndirectByteCountEXT)
        #define vkCmdEndQueryIndexedEXT (vxAssert(vkCmdEndQueryIndexedEXT),vkCmdEndQueryIndexedEXT)
        #define vkCmdEndTransformFeedbackEXT (vxAssert(vkCmdEndTransformFeedbackEXT),vkCmdEndTransformFeedbackEXT)
    #endif /* defined(VK_EXT_transform_feedback) */
    #if defined(VK_EXT_validation_cache)
        #define vkCreateValidationCacheEXT (vxAssert(vkCreateValidationCacheEXT),vkCreateValidationCacheEXT)
        #define vkDestroyValidationCacheEXT (vxAssert(vkDestroyValidationCacheEXT),vkDestroyValidationCacheEXT)
        #define vkGetValidationCacheDataEXT (vxAssert(vkGetValidationCacheDataEXT),vkGetValidationCacheDataEXT)
        #define vkMergeValidationCachesEXT (vxAssert(vkMergeValidationCachesEXT),vkMergeValidationCachesEXT)
    #endif /* defined(VK_EXT_validation_cache) */
    #if defined(VK_EXT_vertex_input_dynamic_state)
        #define vkCmdSetVertexInputEXT (vxAssert(vkCmdSetVertexInputEXT),vkCmdSetVertexInputEXT)
    #endif /* defined(VK_EXT_vertex_input_dynamic_state) */
    #if defined(VK_FUCHSIA_buffer_collection)
        #define vkCreateBufferCollectionFUCHSIA (vxAssert(vkCreateBufferCollectionFUCHSIA),vkCreateBufferCollectionFUCHSIA)
        #define vkDestroyBufferCollectionFUCHSIA (vxAssert(vkDestroyBufferCollectionFUCHSIA),vkDestroyBufferCollectionFUCHSIA)
        #define vkGetBufferCollectionPropertiesFUCHSIA (vxAssert(vkGetBufferCollectionPropertiesFUCHSIA),vkGetBufferCollectionPropertiesFUCHSIA)
        #define vkSetBufferCollectionBufferConstraintsFUCHSIA (vxAssert(vkSetBufferCollectionBufferConstraintsFUCHSIA),vkSetBufferCollectionBufferConstraintsFUCHSIA)
        #define vkSetBufferCollectionImageConstraintsFUCHSIA (vxAssert(vkSetBufferCollectionImageConstraintsFUCHSIA),vkSetBufferCollectionImageConstraintsFUCHSIA)
    #endif /* defined(VK_FUCHSIA_buffer_collection) */
    #if defined(VK_FUCHSIA_external_memory)
        #define vkGetMemoryZirconHandleFUCHSIA (vxAssert(vkGetMemoryZirconHandleFUCHSIA),vkGetMemoryZirconHandleFUCHSIA)
        #define vkGetMemoryZirconHandlePropertiesFUCHSIA (vxAssert(vkGetMemoryZirconHandlePropertiesFUCHSIA),vkGetMemoryZirconHandlePropertiesFUCHSIA)
    #endif /* defined(VK_FUCHSIA_external_memory) */
    #if defined(VK_FUCHSIA_external_semaphore)
        #define vkGetSemaphoreZirconHandleFUCHSIA (vxAssert(vkGetSemaphoreZirconHandleFUCHSIA),vkGetSemaphoreZirconHandleFUCHSIA)
        #define vkImportSemaphoreZirconHandleFUCHSIA (vxAssert(vkImportSemaphoreZirconHandleFUCHSIA),vkImportSemaphoreZirconHandleFUCHSIA)
    #endif /* defined(VK_FUCHSIA_external_semaphore) */
    #if defined(VK_GOOGLE_display_timing)
        #define vkGetPastPresentationTimingGOOGLE (vxAssert(vkGetPastPresentationTimingGOOGLE),vkGetPastPresentationTimingGOOGLE)
        #define vkGetRefreshCycleDurationGOOGLE (vxAssert(vkGetRefreshCycleDurationGOOGLE),vkGetRefreshCycleDurationGOOGLE)
    #endif /* defined(VK_GOOGLE_display_timing) */
    #if defined(VK_HUAWEI_cluster_culling_shader)
        #define vkCmdDrawClusterHUAWEI (vxAssert(vkCmdDrawClusterHUAWEI),vkCmdDrawClusterHUAWEI)
        #define vkCmdDrawClusterIndirectHUAWEI (vxAssert(vkCmdDrawClusterIndirectHUAWEI),vkCmdDrawClusterIndirectHUAWEI)
    #endif /* defined(VK_HUAWEI_cluster_culling_shader) */
    #if defined(VK_HUAWEI_invocation_mask)
        #define vkCmdBindInvocationMaskHUAWEI (vxAssert(vkCmdBindInvocationMaskHUAWEI),vkCmdBindInvocationMaskHUAWEI)
    #endif /* defined(VK_HUAWEI_invocation_mask) */
    #if defined(VK_HUAWEI_subpass_shading)
        #define vkCmdSubpassShadingHUAWEI (vxAssert(vkCmdSubpassShadingHUAWEI),vkCmdSubpassShadingHUAWEI)
        #define vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI (vxAssert(vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI),vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI)
    #endif /* defined(VK_HUAWEI_subpass_shading) */
    #if defined(VK_INTEL_performance_query)
        #define vkAcquirePerformanceConfigurationINTEL (vxAssert(vkAcquirePerformanceConfigurationINTEL),vkAcquirePerformanceConfigurationINTEL)
        #define vkCmdSetPerformanceMarkerINTEL (vxAssert(vkCmdSetPerformanceMarkerINTEL),vkCmdSetPerformanceMarkerINTEL)
        #define vkCmdSetPerformanceOverrideINTEL (vxAssert(vkCmdSetPerformanceOverrideINTEL),vkCmdSetPerformanceOverrideINTEL)
        #define vkCmdSetPerformanceStreamMarkerINTEL (vxAssert(vkCmdSetPerformanceStreamMarkerINTEL),vkCmdSetPerformanceStreamMarkerINTEL)
        #define vkGetPerformanceParameterINTEL (vxAssert(vkGetPerformanceParameterINTEL),vkGetPerformanceParameterINTEL)
        #define vkInitializePerformanceApiINTEL (vxAssert(vkInitializePerformanceApiINTEL),vkInitializePerformanceApiINTEL)
        #define vkQueueSetPerformanceConfigurationINTEL (vxAssert(vkQueueSetPerformanceConfigurationINTEL),vkQueueSetPerformanceConfigurationINTEL)
        #define vkReleasePerformanceConfigurationINTEL (vxAssert(vkReleasePerformanceConfigurationINTEL),vkReleasePerformanceConfigurationINTEL)
        #define vkUninitializePerformanceApiINTEL (vxAssert(vkUninitializePerformanceApiINTEL),vkUninitializePerformanceApiINTEL)
    #endif /* defined(VK_INTEL_performance_query) */
    #if defined(VK_KHR_acceleration_structure)
        #define vkBuildAccelerationStructuresKHR (vxAssert(vkBuildAccelerationStructuresKHR),vkBuildAccelerationStructuresKHR)
        #define vkCmdBuildAccelerationStructuresIndirectKHR (vxAssert(vkCmdBuildAccelerationStructuresIndirectKHR),vkCmdBuildAccelerationStructuresIndirectKHR)
        #define vkCmdBuildAccelerationStructuresKHR (vxAssert(vkCmdBuildAccelerationStructuresKHR),vkCmdBuildAccelerationStructuresKHR)
        #define vkCmdCopyAccelerationStructureKHR (vxAssert(vkCmdCopyAccelerationStructureKHR),vkCmdCopyAccelerationStructureKHR)
        #define vkCmdCopyAccelerationStructureToMemoryKHR (vxAssert(vkCmdCopyAccelerationStructureToMemoryKHR),vkCmdCopyAccelerationStructureToMemoryKHR)
        #define vkCmdCopyMemoryToAccelerationStructureKHR (vxAssert(vkCmdCopyMemoryToAccelerationStructureKHR),vkCmdCopyMemoryToAccelerationStructureKHR)
        #define vkCmdWriteAccelerationStructuresPropertiesKHR (vxAssert(vkCmdWriteAccelerationStructuresPropertiesKHR),vkCmdWriteAccelerationStructuresPropertiesKHR)
        #define vkCopyAccelerationStructureKHR (vxAssert(vkCopyAccelerationStructureKHR),vkCopyAccelerationStructureKHR)
        #define vkCopyAccelerationStructureToMemoryKHR (vxAssert(vkCopyAccelerationStructureToMemoryKHR),vkCopyAccelerationStructureToMemoryKHR)
        #define vkCopyMemoryToAccelerationStructureKHR (vxAssert(vkCopyMemoryToAccelerationStructureKHR),vkCopyMemoryToAccelerationStructureKHR)
        #define vkCreateAccelerationStructureKHR (vxAssert(vkCreateAccelerationStructureKHR),vkCreateAccelerationStructureKHR)
        #define vkDestroyAccelerationStructureKHR (vxAssert(vkDestroyAccelerationStructureKHR),vkDestroyAccelerationStructureKHR)
        #define vkGetAccelerationStructureBuildSizesKHR (vxAssert(vkGetAccelerationStructureBuildSizesKHR),vkGetAccelerationStructureBuildSizesKHR)
        #define vkGetAccelerationStructureDeviceAddressKHR (vxAssert(vkGetAccelerationStructureDeviceAddressKHR),vkGetAccelerationStructureDeviceAddressKHR)
        #define vkGetDeviceAccelerationStructureCompatibilityKHR (vxAssert(vkGetDeviceAccelerationStructureCompatibilityKHR),vkGetDeviceAccelerationStructureCompatibilityKHR)
        #define vkWriteAccelerationStructuresPropertiesKHR (vxAssert(vkWriteAccelerationStructuresPropertiesKHR),vkWriteAccelerationStructuresPropertiesKHR)
    #endif /* defined(VK_KHR_acceleration_structure) */
    #if defined(VK_KHR_bind_memory2)
        #define vkBindBufferMemory2KHR (vxAssert(vkBindBufferMemory2KHR),vkBindBufferMemory2KHR)
        #define vkBindImageMemory2KHR (vxAssert(vkBindImageMemory2KHR),vkBindImageMemory2KHR)
    #endif /* defined(VK_KHR_bind_memory2) */
    #if defined(VK_KHR_buffer_device_address)
        #define vkGetBufferDeviceAddressKHR (vxAssert(vkGetBufferDeviceAddressKHR),vkGetBufferDeviceAddressKHR)
        #define vkGetBufferOpaqueCaptureAddressKHR (vxAssert(vkGetBufferOpaqueCaptureAddressKHR),vkGetBufferOpaqueCaptureAddressKHR)
        #define vkGetDeviceMemoryOpaqueCaptureAddressKHR (vxAssert(vkGetDeviceMemoryOpaqueCaptureAddressKHR),vkGetDeviceMemoryOpaqueCaptureAddressKHR)
    #endif /* defined(VK_KHR_buffer_device_address) */
    #if defined(VK_KHR_copy_commands2)
        #define vkCmdBlitImage2KHR (vxAssert(vkCmdBlitImage2KHR),vkCmdBlitImage2KHR)
        #define vkCmdCopyBuffer2KHR (vxAssert(vkCmdCopyBuffer2KHR),vkCmdCopyBuffer2KHR)
        #define vkCmdCopyBufferToImage2KHR (vxAssert(vkCmdCopyBufferToImage2KHR),vkCmdCopyBufferToImage2KHR)
        #define vkCmdCopyImage2KHR (vxAssert(vkCmdCopyImage2KHR),vkCmdCopyImage2KHR)
        #define vkCmdCopyImageToBuffer2KHR (vxAssert(vkCmdCopyImageToBuffer2KHR),vkCmdCopyImageToBuffer2KHR)
        #define vkCmdResolveImage2KHR (vxAssert(vkCmdResolveImage2KHR),vkCmdResolveImage2KHR)
    #endif /* defined(VK_KHR_copy_commands2) */
    #if defined(VK_KHR_create_renderpass2)
        #define vkCmdBeginRenderPass2KHR (vxAssert(vkCmdBeginRenderPass2KHR),vkCmdBeginRenderPass2KHR)
        #define vkCmdEndRenderPass2KHR (vxAssert(vkCmdEndRenderPass2KHR),vkCmdEndRenderPass2KHR)
        #define vkCmdNextSubpass2KHR (vxAssert(vkCmdNextSubpass2KHR),vkCmdNextSubpass2KHR)
        #define vkCreateRenderPass2KHR (vxAssert(vkCreateRenderPass2KHR),vkCreateRenderPass2KHR)
    #endif /* defined(VK_KHR_create_renderpass2) */
    #if defined(VK_KHR_deferred_host_operations)
        #define vkCreateDeferredOperationKHR (vxAssert(vkCreateDeferredOperationKHR),vkCreateDeferredOperationKHR)
        #define vkDeferredOperationJoinKHR (vxAssert(vkDeferredOperationJoinKHR),vkDeferredOperationJoinKHR)
        #define vkDestroyDeferredOperationKHR (vxAssert(vkDestroyDeferredOperationKHR),vkDestroyDeferredOperationKHR)
        #define vkGetDeferredOperationMaxConcurrencyKHR (vxAssert(vkGetDeferredOperationMaxConcurrencyKHR),vkGetDeferredOperationMaxConcurrencyKHR)
        #define vkGetDeferredOperationResultKHR (vxAssert(vkGetDeferredOperationResultKHR),vkGetDeferredOperationResultKHR)
    #endif /* defined(VK_KHR_deferred_host_operations) */
    #if defined(VK_KHR_descriptor_update_template)
        #define vkCreateDescriptorUpdateTemplateKHR (vxAssert(vkCreateDescriptorUpdateTemplateKHR),vkCreateDescriptorUpdateTemplateKHR)
        #define vkDestroyDescriptorUpdateTemplateKHR (vxAssert(vkDestroyDescriptorUpdateTemplateKHR),vkDestroyDescriptorUpdateTemplateKHR)
        #define vkUpdateDescriptorSetWithTemplateKHR (vxAssert(vkUpdateDescriptorSetWithTemplateKHR),vkUpdateDescriptorSetWithTemplateKHR)
    #endif /* defined(VK_KHR_descriptor_update_template) */
    #if defined(VK_KHR_device_group)
        #define vkCmdDispatchBaseKHR (vxAssert(vkCmdDispatchBaseKHR),vkCmdDispatchBaseKHR)
        #define vkCmdSetDeviceMaskKHR (vxAssert(vkCmdSetDeviceMaskKHR),vkCmdSetDeviceMaskKHR)
        #define vkGetDeviceGroupPeerMemoryFeaturesKHR (vxAssert(vkGetDeviceGroupPeerMemoryFeaturesKHR),vkGetDeviceGroupPeerMemoryFeaturesKHR)
    #endif /* defined(VK_KHR_device_group) */
    #if defined(VK_KHR_display_swapchain)
        #define vkCreateSharedSwapchainsKHR (vxAssert(vkCreateSharedSwapchainsKHR),vkCreateSharedSwapchainsKHR)
    #endif /* defined(VK_KHR_display_swapchain) */
    #if defined(VK_KHR_draw_indirect_count)
        #define vkCmdDrawIndexedIndirectCountKHR (vxAssert(vkCmdDrawIndexedIndirectCountKHR),vkCmdDrawIndexedIndirectCountKHR)
        #define vkCmdDrawIndirectCountKHR (vxAssert(vkCmdDrawIndirectCountKHR),vkCmdDrawIndirectCountKHR)
    #endif /* defined(VK_KHR_draw_indirect_count) */
    #if defined(VK_KHR_dynamic_rendering)
        #define vkCmdBeginRenderingKHR (vxAssert(vkCmdBeginRenderingKHR),vkCmdBeginRenderingKHR)
        #define vkCmdEndRenderingKHR (vxAssert(vkCmdEndRenderingKHR),vkCmdEndRenderingKHR)
    #endif /* defined(VK_KHR_dynamic_rendering) */
    #if defined(VK_KHR_external_fence_fd)
        #define vkGetFenceFdKHR (vxAssert(vkGetFenceFdKHR),vkGetFenceFdKHR)
        #define vkImportFenceFdKHR (vxAssert(vkImportFenceFdKHR),vkImportFenceFdKHR)
    #endif /* defined(VK_KHR_external_fence_fd) */
    #if defined(VK_KHR_external_fence_win32)
        #define vkGetFenceWin32HandleKHR (vxAssert(vkGetFenceWin32HandleKHR),vkGetFenceWin32HandleKHR)
        #define vkImportFenceWin32HandleKHR (vxAssert(vkImportFenceWin32HandleKHR),vkImportFenceWin32HandleKHR)
    #endif /* defined(VK_KHR_external_fence_win32) */
    #if defined(VK_KHR_external_memory_fd)
        #define vkGetMemoryFdKHR (vxAssert(vkGetMemoryFdKHR),vkGetMemoryFdKHR)
        #define vkGetMemoryFdPropertiesKHR (vxAssert(vkGetMemoryFdPropertiesKHR),vkGetMemoryFdPropertiesKHR)
    #endif /* defined(VK_KHR_external_memory_fd) */
    #if defined(VK_KHR_external_memory_win32)
        #define vkGetMemoryWin32HandleKHR (vxAssert(vkGetMemoryWin32HandleKHR),vkGetMemoryWin32HandleKHR)
        #define vkGetMemoryWin32HandlePropertiesKHR (vxAssert(vkGetMemoryWin32HandlePropertiesKHR),vkGetMemoryWin32HandlePropertiesKHR)
    #endif /* defined(VK_KHR_external_memory_win32) */
    #if defined(VK_KHR_external_semaphore_fd)
        #define vkGetSemaphoreFdKHR (vxAssert(vkGetSemaphoreFdKHR),vkGetSemaphoreFdKHR)
        #define vkImportSemaphoreFdKHR (vxAssert(vkImportSemaphoreFdKHR),vkImportSemaphoreFdKHR)
    #endif /* defined(VK_KHR_external_semaphore_fd) */
    #if defined(VK_KHR_external_semaphore_win32)
        #define vkGetSemaphoreWin32HandleKHR (vxAssert(vkGetSemaphoreWin32HandleKHR),vkGetSemaphoreWin32HandleKHR)
        #define vkImportSemaphoreWin32HandleKHR (vxAssert(vkImportSemaphoreWin32HandleKHR),vkImportSemaphoreWin32HandleKHR)
    #endif /* defined(VK_KHR_external_semaphore_win32) */
    #if defined(VK_KHR_fragment_shading_rate)
        #define vkCmdSetFragmentShadingRateKHR (vxAssert(vkCmdSetFragmentShadingRateKHR),vkCmdSetFragmentShadingRateKHR)
    #endif /* defined(VK_KHR_fragment_shading_rate) */
    #if defined(VK_KHR_get_memory_requirements2)
        #define vkGetBufferMemoryRequirements2KHR (vxAssert(vkGetBufferMemoryRequirements2KHR),vkGetBufferMemoryRequirements2KHR)
        #define vkGetImageMemoryRequirements2KHR (vxAssert(vkGetImageMemoryRequirements2KHR),vkGetImageMemoryRequirements2KHR)
        #define vkGetImageSparseMemoryRequirements2KHR (vxAssert(vkGetImageSparseMemoryRequirements2KHR),vkGetImageSparseMemoryRequirements2KHR)
    #endif /* defined(VK_KHR_get_memory_requirements2) */
    #if defined(VK_KHR_maintenance1)
        #define vkTrimCommandPoolKHR (vxAssert(vkTrimCommandPoolKHR),vkTrimCommandPoolKHR)
    #endif /* defined(VK_KHR_maintenance1) */
    #if defined(VK_KHR_maintenance3)
        #define vkGetDescriptorSetLayoutSupportKHR (vxAssert(vkGetDescriptorSetLayoutSupportKHR),vkGetDescriptorSetLayoutSupportKHR)
    #endif /* defined(VK_KHR_maintenance3) */
    #if defined(VK_KHR_maintenance4)
        #define vkGetDeviceBufferMemoryRequirementsKHR (vxAssert(vkGetDeviceBufferMemoryRequirementsKHR),vkGetDeviceBufferMemoryRequirementsKHR)
        #define vkGetDeviceImageMemoryRequirementsKHR (vxAssert(vkGetDeviceImageMemoryRequirementsKHR),vkGetDeviceImageMemoryRequirementsKHR)
        #define vkGetDeviceImageSparseMemoryRequirementsKHR (vxAssert(vkGetDeviceImageSparseMemoryRequirementsKHR),vkGetDeviceImageSparseMemoryRequirementsKHR)
    #endif /* defined(VK_KHR_maintenance4) */
    #if defined(VK_KHR_performance_query)
        #define vkAcquireProfilingLockKHR (vxAssert(vkAcquireProfilingLockKHR),vkAcquireProfilingLockKHR)
        #define vkReleaseProfilingLockKHR (vxAssert(vkReleaseProfilingLockKHR),vkReleaseProfilingLockKHR)
    #endif /* defined(VK_KHR_performance_query) */
    #if defined(VK_KHR_pipeline_executable_properties)
        #define vkGetPipelineExecutableInternalRepresentationsKHR (vxAssert(vkGetPipelineExecutableInternalRepresentationsKHR),vkGetPipelineExecutableInternalRepresentationsKHR)
        #define vkGetPipelineExecutablePropertiesKHR (vxAssert(vkGetPipelineExecutablePropertiesKHR),vkGetPipelineExecutablePropertiesKHR)
        #define vkGetPipelineExecutableStatisticsKHR (vxAssert(vkGetPipelineExecutableStatisticsKHR),vkGetPipelineExecutableStatisticsKHR)
    #endif /* defined(VK_KHR_pipeline_executable_properties) */
    #if defined(VK_KHR_present_wait)
        #define vkWaitForPresentKHR (vxAssert(vkWaitForPresentKHR),vkWaitForPresentKHR)
    #endif /* defined(VK_KHR_present_wait) */
    #if defined(VK_KHR_push_descriptor)
        #define vkCmdPushDescriptorSetKHR (vxAssert(vkCmdPushDescriptorSetKHR),vkCmdPushDescriptorSetKHR)
    #endif /* defined(VK_KHR_push_descriptor) */
    #if defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline)
        #define vkCmdTraceRaysIndirect2KHR (vxAssert(vkCmdTraceRaysIndirect2KHR),vkCmdTraceRaysIndirect2KHR)
    #endif /* defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline) */
    #if defined(VK_KHR_ray_tracing_pipeline)
        #define vkCmdSetRayTracingPipelineStackSizeKHR (vxAssert(vkCmdSetRayTracingPipelineStackSizeKHR),vkCmdSetRayTracingPipelineStackSizeKHR)
        #define vkCmdTraceRaysIndirectKHR (vxAssert(vkCmdTraceRaysIndirectKHR),vkCmdTraceRaysIndirectKHR)
        #define vkCmdTraceRaysKHR (vxAssert(vkCmdTraceRaysKHR),vkCmdTraceRaysKHR)
        #define vkCreateRayTracingPipelinesKHR (vxAssert(vkCreateRayTracingPipelinesKHR),vkCreateRayTracingPipelinesKHR)
        #define vkGetRayTracingCaptureReplayShaderGroupHandlesKHR (vxAssert(vkGetRayTracingCaptureReplayShaderGroupHandlesKHR),vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)
        #define vkGetRayTracingShaderGroupHandlesKHR (vxAssert(vkGetRayTracingShaderGroupHandlesKHR),vkGetRayTracingShaderGroupHandlesKHR)
        #define vkGetRayTracingShaderGroupStackSizeKHR (vxAssert(vkGetRayTracingShaderGroupStackSizeKHR),vkGetRayTracingShaderGroupStackSizeKHR)
    #endif /* defined(VK_KHR_ray_tracing_pipeline) */
    #if defined(VK_KHR_sampler_ycbcr_conversion)
        #define vkCreateSamplerYcbcrConversionKHR (vxAssert(vkCreateSamplerYcbcrConversionKHR),vkCreateSamplerYcbcrConversionKHR)
        #define vkDestroySamplerYcbcrConversionKHR (vxAssert(vkDestroySamplerYcbcrConversionKHR),vkDestroySamplerYcbcrConversionKHR)
    #endif /* defined(VK_KHR_sampler_ycbcr_conversion) */
    #if defined(VK_KHR_shared_presentable_image)
        #define vkGetSwapchainStatusKHR (vxAssert(vkGetSwapchainStatusKHR),vkGetSwapchainStatusKHR)
    #endif /* defined(VK_KHR_shared_presentable_image) */
    #if defined(VK_KHR_swapchain)
        #define vkAcquireNextImageKHR (vxAssert(vkAcquireNextImageKHR),vkAcquireNextImageKHR)
        #define vkCreateSwapchainKHR (vxAssert(vkCreateSwapchainKHR),vkCreateSwapchainKHR)
        #define vkDestroySwapchainKHR (vxAssert(vkDestroySwapchainKHR),vkDestroySwapchainKHR)
        #define vkGetSwapchainImagesKHR (vxAssert(vkGetSwapchainImagesKHR),vkGetSwapchainImagesKHR)
        #define vkQueuePresentKHR (vxAssert(vkQueuePresentKHR),vkQueuePresentKHR)
    #endif /* defined(VK_KHR_swapchain) */
    #if defined(VK_KHR_synchronization2)
        #define vkCmdPipelineBarrier2KHR (vxAssert(vkCmdPipelineBarrier2KHR),vkCmdPipelineBarrier2KHR)
        #define vkCmdResetEvent2KHR (vxAssert(vkCmdResetEvent2KHR),vkCmdResetEvent2KHR)
        #define vkCmdSetEvent2KHR (vxAssert(vkCmdSetEvent2KHR),vkCmdSetEvent2KHR)
        #define vkCmdWaitEvents2KHR (vxAssert(vkCmdWaitEvents2KHR),vkCmdWaitEvents2KHR)
        #define vkCmdWriteTimestamp2KHR (vxAssert(vkCmdWriteTimestamp2KHR),vkCmdWriteTimestamp2KHR)
        #define vkQueueSubmit2KHR (vxAssert(vkQueueSubmit2KHR),vkQueueSubmit2KHR)
    #endif /* defined(VK_KHR_synchronization2) */
    #if defined(VK_KHR_synchronization2) && defined(VK_AMD_buffer_marker)
        #define vkCmdWriteBufferMarker2AMD (vxAssert(vkCmdWriteBufferMarker2AMD),vkCmdWriteBufferMarker2AMD)
    #endif /* defined(VK_KHR_synchronization2) && defined(VK_AMD_buffer_marker) */
    #if defined(VK_KHR_synchronization2) && defined(VK_NV_device_diagnostic_checkpoints)
        #define vkGetQueueCheckpointData2NV (vxAssert(vkGetQueueCheckpointData2NV),vkGetQueueCheckpointData2NV)
    #endif /* defined(VK_KHR_synchronization2) && defined(VK_NV_device_diagnostic_checkpoints) */
    #if defined(VK_KHR_timeline_semaphore)
        #define vkGetSemaphoreCounterValueKHR (vxAssert(vkGetSemaphoreCounterValueKHR),vkGetSemaphoreCounterValueKHR)
        #define vkSignalSemaphoreKHR (vxAssert(vkSignalSemaphoreKHR),vkSignalSemaphoreKHR)
        #define vkWaitSemaphoresKHR (vxAssert(vkWaitSemaphoresKHR),vkWaitSemaphoresKHR)
    #endif /* defined(VK_KHR_timeline_semaphore) */
    #if defined(VK_KHR_video_decode_queue)
        #define vkCmdDecodeVideoKHR (vxAssert(vkCmdDecodeVideoKHR),vkCmdDecodeVideoKHR)
    #endif /* defined(VK_KHR_video_decode_queue) */
    #if defined(VK_KHR_video_encode_queue)
        #define vkCmdEncodeVideoKHR (vxAssert(vkCmdEncodeVideoKHR),vkCmdEncodeVideoKHR)
    #endif /* defined(VK_KHR_video_encode_queue) */
    #if defined(VK_KHR_video_queue)
        #define vkBindVideoSessionMemoryKHR (vxAssert(vkBindVideoSessionMemoryKHR),vkBindVideoSessionMemoryKHR)
        #define vkCmdBeginVideoCodingKHR (vxAssert(vkCmdBeginVideoCodingKHR),vkCmdBeginVideoCodingKHR)
        #define vkCmdControlVideoCodingKHR (vxAssert(vkCmdControlVideoCodingKHR),vkCmdControlVideoCodingKHR)
        #define vkCmdEndVideoCodingKHR (vxAssert(vkCmdEndVideoCodingKHR),vkCmdEndVideoCodingKHR)
        #define vkCreateVideoSessionKHR (vxAssert(vkCreateVideoSessionKHR),vkCreateVideoSessionKHR)
        #define vkCreateVideoSessionParametersKHR (vxAssert(vkCreateVideoSessionParametersKHR),vkCreateVideoSessionParametersKHR)
        #define vkDestroyVideoSessionKHR (vxAssert(vkDestroyVideoSessionKHR),vkDestroyVideoSessionKHR)
        #define vkDestroyVideoSessionParametersKHR (vxAssert(vkDestroyVideoSessionParametersKHR),vkDestroyVideoSessionParametersKHR)
        #define vkGetVideoSessionMemoryRequirementsKHR (vxAssert(vkGetVideoSessionMemoryRequirementsKHR),vkGetVideoSessionMemoryRequirementsKHR)
        #define vkUpdateVideoSessionParametersKHR (vxAssert(vkUpdateVideoSessionParametersKHR),vkUpdateVideoSessionParametersKHR)
    #endif /* defined(VK_KHR_video_queue) */
    #if defined(VK_NVX_binary_import)
        #define vkCmdCuLaunchKernelNVX (vxAssert(vkCmdCuLaunchKernelNVX),vkCmdCuLaunchKernelNVX)
        #define vkCreateCuFunctionNVX (vxAssert(vkCreateCuFunctionNVX),vkCreateCuFunctionNVX)
        #define vkCreateCuModuleNVX (vxAssert(vkCreateCuModuleNVX),vkCreateCuModuleNVX)
        #define vkDestroyCuFunctionNVX (vxAssert(vkDestroyCuFunctionNVX),vkDestroyCuFunctionNVX)
        #define vkDestroyCuModuleNVX (vxAssert(vkDestroyCuModuleNVX),vkDestroyCuModuleNVX)
    #endif /* defined(VK_NVX_binary_import) */
    #if defined(VK_NVX_image_view_handle)
        #define vkGetImageViewAddressNVX (vxAssert(vkGetImageViewAddressNVX),vkGetImageViewAddressNVX)
        #define vkGetImageViewHandleNVX (vxAssert(vkGetImageViewHandleNVX),vkGetImageViewHandleNVX)
    #endif /* defined(VK_NVX_image_view_handle) */
    #if defined(VK_NV_clip_space_w_scaling)
        #define vkCmdSetViewportWScalingNV (vxAssert(vkCmdSetViewportWScalingNV),vkCmdSetViewportWScalingNV)
    #endif /* defined(VK_NV_clip_space_w_scaling) */
    #if defined(VK_NV_copy_memory_indirect)
        #define vkCmdCopyMemoryIndirectNV (vxAssert(vkCmdCopyMemoryIndirectNV),vkCmdCopyMemoryIndirectNV)
        #define vkCmdCopyMemoryToImageIndirectNV (vxAssert(vkCmdCopyMemoryToImageIndirectNV),vkCmdCopyMemoryToImageIndirectNV)
    #endif /* defined(VK_NV_copy_memory_indirect) */
    #if defined(VK_NV_device_diagnostic_checkpoints)
        #define vkCmdSetCheckpointNV (vxAssert(vkCmdSetCheckpointNV),vkCmdSetCheckpointNV)
        #define vkGetQueueCheckpointDataNV (vxAssert(vkGetQueueCheckpointDataNV),vkGetQueueCheckpointDataNV)
    #endif /* defined(VK_NV_device_diagnostic_checkpoints) */
    #if defined(VK_NV_device_generated_commands)
        #define vkCmdBindPipelineShaderGroupNV (vxAssert(vkCmdBindPipelineShaderGroupNV),vkCmdBindPipelineShaderGroupNV)
        #define vkCmdExecuteGeneratedCommandsNV (vxAssert(vkCmdExecuteGeneratedCommandsNV),vkCmdExecuteGeneratedCommandsNV)
        #define vkCmdPreprocessGeneratedCommandsNV (vxAssert(vkCmdPreprocessGeneratedCommandsNV),vkCmdPreprocessGeneratedCommandsNV)
        #define vkCreateIndirectCommandsLayoutNV (vxAssert(vkCreateIndirectCommandsLayoutNV),vkCreateIndirectCommandsLayoutNV)
        #define vkDestroyIndirectCommandsLayoutNV (vxAssert(vkDestroyIndirectCommandsLayoutNV),vkDestroyIndirectCommandsLayoutNV)
        #define vkGetGeneratedCommandsMemoryRequirementsNV (vxAssert(vkGetGeneratedCommandsMemoryRequirementsNV),vkGetGeneratedCommandsMemoryRequirementsNV)
    #endif /* defined(VK_NV_device_generated_commands) */
    #if defined(VK_NV_external_memory_rdma)
        #define vkGetMemoryRemoteAddressNV (vxAssert(vkGetMemoryRemoteAddressNV),vkGetMemoryRemoteAddressNV)
    #endif /* defined(VK_NV_external_memory_rdma) */
    #if defined(VK_NV_external_memory_win32)
        #define vkGetMemoryWin32HandleNV (vxAssert(vkGetMemoryWin32HandleNV),vkGetMemoryWin32HandleNV)
    #endif /* defined(VK_NV_external_memory_win32) */
    #if defined(VK_NV_fragment_shading_rate_enums)
        #define vkCmdSetFragmentShadingRateEnumNV (vxAssert(vkCmdSetFragmentShadingRateEnumNV),vkCmdSetFragmentShadingRateEnumNV)
    #endif /* defined(VK_NV_fragment_shading_rate_enums) */
    #if defined(VK_NV_memory_decompression)
        #define vkCmdDecompressMemoryIndirectCountNV (vxAssert(vkCmdDecompressMemoryIndirectCountNV),vkCmdDecompressMemoryIndirectCountNV)
        #define vkCmdDecompressMemoryNV (vxAssert(vkCmdDecompressMemoryNV),vkCmdDecompressMemoryNV)
    #endif /* defined(VK_NV_memory_decompression) */
    #if defined(VK_NV_mesh_shader)
        #define vkCmdDrawMeshTasksIndirectCountNV (vxAssert(vkCmdDrawMeshTasksIndirectCountNV),vkCmdDrawMeshTasksIndirectCountNV)
        #define vkCmdDrawMeshTasksIndirectNV (vxAssert(vkCmdDrawMeshTasksIndirectNV),vkCmdDrawMeshTasksIndirectNV)
        #define vkCmdDrawMeshTasksNV (vxAssert(vkCmdDrawMeshTasksNV),vkCmdDrawMeshTasksNV)
    #endif /* defined(VK_NV_mesh_shader) */
    #if defined(VK_NV_optical_flow)
        #define vkBindOpticalFlowSessionImageNV (vxAssert(vkBindOpticalFlowSessionImageNV),vkBindOpticalFlowSessionImageNV)
        #define vkCmdOpticalFlowExecuteNV (vxAssert(vkCmdOpticalFlowExecuteNV),vkCmdOpticalFlowExecuteNV)
        #define vkCreateOpticalFlowSessionNV (vxAssert(vkCreateOpticalFlowSessionNV),vkCreateOpticalFlowSessionNV)
        #define vkDestroyOpticalFlowSessionNV (vxAssert(vkDestroyOpticalFlowSessionNV),vkDestroyOpticalFlowSessionNV)
    #endif /* defined(VK_NV_optical_flow) */
    #if defined(VK_NV_ray_tracing)
        #define vkBindAccelerationStructureMemoryNV (vxAssert(vkBindAccelerationStructureMemoryNV),vkBindAccelerationStructureMemoryNV)
        #define vkCmdBuildAccelerationStructureNV (vxAssert(vkCmdBuildAccelerationStructureNV),vkCmdBuildAccelerationStructureNV)
        #define vkCmdCopyAccelerationStructureNV (vxAssert(vkCmdCopyAccelerationStructureNV),vkCmdCopyAccelerationStructureNV)
        #define vkCmdTraceRaysNV (vxAssert(vkCmdTraceRaysNV),vkCmdTraceRaysNV)
        #define vkCmdWriteAccelerationStructuresPropertiesNV (vxAssert(vkCmdWriteAccelerationStructuresPropertiesNV),vkCmdWriteAccelerationStructuresPropertiesNV)
        #define vkCompileDeferredNV (vxAssert(vkCompileDeferredNV),vkCompileDeferredNV)
        #define vkCreateAccelerationStructureNV (vxAssert(vkCreateAccelerationStructureNV),vkCreateAccelerationStructureNV)
        #define vkCreateRayTracingPipelinesNV (vxAssert(vkCreateRayTracingPipelinesNV),vkCreateRayTracingPipelinesNV)
        #define vkDestroyAccelerationStructureNV (vxAssert(vkDestroyAccelerationStructureNV),vkDestroyAccelerationStructureNV)
        #define vkGetAccelerationStructureHandleNV (vxAssert(vkGetAccelerationStructureHandleNV),vkGetAccelerationStructureHandleNV)
        #define vkGetAccelerationStructureMemoryRequirementsNV (vxAssert(vkGetAccelerationStructureMemoryRequirementsNV),vkGetAccelerationStructureMemoryRequirementsNV)
        #define vkGetRayTracingShaderGroupHandlesNV (vxAssert(vkGetRayTracingShaderGroupHandlesNV),vkGetRayTracingShaderGroupHandlesNV)
    #endif /* defined(VK_NV_ray_tracing) */
    #if defined(VK_NV_scissor_exclusive)
        #define vkCmdSetExclusiveScissorNV (vxAssert(vkCmdSetExclusiveScissorNV),vkCmdSetExclusiveScissorNV)
    #endif /* defined(VK_NV_scissor_exclusive) */
    #if defined(VK_NV_shading_rate_image)
        #define vkCmdBindShadingRateImageNV (vxAssert(vkCmdBindShadingRateImageNV),vkCmdBindShadingRateImageNV)
        #define vkCmdSetCoarseSampleOrderNV (vxAssert(vkCmdSetCoarseSampleOrderNV),vkCmdSetCoarseSampleOrderNV)
        #define vkCmdSetViewportShadingRatePaletteNV (vxAssert(vkCmdSetViewportShadingRatePaletteNV),vkCmdSetViewportShadingRatePaletteNV)
    #endif /* defined(VK_NV_shading_rate_image) */
    #if defined(VK_QCOM_tile_properties)
        #define vkGetDynamicRenderingTilePropertiesQCOM (vxAssert(vkGetDynamicRenderingTilePropertiesQCOM),vkGetDynamicRenderingTilePropertiesQCOM)
        #define vkGetFramebufferTilePropertiesQCOM (vxAssert(vkGetFramebufferTilePropertiesQCOM),vkGetFramebufferTilePropertiesQCOM)
    #endif /* defined(VK_QCOM_tile_properties) */
    #if defined(VK_VALVE_descriptor_set_host_mapping)
        #define vkGetDescriptorSetHostMappingVALVE (vxAssert(vkGetDescriptorSetHostMappingVALVE),vkGetDescriptorSetHostMappingVALVE)
        #define vkGetDescriptorSetLayoutHostMappingInfoVALVE (vxAssert(vkGetDescriptorSetLayoutHostMappingInfoVALVE),vkGetDescriptorSetLayoutHostMappingInfoVALVE)
    #endif /* defined(VK_VALVE_descriptor_set_host_mapping) */
    #if (defined(VK_EXT_full_screen_exclusive) && defined(VK_KHR_device_group)) || (defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1))
        #define vkGetDeviceGroupSurfacePresentModes2EXT (vxAssert(vkGetDeviceGroupSurfacePresentModes2EXT),vkGetDeviceGroupSurfacePresentModes2EXT)
    #endif /* (defined(VK_EXT_full_screen_exclusive) && defined(VK_KHR_device_group)) || (defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1)) */
    #if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_push_descriptor) && defined(VK_KHR_descriptor_update_template))
        #define vkCmdPushDescriptorSetWithTemplateKHR (vxAssert(vkCmdPushDescriptorSetWithTemplateKHR),vkCmdPushDescriptorSetWithTemplateKHR)
    #endif /* (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_push_descriptor) && defined(VK_KHR_descriptor_update_template)) */
    #if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
        #define vkGetDeviceGroupPresentCapabilitiesKHR (vxAssert(vkGetDeviceGroupPresentCapabilitiesKHR),vkGetDeviceGroupPresentCapabilitiesKHR)
        #define vkGetDeviceGroupSurfacePresentModesKHR (vxAssert(vkGetDeviceGroupSurfacePresentModesKHR),vkGetDeviceGroupSurfacePresentModesKHR)
    #endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
    #if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
        #define vkAcquireNextImage2KHR (vxAssert(vkAcquireNextImage2KHR),vkAcquireNextImage2KHR)
    #endif /* (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1)) */
#endif // !defined(VX_NO_FUNCTION_POINTER_VALIDATION)

//------------------------------------------------------------------------------

#endif // #ifndef VULKAN_EXPRESS_H_

//------------------------------------------------------------------------------

#ifdef VX_IMPLEMENTATION
    #undef VX_IMPLEMENTATION
    // Prevent tools like dependency checkers that don't evaluate
    // macros from detecting a cyclic dependency.
    #define VULKAN_EXPRESS_C_ "vulkan_express.c"
    #include VULKAN_EXPRESS_C_
#endif
/* clang-format on */
