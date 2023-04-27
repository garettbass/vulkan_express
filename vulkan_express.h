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

VkResult vxExpectNonErrorCallback(
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

VkResult vxExpectSuccessCallback(
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
    VkQueue                          computeQueue;
    uint32_t                         computeQueueFamilyIndex;
    VkQueue                          graphicsQueue;
    uint32_t                         graphicsQueueFamilyIndex;
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

void
vxDestroyBufferAllocation(
    const VxContext*    pContext,
    VxBufferAllocation* pAllocation
);

VkResult
vxCopyToBufferAllocation(
    const VxContext*          pContext,
    const VxBufferAllocation* dstAllocation,
    VkDeviceSize              dstOffset,
    VkDeviceSize              size,
    const void*               srcData
);

static inline
VxBufferAllocation
vxBufferAllocation(
    const VxContext* pContext,
    VxBufferAllocationInfo allocationInfo
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

#endif // #ifndef VULKAN_EXPRESS_H_

//------------------------------------------------------------------------------

#ifdef VX_IMPLEMENTATION
    #undef VX_IMPLEMENTATION
    // Prevent tools like dependency checkers that don't evaluate
    // macros from detecting a cyclic dependency.
    #define VX_SOURCE "vulkan_express.c"
    #include VX_SOURCE
#endif
/* clang-format on */
