/* This file is part of vx library; see vx.h for version/license details */
/* clang-format off */
#include "vulkan_express.h"
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
    #define vxInit {}
#else // !__cplusplus
    #define vxInit {0}
    #define nullptr NULL
    #ifndef static_assert
    #define static_assert _Static_assert
    #endif
#endif

//------------------------------------------------------------------------------

#if defined(VX_NO_ESCAPE_CODES)

    #define VX_ESCAPE_CODE_RESET            ""
    #define VX_ESCAPE_CODE_BLACK            ""
    #define VX_ESCAPE_CODE_DKRED            ""
    #define VX_ESCAPE_CODE_DKGREEN          ""
    #define VX_ESCAPE_CODE_DKYELLOW         ""
    #define VX_ESCAPE_CODE_DKBLUE           ""
    #define VX_ESCAPE_CODE_DKPURPLE         ""
    #define VX_ESCAPE_CODE_DKCYAN           ""
    #define VX_ESCAPE_CODE_LTGREY           ""
    #define VX_ESCAPE_CODE_DKGREY           ""
    #define VX_ESCAPE_CODE_LTRED            ""
    #define VX_ESCAPE_CODE_LTGREEN          ""
    #define VX_ESCAPE_CODE_LTYELLOW         ""
    #define VX_ESCAPE_CODE_LTBLUE           ""
    #define VX_ESCAPE_CODE_LTPURPLE         ""
    #define VX_ESCAPE_CODE_LTCYAN           ""
    #define VX_ESCAPE_CODE_WHITE            ""

#else

    #define VX_ESCAPE_CODE_RESET            "\x1b[0m"
    #define VX_ESCAPE_CODE_BLACK            "\x1b[30m"
    #define VX_ESCAPE_CODE_DKRED            "\x1b[31m"
    #define VX_ESCAPE_CODE_DKGREEN          "\x1b[32m"
    #define VX_ESCAPE_CODE_DKYELLOW         "\x1b[33m"
    #define VX_ESCAPE_CODE_DKBLUE           "\x1b[34m"
    #define VX_ESCAPE_CODE_DKPURPLE         "\x1b[35m"
    #define VX_ESCAPE_CODE_DKCYAN           "\x1b[36m"
    #define VX_ESCAPE_CODE_LTGREY           "\x1b[37m"
    #define VX_ESCAPE_CODE_DKGREY           "\x1b[1;30m"
    #define VX_ESCAPE_CODE_LTRED            "\x1b[1;31m"
    #define VX_ESCAPE_CODE_LTGREEN          "\x1b[1;32m"
    #define VX_ESCAPE_CODE_LTYELLOW         "\x1b[1;33m"
    #define VX_ESCAPE_CODE_LTBLUE           "\x1b[1;34m"
    #define VX_ESCAPE_CODE_LTPURPLE         "\x1b[1;35m"
    #define VX_ESCAPE_CODE_LTCYAN           "\x1b[1;36m"
    #define VX_ESCAPE_CODE_WHITE            "\x1b[1;37m"

#endif

#define VX_INFO(...)    VX_ESCAPE_CODE_LTGREEN  __VA_ARGS__ VX_ESCAPE_CODE_RESET
#define VX_WARNING(...) VX_ESCAPE_CODE_LTYELLOW __VA_ARGS__ VX_ESCAPE_CODE_RESET
#define VX_ERROR(...)   VX_ESCAPE_CODE_LTRED    __VA_ARGS__ VX_ESCAPE_CODE_RESET

//------------------------------------------------------------------------------

#define vxLengthOf(array) (sizeof(array)/sizeof(array[0]))

//------------------------------------------------------------------------------

#ifndef vxPrintf
#define vxPrintf printf
#endif

#ifndef vxPuts
#define vxPuts puts
#endif

#define vxInfof(format, ...) \
        vxPrintf(VX_INFO("%s:%i: " format "\n"),__FILE__,__LINE__,__VA_ARGS__)

#define vxWarningf(format, ...) \
        vxPrintf(VX_WARNING("%s:%i: " format "\n"),__FILE__,__LINE__,__VA_ARGS__)

#define vxErrorf(format, ...) \
        vxPrintf(VX_ERROR("%s:%i: " format "\n"),__FILE__,__LINE__,__VA_ARGS__)

#define vxDiagnosticf(format, ...) \
        vxInfof(format,__VA_ARGS__)

#define vxExpect(expr) \
        ((expr)||(vxPuts(VX_WARNING("vxExpect(" #expr ") failed")),0))

#define vxAssert(expr) \
        ((expr)||(vxPuts(VX_ERROR("vxAssert(" #expr ") failed")),exit(1),0))

//------------------------------------------------------------------------------

static char vxEnumNameBuffer[256];

const char* vxResultName(VkResult result) {
    switch (result) {
        case    VK_SUCCESS:
        return "VK_SUCCESS";
        case    VK_NOT_READY:
        return "VK_NOT_READY";
        case    VK_TIMEOUT:
        return "VK_TIMEOUT";
        case    VK_EVENT_SET:
        return "VK_EVENT_SET";
        case    VK_EVENT_RESET:
        return "VK_EVENT_RESET";
        case    VK_INCOMPLETE:
        return "VK_INCOMPLETE";
        case    VK_ERROR_OUT_OF_HOST_MEMORY:
        return "VK_ERROR_OUT_OF_HOST_MEMORY";
        case    VK_ERROR_OUT_OF_DEVICE_MEMORY:
        return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
        case    VK_ERROR_INITIALIZATION_FAILED:
        return "VK_ERROR_INITIALIZATION_FAILED";
        case    VK_ERROR_DEVICE_LOST:
        return "VK_ERROR_DEVICE_LOST";
        case    VK_ERROR_MEMORY_MAP_FAILED:
        return "VK_ERROR_MEMORY_MAP_FAILED";
        case    VK_ERROR_LAYER_NOT_PRESENT:
        return "VK_ERROR_LAYER_NOT_PRESENT";
        case    VK_ERROR_EXTENSION_NOT_PRESENT:
        return "VK_ERROR_EXTENSION_NOT_PRESENT";
        case    VK_ERROR_FEATURE_NOT_PRESENT:
        return "VK_ERROR_FEATURE_NOT_PRESENT";
        case    VK_ERROR_INCOMPATIBLE_DRIVER:
        return "VK_ERROR_INCOMPATIBLE_DRIVER";
        case    VK_ERROR_TOO_MANY_OBJECTS:
        return "VK_ERROR_TOO_MANY_OBJECTS";
        case    VK_ERROR_FORMAT_NOT_SUPPORTED:
        return "VK_ERROR_FORMAT_NOT_SUPPORTED";
        case    VK_ERROR_FRAGMENTED_POOL:
        return "VK_ERROR_FRAGMENTED_POOL";
        case    VK_ERROR_UNKNOWN:
        return "VK_ERROR_UNKNOWN";
        case    VK_ERROR_OUT_OF_POOL_MEMORY:
        return "VK_ERROR_OUT_OF_POOL_MEMORY";
        case    VK_ERROR_INVALID_EXTERNAL_HANDLE:
        return "VK_ERROR_INVALID_EXTERNAL_HANDLE";
        case    VK_ERROR_FRAGMENTATION:
        return "VK_ERROR_FRAGMENTATION";
        case    VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:
        return "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";
        case    VK_PIPELINE_COMPILE_REQUIRED:
        return "VK_PIPELINE_COMPILE_REQUIRED";
        case    VK_ERROR_SURFACE_LOST_KHR:
        return "VK_ERROR_SURFACE_LOST_KHR";
        case    VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
        return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
        case    VK_SUBOPTIMAL_KHR:
        return "VK_SUBOPTIMAL_KHR";
        case    VK_ERROR_OUT_OF_DATE_KHR:
        return "VK_ERROR_OUT_OF_DATE_KHR";
        case    VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
        return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
        case    VK_ERROR_VALIDATION_FAILED_EXT:
        return "VK_ERROR_VALIDATION_FAILED_EXT";
        case    VK_ERROR_INVALID_SHADER_NV:
        return "VK_ERROR_INVALID_SHADER_NV";
        case    VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR:
        return "VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR";
        case    VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR";
        case    VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR";
        case    VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR";
        case    VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR";
        case    VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR";
        case    VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT:
        return "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT";
        case    VK_ERROR_NOT_PERMITTED_KHR:
        return "VK_ERROR_NOT_PERMITTED_KHR";
        case    VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
        return "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";
        case    VK_THREAD_IDLE_KHR:
        return "VK_THREAD_IDLE_KHR";
        case    VK_THREAD_DONE_KHR:
        return "VK_THREAD_DONE_KHR";
        case    VK_OPERATION_DEFERRED_KHR:
        return "VK_OPERATION_DEFERRED_KHR";
        case    VK_OPERATION_NOT_DEFERRED_KHR:
        return "VK_OPERATION_NOT_DEFERRED_KHR";
        case    VK_ERROR_COMPRESSION_EXHAUSTED_EXT:
        return "VK_ERROR_COMPRESSION_EXHAUSTED_EXT";
        case    VK_RESULT_MAX_ENUM:
        return "VK_RESULT_MAX_ENUM";
    }
    snprintf(
        vxEnumNameBuffer, sizeof(vxEnumNameBuffer),
        "((VkResult)%i)", result
    );
    return vxEnumNameBuffer;
}

const char* vxFormatName(VkFormat format) {
    switch (format) {
        case    VK_FORMAT_UNDEFINED:
        return "VK_FORMAT_UNDEFINED";
        case    VK_FORMAT_R4G4_UNORM_PACK8:
        return "VK_FORMAT_R4G4_UNORM_PACK8";
        case    VK_FORMAT_R4G4B4A4_UNORM_PACK16:
        return "VK_FORMAT_R4G4B4A4_UNORM_PACK16";
        case    VK_FORMAT_B4G4R4A4_UNORM_PACK16:
        return "VK_FORMAT_B4G4R4A4_UNORM_PACK16";
        case    VK_FORMAT_R5G6B5_UNORM_PACK16:
        return "VK_FORMAT_R5G6B5_UNORM_PACK16";
        case    VK_FORMAT_B5G6R5_UNORM_PACK16:
        return "VK_FORMAT_B5G6R5_UNORM_PACK16";
        case    VK_FORMAT_R5G5B5A1_UNORM_PACK16:
        return "VK_FORMAT_R5G5B5A1_UNORM_PACK16";
        case    VK_FORMAT_B5G5R5A1_UNORM_PACK16:
        return "VK_FORMAT_B5G5R5A1_UNORM_PACK16";
        case    VK_FORMAT_A1R5G5B5_UNORM_PACK16:
        return "VK_FORMAT_A1R5G5B5_UNORM_PACK16";
        case    VK_FORMAT_R8_UNORM:
        return "VK_FORMAT_R8_UNORM";
        case    VK_FORMAT_R8_SNORM:
        return "VK_FORMAT_R8_SNORM";
        case    VK_FORMAT_R8_USCALED:
        return "VK_FORMAT_R8_USCALED";
        case    VK_FORMAT_R8_SSCALED:
        return "VK_FORMAT_R8_SSCALED";
        case    VK_FORMAT_R8_UINT:
        return "VK_FORMAT_R8_UINT";
        case    VK_FORMAT_R8_SINT:
        return "VK_FORMAT_R8_SINT";
        case    VK_FORMAT_R8_SRGB:
        return "VK_FORMAT_R8_SRGB";
        case    VK_FORMAT_R8G8_UNORM:
        return "VK_FORMAT_R8G8_UNORM";
        case    VK_FORMAT_R8G8_SNORM:
        return "VK_FORMAT_R8G8_SNORM";
        case    VK_FORMAT_R8G8_USCALED:
        return "VK_FORMAT_R8G8_USCALED";
        case    VK_FORMAT_R8G8_SSCALED:
        return "VK_FORMAT_R8G8_SSCALED";
        case    VK_FORMAT_R8G8_UINT:
        return "VK_FORMAT_R8G8_UINT";
        case    VK_FORMAT_R8G8_SINT:
        return "VK_FORMAT_R8G8_SINT";
        case    VK_FORMAT_R8G8_SRGB:
        return "VK_FORMAT_R8G8_SRGB";
        case    VK_FORMAT_R8G8B8_UNORM:
        return "VK_FORMAT_R8G8B8_UNORM";
        case    VK_FORMAT_R8G8B8_SNORM:
        return "VK_FORMAT_R8G8B8_SNORM";
        case    VK_FORMAT_R8G8B8_USCALED:
        return "VK_FORMAT_R8G8B8_USCALED";
        case    VK_FORMAT_R8G8B8_SSCALED:
        return "VK_FORMAT_R8G8B8_SSCALED";
        case    VK_FORMAT_R8G8B8_UINT:
        return "VK_FORMAT_R8G8B8_UINT";
        case    VK_FORMAT_R8G8B8_SINT:
        return "VK_FORMAT_R8G8B8_SINT";
        case    VK_FORMAT_R8G8B8_SRGB:
        return "VK_FORMAT_R8G8B8_SRGB";
        case    VK_FORMAT_B8G8R8_UNORM:
        return "VK_FORMAT_B8G8R8_UNORM";
        case    VK_FORMAT_B8G8R8_SNORM:
        return "VK_FORMAT_B8G8R8_SNORM";
        case    VK_FORMAT_B8G8R8_USCALED:
        return "VK_FORMAT_B8G8R8_USCALED";
        case    VK_FORMAT_B8G8R8_SSCALED:
        return "VK_FORMAT_B8G8R8_SSCALED";
        case    VK_FORMAT_B8G8R8_UINT:
        return "VK_FORMAT_B8G8R8_UINT";
        case    VK_FORMAT_B8G8R8_SINT:
        return "VK_FORMAT_B8G8R8_SINT";
        case    VK_FORMAT_B8G8R8_SRGB:
        return "VK_FORMAT_B8G8R8_SRGB";
        case    VK_FORMAT_R8G8B8A8_UNORM:
        return "VK_FORMAT_R8G8B8A8_UNORM";
        case    VK_FORMAT_R8G8B8A8_SNORM:
        return "VK_FORMAT_R8G8B8A8_SNORM";
        case    VK_FORMAT_R8G8B8A8_USCALED:
        return "VK_FORMAT_R8G8B8A8_USCALED";
        case    VK_FORMAT_R8G8B8A8_SSCALED:
        return "VK_FORMAT_R8G8B8A8_SSCALED";
        case    VK_FORMAT_R8G8B8A8_UINT:
        return "VK_FORMAT_R8G8B8A8_UINT";
        case    VK_FORMAT_R8G8B8A8_SINT:
        return "VK_FORMAT_R8G8B8A8_SINT";
        case    VK_FORMAT_R8G8B8A8_SRGB:
        return "VK_FORMAT_R8G8B8A8_SRGB";
        case    VK_FORMAT_B8G8R8A8_UNORM:
        return "VK_FORMAT_B8G8R8A8_UNORM";
        case    VK_FORMAT_B8G8R8A8_SNORM:
        return "VK_FORMAT_B8G8R8A8_SNORM";
        case    VK_FORMAT_B8G8R8A8_USCALED:
        return "VK_FORMAT_B8G8R8A8_USCALED";
        case    VK_FORMAT_B8G8R8A8_SSCALED:
        return "VK_FORMAT_B8G8R8A8_SSCALED";
        case    VK_FORMAT_B8G8R8A8_UINT:
        return "VK_FORMAT_B8G8R8A8_UINT";
        case    VK_FORMAT_B8G8R8A8_SINT:
        return "VK_FORMAT_B8G8R8A8_SINT";
        case    VK_FORMAT_B8G8R8A8_SRGB:
        return "VK_FORMAT_B8G8R8A8_SRGB";
        case    VK_FORMAT_A8B8G8R8_UNORM_PACK32:
        return "VK_FORMAT_A8B8G8R8_UNORM_PACK32";
        case    VK_FORMAT_A8B8G8R8_SNORM_PACK32:
        return "VK_FORMAT_A8B8G8R8_SNORM_PACK32";
        case    VK_FORMAT_A8B8G8R8_USCALED_PACK32:
        return "VK_FORMAT_A8B8G8R8_USCALED_PACK32";
        case    VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
        return "VK_FORMAT_A8B8G8R8_SSCALED_PACK32";
        case    VK_FORMAT_A8B8G8R8_UINT_PACK32:
        return "VK_FORMAT_A8B8G8R8_UINT_PACK32";
        case    VK_FORMAT_A8B8G8R8_SINT_PACK32:
        return "VK_FORMAT_A8B8G8R8_SINT_PACK32";
        case    VK_FORMAT_A8B8G8R8_SRGB_PACK32:
        return "VK_FORMAT_A8B8G8R8_SRGB_PACK32";
        case    VK_FORMAT_A2R10G10B10_UNORM_PACK32:
        return "VK_FORMAT_A2R10G10B10_UNORM_PACK32";
        case    VK_FORMAT_A2R10G10B10_SNORM_PACK32:
        return "VK_FORMAT_A2R10G10B10_SNORM_PACK32";
        case    VK_FORMAT_A2R10G10B10_USCALED_PACK32:
        return "VK_FORMAT_A2R10G10B10_USCALED_PACK32";
        case    VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
        return "VK_FORMAT_A2R10G10B10_SSCALED_PACK32";
        case    VK_FORMAT_A2R10G10B10_UINT_PACK32:
        return "VK_FORMAT_A2R10G10B10_UINT_PACK32";
        case    VK_FORMAT_A2R10G10B10_SINT_PACK32:
        return "VK_FORMAT_A2R10G10B10_SINT_PACK32";
        case    VK_FORMAT_A2B10G10R10_UNORM_PACK32:
        return "VK_FORMAT_A2B10G10R10_UNORM_PACK32";
        case    VK_FORMAT_A2B10G10R10_SNORM_PACK32:
        return "VK_FORMAT_A2B10G10R10_SNORM_PACK32";
        case    VK_FORMAT_A2B10G10R10_USCALED_PACK32:
        return "VK_FORMAT_A2B10G10R10_USCALED_PACK32";
        case    VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
        return "VK_FORMAT_A2B10G10R10_SSCALED_PACK32";
        case    VK_FORMAT_A2B10G10R10_UINT_PACK32:
        return "VK_FORMAT_A2B10G10R10_UINT_PACK32";
        case    VK_FORMAT_A2B10G10R10_SINT_PACK32:
        return "VK_FORMAT_A2B10G10R10_SINT_PACK32";
        case    VK_FORMAT_R16_UNORM:
        return "VK_FORMAT_R16_UNORM";
        case    VK_FORMAT_R16_SNORM:
        return "VK_FORMAT_R16_SNORM";
        case    VK_FORMAT_R16_USCALED:
        return "VK_FORMAT_R16_USCALED";
        case    VK_FORMAT_R16_SSCALED:
        return "VK_FORMAT_R16_SSCALED";
        case    VK_FORMAT_R16_UINT:
        return "VK_FORMAT_R16_UINT";
        case    VK_FORMAT_R16_SINT:
        return "VK_FORMAT_R16_SINT";
        case    VK_FORMAT_R16_SFLOAT:
        return "VK_FORMAT_R16_SFLOAT";
        case    VK_FORMAT_R16G16_UNORM:
        return "VK_FORMAT_R16G16_UNORM";
        case    VK_FORMAT_R16G16_SNORM:
        return "VK_FORMAT_R16G16_SNORM";
        case    VK_FORMAT_R16G16_USCALED:
        return "VK_FORMAT_R16G16_USCALED";
        case    VK_FORMAT_R16G16_SSCALED:
        return "VK_FORMAT_R16G16_SSCALED";
        case    VK_FORMAT_R16G16_UINT:
        return "VK_FORMAT_R16G16_UINT";
        case    VK_FORMAT_R16G16_SINT:
        return "VK_FORMAT_R16G16_SINT";
        case    VK_FORMAT_R16G16_SFLOAT:
        return "VK_FORMAT_R16G16_SFLOAT";
        case    VK_FORMAT_R16G16B16_UNORM:
        return "VK_FORMAT_R16G16B16_UNORM";
        case    VK_FORMAT_R16G16B16_SNORM:
        return "VK_FORMAT_R16G16B16_SNORM";
        case    VK_FORMAT_R16G16B16_USCALED:
        return "VK_FORMAT_R16G16B16_USCALED";
        case    VK_FORMAT_R16G16B16_SSCALED:
        return "VK_FORMAT_R16G16B16_SSCALED";
        case    VK_FORMAT_R16G16B16_UINT:
        return "VK_FORMAT_R16G16B16_UINT";
        case    VK_FORMAT_R16G16B16_SINT:
        return "VK_FORMAT_R16G16B16_SINT";
        case    VK_FORMAT_R16G16B16_SFLOAT:
        return "VK_FORMAT_R16G16B16_SFLOAT";
        case    VK_FORMAT_R16G16B16A16_UNORM:
        return "VK_FORMAT_R16G16B16A16_UNORM";
        case    VK_FORMAT_R16G16B16A16_SNORM:
        return "VK_FORMAT_R16G16B16A16_SNORM";
        case    VK_FORMAT_R16G16B16A16_USCALED:
        return "VK_FORMAT_R16G16B16A16_USCALED";
        case    VK_FORMAT_R16G16B16A16_SSCALED:
        return "VK_FORMAT_R16G16B16A16_SSCALED";
        case    VK_FORMAT_R16G16B16A16_UINT:
        return "VK_FORMAT_R16G16B16A16_UINT";
        case    VK_FORMAT_R16G16B16A16_SINT:
        return "VK_FORMAT_R16G16B16A16_SINT";
        case    VK_FORMAT_R16G16B16A16_SFLOAT:
        return "VK_FORMAT_R16G16B16A16_SFLOAT";
        case    VK_FORMAT_R32_UINT:
        return "VK_FORMAT_R32_UINT";
        case    VK_FORMAT_R32_SINT:
        return "VK_FORMAT_R32_SINT";
        case    VK_FORMAT_R32_SFLOAT:
        return "VK_FORMAT_R32_SFLOAT";
        case    VK_FORMAT_R32G32_UINT:
        return "VK_FORMAT_R32G32_UINT";
        case    VK_FORMAT_R32G32_SINT:
        return "VK_FORMAT_R32G32_SINT";
        case    VK_FORMAT_R32G32_SFLOAT:
        return "VK_FORMAT_R32G32_SFLOAT";
        case    VK_FORMAT_R32G32B32_UINT:
        return "VK_FORMAT_R32G32B32_UINT";
        case    VK_FORMAT_R32G32B32_SINT:
        return "VK_FORMAT_R32G32B32_SINT";
        case    VK_FORMAT_R32G32B32_SFLOAT:
        return "VK_FORMAT_R32G32B32_SFLOAT";
        case    VK_FORMAT_R32G32B32A32_UINT:
        return "VK_FORMAT_R32G32B32A32_UINT";
        case    VK_FORMAT_R32G32B32A32_SINT:
        return "VK_FORMAT_R32G32B32A32_SINT";
        case    VK_FORMAT_R32G32B32A32_SFLOAT:
        return "VK_FORMAT_R32G32B32A32_SFLOAT";
        case    VK_FORMAT_R64_UINT:
        return "VK_FORMAT_R64_UINT";
        case    VK_FORMAT_R64_SINT:
        return "VK_FORMAT_R64_SINT";
        case    VK_FORMAT_R64_SFLOAT:
        return "VK_FORMAT_R64_SFLOAT";
        case    VK_FORMAT_R64G64_UINT:
        return "VK_FORMAT_R64G64_UINT";
        case    VK_FORMAT_R64G64_SINT:
        return "VK_FORMAT_R64G64_SINT";
        case    VK_FORMAT_R64G64_SFLOAT:
        return "VK_FORMAT_R64G64_SFLOAT";
        case    VK_FORMAT_R64G64B64_UINT:
        return "VK_FORMAT_R64G64B64_UINT";
        case    VK_FORMAT_R64G64B64_SINT:
        return "VK_FORMAT_R64G64B64_SINT";
        case    VK_FORMAT_R64G64B64_SFLOAT:
        return "VK_FORMAT_R64G64B64_SFLOAT";
        case    VK_FORMAT_R64G64B64A64_UINT:
        return "VK_FORMAT_R64G64B64A64_UINT";
        case    VK_FORMAT_R64G64B64A64_SINT:
        return "VK_FORMAT_R64G64B64A64_SINT";
        case    VK_FORMAT_R64G64B64A64_SFLOAT:
        return "VK_FORMAT_R64G64B64A64_SFLOAT";
        case    VK_FORMAT_B10G11R11_UFLOAT_PACK32:
        return "VK_FORMAT_B10G11R11_UFLOAT_PACK32";
        case    VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
        return "VK_FORMAT_E5B9G9R9_UFLOAT_PACK32";
        case    VK_FORMAT_D16_UNORM:
        return "VK_FORMAT_D16_UNORM";
        case    VK_FORMAT_X8_D24_UNORM_PACK32:
        return "VK_FORMAT_X8_D24_UNORM_PACK32";
        case    VK_FORMAT_D32_SFLOAT:
        return "VK_FORMAT_D32_SFLOAT";
        case    VK_FORMAT_S8_UINT:
        return "VK_FORMAT_S8_UINT";
        case    VK_FORMAT_D16_UNORM_S8_UINT:
        return "VK_FORMAT_D16_UNORM_S8_UINT";
        case    VK_FORMAT_D24_UNORM_S8_UINT:
        return "VK_FORMAT_D24_UNORM_S8_UINT";
        case    VK_FORMAT_D32_SFLOAT_S8_UINT:
        return "VK_FORMAT_D32_SFLOAT_S8_UINT";
        case    VK_FORMAT_BC1_RGB_UNORM_BLOCK:
        return "VK_FORMAT_BC1_RGB_UNORM_BLOCK";
        case    VK_FORMAT_BC1_RGB_SRGB_BLOCK:
        return "VK_FORMAT_BC1_RGB_SRGB_BLOCK";
        case    VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
        return "VK_FORMAT_BC1_RGBA_UNORM_BLOCK";
        case    VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        return "VK_FORMAT_BC1_RGBA_SRGB_BLOCK";
        case    VK_FORMAT_BC2_UNORM_BLOCK:
        return "VK_FORMAT_BC2_UNORM_BLOCK";
        case    VK_FORMAT_BC2_SRGB_BLOCK:
        return "VK_FORMAT_BC2_SRGB_BLOCK";
        case    VK_FORMAT_BC3_UNORM_BLOCK:
        return "VK_FORMAT_BC3_UNORM_BLOCK";
        case    VK_FORMAT_BC3_SRGB_BLOCK:
        return "VK_FORMAT_BC3_SRGB_BLOCK";
        case    VK_FORMAT_BC4_UNORM_BLOCK:
        return "VK_FORMAT_BC4_UNORM_BLOCK";
        case    VK_FORMAT_BC4_SNORM_BLOCK:
        return "VK_FORMAT_BC4_SNORM_BLOCK";
        case    VK_FORMAT_BC5_UNORM_BLOCK:
        return "VK_FORMAT_BC5_UNORM_BLOCK";
        case    VK_FORMAT_BC5_SNORM_BLOCK:
        return "VK_FORMAT_BC5_SNORM_BLOCK";
        case    VK_FORMAT_BC6H_UFLOAT_BLOCK:
        return "VK_FORMAT_BC6H_UFLOAT_BLOCK";
        case    VK_FORMAT_BC6H_SFLOAT_BLOCK:
        return "VK_FORMAT_BC6H_SFLOAT_BLOCK";
        case    VK_FORMAT_BC7_UNORM_BLOCK:
        return "VK_FORMAT_BC7_UNORM_BLOCK";
        case    VK_FORMAT_BC7_SRGB_BLOCK:
        return "VK_FORMAT_BC7_SRGB_BLOCK";
        case    VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
        return "VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK";
        case    VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
        return "VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK";
        case    VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
        return "VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK";
        case    VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
        return "VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK";
        case    VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
        return "VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK";
        case    VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
        return "VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK";
        case    VK_FORMAT_EAC_R11_UNORM_BLOCK:
        return "VK_FORMAT_EAC_R11_UNORM_BLOCK";
        case    VK_FORMAT_EAC_R11_SNORM_BLOCK:
        return "VK_FORMAT_EAC_R11_SNORM_BLOCK";
        case    VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
        return "VK_FORMAT_EAC_R11G11_UNORM_BLOCK";
        case    VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
        return "VK_FORMAT_EAC_R11G11_SNORM_BLOCK";
        case    VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_4x4_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_4x4_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_5x4_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_5x4_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_5x5_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_5x5_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_6x5_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_6x5_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_6x6_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_6x6_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_8x5_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_8x5_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_8x6_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_8x6_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_8x8_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_8x8_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_10x5_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_10x5_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_10x6_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_10x6_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_10x8_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_10x8_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_10x10_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_10x10_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_12x10_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_12x10_SRGB_BLOCK";
        case    VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
        return "VK_FORMAT_ASTC_12x12_UNORM_BLOCK";
        case    VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
        return "VK_FORMAT_ASTC_12x12_SRGB_BLOCK";
        case    VK_FORMAT_G8B8G8R8_422_UNORM:
        return "VK_FORMAT_G8B8G8R8_422_UNORM";
        case    VK_FORMAT_B8G8R8G8_422_UNORM:
        return "VK_FORMAT_B8G8R8G8_422_UNORM";
        case    VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
        return "VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM";
        case    VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
        return "VK_FORMAT_G8_B8R8_2PLANE_420_UNORM";
        case    VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
        return "VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM";
        case    VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
        return "VK_FORMAT_G8_B8R8_2PLANE_422_UNORM";
        case    VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
        return "VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM";
        case    VK_FORMAT_R10X6_UNORM_PACK16:
        return "VK_FORMAT_R10X6_UNORM_PACK16";
        case    VK_FORMAT_R10X6G10X6_UNORM_2PACK16:
        return "VK_FORMAT_R10X6G10X6_UNORM_2PACK16";
        case    VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16:
        return "VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16";
        case    VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16:
        return "VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16";
        case    VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16:
        return "VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16";
        case    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
        return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16";
        case    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
        return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16";
        case    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
        return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16";
        case    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
        return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16";
        case    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
        return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16";
        case    VK_FORMAT_R12X4_UNORM_PACK16:
        return "VK_FORMAT_R12X4_UNORM_PACK16";
        case    VK_FORMAT_R12X4G12X4_UNORM_2PACK16:
        return "VK_FORMAT_R12X4G12X4_UNORM_2PACK16";
        case    VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16:
        return "VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16";
        case    VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16:
        return "VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16";
        case    VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16:
        return "VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16";
        case    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
        return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16";
        case    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
        return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16";
        case    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
        return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16";
        case    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
        return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16";
        case    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
        return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16";
        case    VK_FORMAT_G16B16G16R16_422_UNORM:
        return "VK_FORMAT_G16B16G16R16_422_UNORM";
        case    VK_FORMAT_B16G16R16G16_422_UNORM:
        return "VK_FORMAT_B16G16R16G16_422_UNORM";
        case    VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
        return "VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM";
        case    VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
        return "VK_FORMAT_G16_B16R16_2PLANE_420_UNORM";
        case    VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
        return "VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM";
        case    VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
        return "VK_FORMAT_G16_B16R16_2PLANE_422_UNORM";
        case    VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
        return "VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM";
        case    VK_FORMAT_G8_B8R8_2PLANE_444_UNORM:
        return "VK_FORMAT_G8_B8R8_2PLANE_444_UNORM";
        case    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16:
        return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16";
        case    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16:
        return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16";
        case    VK_FORMAT_G16_B16R16_2PLANE_444_UNORM:
        return "VK_FORMAT_G16_B16R16_2PLANE_444_UNORM";
        case    VK_FORMAT_A4R4G4B4_UNORM_PACK16:
        return "VK_FORMAT_A4R4G4B4_UNORM_PACK16";
        case    VK_FORMAT_A4B4G4R4_UNORM_PACK16:
        return "VK_FORMAT_A4B4G4R4_UNORM_PACK16";
        case    VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK";
        case    VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK:
        return "VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK";
        case    VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG:
        return "VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG";
        case    VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG:
        return "VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG";
        case    VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
        return "VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG";
        case    VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
        return "VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG";
        case    VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
        return "VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG";
        case    VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
        return "VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG";
        case    VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
        return "VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG";
        case    VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
        return "VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG";
        case    VK_FORMAT_R16G16_S10_5_NV:
        return "VK_FORMAT_R16G16_S10_5_NV";
        case    VK_FORMAT_MAX_ENUM:
        return "VK_FORMAT_MAX_ENUM";
    }
    snprintf(
        vxEnumNameBuffer, sizeof(vxEnumNameBuffer),
        "((VkFormat)%i)", format
    );
    return vxEnumNameBuffer;
}

const char* vxColorSpaceName(VkColorSpaceKHR colorSpace) {
    switch (colorSpace) {
        case    VK_COLOR_SPACE_SRGB_NONLINEAR_KHR:
        return "VK_COLOR_SPACE_SRGB_NONLINEAR_KHR";
        case    VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT:
        return "VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT";
        case    VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT:
        return "VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT";
        case    VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT:
        return "VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT";
        case    VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT:
        return "VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT";
        case    VK_COLOR_SPACE_BT709_LINEAR_EXT:
        return "VK_COLOR_SPACE_BT709_LINEAR_EXT";
        case    VK_COLOR_SPACE_BT709_NONLINEAR_EXT:
        return "VK_COLOR_SPACE_BT709_NONLINEAR_EXT";
        case    VK_COLOR_SPACE_BT2020_LINEAR_EXT:
        return "VK_COLOR_SPACE_BT2020_LINEAR_EXT";
        case    VK_COLOR_SPACE_HDR10_ST2084_EXT:
        return "VK_COLOR_SPACE_HDR10_ST2084_EXT";
        case    VK_COLOR_SPACE_DOLBYVISION_EXT:
        return "VK_COLOR_SPACE_DOLBYVISION_EXT";
        case    VK_COLOR_SPACE_HDR10_HLG_EXT:
        return "VK_COLOR_SPACE_HDR10_HLG_EXT";
        case    VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT:
        return "VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT";
        case    VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT:
        return "VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT";
        case    VK_COLOR_SPACE_PASS_THROUGH_EXT:
        return "VK_COLOR_SPACE_PASS_THROUGH_EXT";
        case    VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT:
        return "VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT";
        case    VK_COLOR_SPACE_DISPLAY_NATIVE_AMD:
        return "VK_COLOR_SPACE_DISPLAY_NATIVE_AMD";
        case    VK_COLOR_SPACE_MAX_ENUM_KHR:
        return "VK_COLOR_SPACE_MAX_ENUM_KHR";
    }
    snprintf(
        vxEnumNameBuffer, sizeof(vxEnumNameBuffer),
        "((VkColorSpaceKHR)%i)", colorSpace
    );
    return vxEnumNameBuffer;
}

const char* vxDescriptorTypeName(VkDescriptorType descriptorType) {
    switch (descriptorType) {
        case    VK_DESCRIPTOR_TYPE_SAMPLER:
        return "VK_DESCRIPTOR_TYPE_SAMPLER";
        case    VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        return "VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER";
        case    VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        return "VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE";
        case    VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        return "VK_DESCRIPTOR_TYPE_STORAGE_IMAGE";
        case    VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        return "VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER";
        case    VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
        return "VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER";
        case    VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        return "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER";
        case    VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        return "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER";
        case    VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        return "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC";
        case    VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
        return "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC";
        case    VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
        return "VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT";
        case    VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
        return "VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK";
        case    VK_DESCRIPTOR_TYPE_MAX_ENUM:
        return "VK_DESCRIPTOR_TYPE_MAX_ENUM";
        case    VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
        return "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR";
        case    VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
        return "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV";
        case    VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM:
        return "VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM";
        case    VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM:
        return "VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM";
        case    VK_DESCRIPTOR_TYPE_MUTABLE_EXT:
        return "VK_DESCRIPTOR_TYPE_MUTABLE_EXT";
    }
    snprintf(
        vxEnumNameBuffer, sizeof(vxEnumNameBuffer),
        "((VkDescriptorType)%i)", descriptorType
    );
    return vxEnumNameBuffer;
}

//------------------------------------------------------------------------------

VkResult vxExpectNonErrorCallback(
    const char* file, const int line,
    const char* expr, const VkResult result
) {
    if (result < 0) {
        vxPrintf(
            VX_ERROR("%s:%i: %s returned %s\n"),
            file, line, expr, vxResultName(result)
        );
    }
    else if (result > 0) {
        vxPrintf(
            VX_INFO("%s:%i: %s returned %s\n"),
            file, line, expr, vxResultName(result)
        );
    }
    return result;
}

//------------------------------------------------------------------------------

VkResult vxExpectSuccessCallback(
    const char* file, const int line,
    const char* expr, const VkResult result
) {
    if (result < 0) {
        vxPrintf(
            VX_ERROR("%s:%i: %s returned %s\n"),
            file, line, expr, vxResultName(result)
        );
    }
    else if (result > 0) {
        vxPrintf(
            VX_WARNING("%s:%i: %s returned %s\n"),
            file, line, expr, vxResultName(result)
        );
    }
    return result;
}

//------------------------------------------------------------------------------

VkResult
vxAssertNonErrorCallback(
    const char* file, const int line,
    const char* expr, const VkResult result
) {
    if (result < 0) {
        vxPrintf(
            VX_ERROR("%s:%i: %s returned %s\n"),
            file, line, expr, vxResultName(result)
        );
        exit(1);
    }
    else if (result > 0) {
        vxPrintf(
            VX_WARNING("%s:%i: %s returned %s\n"),
            file, line, expr, vxResultName(result)
        );
    }
    return result;
}

//------------------------------------------------------------------------------

VkResult
vxAssertSuccessCallback(
    const char* file, const int line,
    const char* expr, const VkResult result
) {
    if (result < 0) {
        vxPrintf(
            VX_ERROR("%s:%i: %s returned %s\n"),
            file, line, expr, vxResultName(result)
        );
        exit(1);
    }
    else if (result > 0) {
        vxPrintf(
            VX_WARNING("%s:%i: %s returned %s\n"),
            file, line, expr, vxResultName(result)
        );
        exit(1);
    }
    return result;
}

//------------------------------------------------------------------------------

VKAPI_ATTR VkBool32
VKAPI_CALL vxDebugUtilsMessengerCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData
) {
    const char* escape = "";
    const char* severity = "";
    switch (messageSeverity) {
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
            severity = "verbose"; escape = VX_ESCAPE_CODE_LTCYAN;
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
            severity = "info   "; escape = VX_ESCAPE_CODE_LTGREEN;
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
            severity = "warning"; escape = VX_ESCAPE_CODE_LTYELLOW;
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
            severity = "error  "; escape = VX_ESCAPE_CODE_LTRED;
            break;
        default:
            severity =
                "???";
            break;
    }

    const char* type = "";
    switch (messageType) {
        case VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT:
            type = "general"; break;
        case VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT:
            type = "validation"; break;
        case VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT:
            type = "performance"; break;
        case VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT:
            type = "device address binding"; break;
        default:
            type = "???"; break;
    }

    if (pCallbackData->messageIdNumber == 0) {
        vxPrintf("%svx %s (%s): %s: %s" VX_ESCAPE_CODE_RESET "\n",
            escape, severity, type,
            pCallbackData->pMessageIdName,
            pCallbackData->pMessage
        );
    } else {
        vxPrintf("%svx %s (%s): %s #%i: %s" VX_ESCAPE_CODE_RESET "\n",
            escape, severity, type,
            pCallbackData->pMessageIdName,
            pCallbackData->messageIdNumber,
            pCallbackData->pMessage
        );
    }

    return VK_FALSE;
}

//------------------------------------------------------------------------------

static inline
bool vxFindQueueFamilyIndex(
    const uint32_t queueFamilyPropertyCount,
    VkQueueFamilyProperties* queueFamilyProperties,
    VkQueueFlags queueFlags,
    uint32_t* pQueueFamilyIndex
) {
    for (uint32_t i = 0; i < queueFamilyPropertyCount; ++i) {
        if ((queueFamilyProperties[i].queueFlags & queueFlags) == queueFlags) {
            *pQueueFamilyIndex = i;
            return true;
        }
    }
    *pQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    return false;
}

//------------------------------------------------------------------------------

VkResult
vxSelectPhysicalDevice(
    VxContext*           pContext,
    VkSurfaceKHR         surface,
    uint32_t             requiredApiVersion,
    VkPhysicalDeviceType preferredDeviceType
) {
    VkPhysicalDevice physicalDevices[16] = vxInit;
    uint32_t physicalDeviceCount = vxLengthOf(physicalDevices);
    vxExpectNonErrorOrReturn(
        vkEnumeratePhysicalDevices(
            pContext->instance,
            &physicalDeviceCount,
            physicalDevices
        ),{}
    );

    typedef struct VxPhysicalDeviceInfo {
        VkPhysicalDevice             physicalDevice;
        VkPhysicalDeviceProperties   physicalDeviceProperties;
        uint32_t                     computeQueueFamilyIndex;
        uint32_t                     graphicsQueueFamilyIndex;
    } VxPhysicalDeviceInfo;

    VxPhysicalDeviceInfo preferred = vxInit;
    VxPhysicalDeviceInfo fallback  = vxInit;

    for (uint32_t i = 0; i < physicalDeviceCount; ++i) {
        if (preferred.physicalDevice && fallback.physicalDevice)
            break;

        VxPhysicalDeviceInfo candidate = vxInit;
        candidate.physicalDevice = physicalDevices[i];

        vkGetPhysicalDeviceProperties(
            candidate.physicalDevice,
            &candidate.physicalDeviceProperties
        );

        if (candidate.physicalDeviceProperties.apiVersion < requiredApiVersion)
            continue;

        VkQueueFamilyProperties queueFamilyProperties[64] = {vxInit};
        uint32_t queueFamilyPropertyCount = vxLengthOf(queueFamilyProperties);
        vkGetPhysicalDeviceQueueFamilyProperties(
            candidate.physicalDevice,
            &queueFamilyPropertyCount,
            queueFamilyProperties
        );

        if (queueFamilyPropertyCount == 0)
            continue;

        if (!vxFindQueueFamilyIndex(
                queueFamilyPropertyCount,
                queueFamilyProperties,
                VK_QUEUE_COMPUTE_BIT,
                &candidate.computeQueueFamilyIndex
            ))
            continue;

        if (!vxFindQueueFamilyIndex(
                queueFamilyPropertyCount,
                queueFamilyProperties,
                VK_QUEUE_GRAPHICS_BIT,
                &candidate.graphicsQueueFamilyIndex
            ))
            continue;

        vxAssert(vkGetPhysicalDeviceSurfaceSupportKHR);
        VkBool32 presentationSupported = false;
        if (VK_SUCCESS != vxExpectSuccess(
                vkGetPhysicalDeviceSurfaceSupportKHR(
                    candidate.physicalDevice,
                    candidate.graphicsQueueFamilyIndex,
                    surface,
                    &presentationSupported
                )
            ))
            continue;

        if (!presentationSupported)
            continue;

        const bool hasPreferredDeviceType
            = candidate.physicalDeviceProperties.deviceType
            == preferredDeviceType;

        if (!preferred.physicalDevice && hasPreferredDeviceType) {
            preferred = candidate;
            continue;
        }

        if (!fallback.physicalDevice) {
            fallback = candidate;
            continue;
        }
    }

    if (!preferred.physicalDevice && !fallback.physicalDevice) {
        vxDiagnosticf("vxSelectPhysicalDevice(): no viable physical device");
        return VK_ERROR_UNKNOWN;
    }

    VxPhysicalDeviceInfo selected
        = preferred.physicalDevice
        ? preferred
        : fallback;

    pContext->physicalDevice           = selected.physicalDevice;
    pContext->physicalDeviceProperties = selected.physicalDeviceProperties;
    pContext->computeQueueFamilyIndex  = selected.computeQueueFamilyIndex;
    pContext->graphicsQueueFamilyIndex = selected.graphicsQueueFamilyIndex;
    return VK_SUCCESS;
}

//------------------------------------------------------------------------------

typedef struct VxNativeWindow VxNativeWindow;

#if defined(VK_USE_PLATFORM_WIN32_KHR)

    struct VxNativeWindow { HINSTANCE hinstance; HWND hwnd; };

#elif defined(VK_USE_PLATFORM_MACOS_MVK)

    #error "todo"

#elif defined(VK_USE_PLATFORM_IOS_MVK)

    #error "todo"

#elif defined(VK_USE_PLATFORM_XLIB_KHR)

    #error "todo"

#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)

    #error "todo"

#else

    #error "unsupported platform"

#endif

void vxCreateNativeWindow(VxNativeWindow* pNativeWindow) {
    *pNativeWindow = (VxNativeWindow)vxInit;

    #if defined(VK_USE_PLATFORM_WIN32_KHR)

        static size_t wndClassAtom = 0;
        if (!wndClassAtom) {
            typedef uint32_t (__stdcall *WndProc)(
                HWND     hWnd,
                uint32_t Msg,
                uint64_t wParam,
                int64_t  lParam
            );

            typedef struct tagWNDCLASSEXA {
                uint32_t    cbSize;
                uint32_t    style;
                WndProc     lpfnWndProc;
                int         cbClsExtra;
                int         cbWndExtra;
                HINSTANCE   hInstance;
                void*       hIcon;
                void*       hCursor;
                void*       hbrBackground;
                const char* lpszMenuName;
                const char* lpszClassName;
                void*       hIconSm;
            } WNDCLASSEXA;

            extern uint32_t __stdcall DefWindowProcA(
                HWND     hWnd,
                uint32_t Msg,
                uint64_t wParam,
                int64_t  lParam
            );

            WNDCLASSEXA wc   = { sizeof(wc) };
            wc.lpfnWndProc   = DefWindowProcA;
            wc.lpszClassName = "VxNativeWindow";

            extern uint16_t __stdcall RegisterClassExA(
                const WNDCLASSEXA*
            );

            wndClassAtom = RegisterClassExA(&wc);
        }

        extern HMODULE __stdcall GetModuleHandleA(
            const char* lpModuleName
        );

        extern HWND __stdcall CreateWindowExA(
            uint32_t    dwExStyle,
            const char* lpClassName,
            const char* lpWindowName,
            uint32_t    dwStyle,
            int         X,
            int         Y,
            int         nWidth,
            int         nHeight,
            HWND        hWndParent,
            const void* hMenu,
            HINSTANCE   hInstance,
            const void* lpParam
        );

        const uint32_t  dwExStyle = 0;
        const char*     lpClassName = (const char*)wndClassAtom;
        const char*     lpWindowName = "VxNativeWindow";
        const uint32_t  dwStyle = 0;
        const int       X = 64;
        const int       Y = 64;
        const int       nWidth = 256;
        const int       nHeight = 256;
        const HWND      hWndParent = nullptr;
        const void*     hMenu = nullptr;
        const HINSTANCE hInstance = GetModuleHandleA(nullptr);
        const void*     lpParam = nullptr;

        pNativeWindow->hinstance = hInstance;
        pNativeWindow->hwnd = CreateWindowExA(
            dwExStyle,
            lpClassName,
            lpWindowName,
            dwStyle,
            X,
            Y,
            nWidth,
            nHeight,
            hWndParent,
            hMenu,
            hInstance,
            lpParam
        );

    #elif defined(VK_USE_PLATFORM_MACOS_MVK)

        #error "todo"

    #elif defined(VK_USE_PLATFORM_IOS_MVK)

        #error "todo"

    #elif defined(VK_USE_PLATFORM_XLIB_KHR)

        #error "todo"

    #elif defined(VK_USE_PLATFORM_WAYLAND_KHR)

        #error "todo"

    #else

        #error "unsupported platform"

    #endif
}

void vxDestroyNativeWindow(VxNativeWindow* pNativeWindow) {
    #if defined(VK_USE_PLATFORM_WIN32_KHR)

        extern int __stdcall DestroyWindow(HWND hWnd);

        DestroyWindow(pNativeWindow->hwnd);

    #elif defined(VK_USE_PLATFORM_MACOS_MVK)

        #error "todo"

    #elif defined(VK_USE_PLATFORM_IOS_MVK)

        #error "todo"

    #elif defined(VK_USE_PLATFORM_XLIB_KHR)

        #error "todo"

    #elif defined(VK_USE_PLATFORM_WAYLAND_KHR)

        #error "todo"

    #else

        #error "unsupported platform"

    #endif

    *pNativeWindow = (VxNativeWindow)vxInit;
}

//------------------------------------------------------------------------------

VkResult
vxCreateNativeSurface(
    const VxContext*      pContext,
    const VxNativeWindow* pNativeWindow,
    VkSurfaceKHR*         pSurface
) {
    #if defined(VK_USE_PLATFORM_WIN32_KHR)

        VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = vxInit;
        surfaceCreateInfo.sType
            = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
        surfaceCreateInfo.hinstance = pNativeWindow->hinstance;
        surfaceCreateInfo.hwnd = pNativeWindow->hwnd;

        vxAssert(vkCreateWin32SurfaceKHR);
        return vkCreateWin32SurfaceKHR(
            pContext->instance,
            &surfaceCreateInfo,
            pContext->pAllocator,
            pSurface
        );

    #elif defined(VK_USE_PLATFORM_MACOS_MVK)

        #error "todo"

    #elif defined(VK_USE_PLATFORM_IOS_MVK)

        #error "todo"

    #elif defined(VK_USE_PLATFORM_XLIB_KHR)

        #error "todo"

    #elif defined(VK_USE_PLATFORM_WAYLAND_KHR)

        #error "todo"

    #else

        #error "unsupported platform"

    #endif
}

void
vxDestroyNativeSurface(const VxContext* pContext, VkSurfaceKHR surface) {
    vkDestroySurfaceKHR(pContext->instance, surface, pContext->pAllocator);
}

//------------------------------------------------------------------------------

VkResult
vxCreateContext(const VxContextCreateInfo* pCreateInfo, VxContext* pContext) {
    #ifdef VX_USE_VOLK
        vxExpectSuccessOrReturn(volkInitialize(),{});
    #endif

    *pContext = (VxContext)vxInit;

    pContext->pAllocator = pCreateInfo ? pCreateInfo->pAllocator : nullptr;

    const uint32_t requiredApiVersion =
        pCreateInfo &&
        pCreateInfo->pInstanceCreateInfo &&
        pCreateInfo->pInstanceCreateInfo->pApplicationInfo
        ? pCreateInfo
            ->pInstanceCreateInfo
            ->pApplicationInfo
            ->apiVersion
        : VK_API_VERSION_1_3;

    const VkPhysicalDeviceType preferredDeviceType =
        pCreateInfo
        ? pCreateInfo->preferredDeviceType
        : VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;

    if (pCreateInfo && pCreateInfo->pInstanceCreateInfo) {
        vxExpectSuccessOrReturn(
            vkCreateInstance(
                pCreateInfo->pInstanceCreateInfo,
                pContext->pAllocator, &pContext->instance
            ),{}
        );
    } else {
        VkApplicationInfo applicationInfo = {
            VK_STRUCTURE_TYPE_APPLICATION_INFO,
        };
        applicationInfo.apiVersion = requiredApiVersion;

        VkValidationFeatureEnableEXT enabledValidationFeatures[] = {
            VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT,
            VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT,
            VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT,
            // VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT,
            VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT,
        };

        VkValidationFeaturesEXT validationFeatures = {
            VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT,
        };
        validationFeatures.enabledValidationFeatureCount
            = vxLengthOf(enabledValidationFeatures);
        validationFeatures.pEnabledValidationFeatures
            = enabledValidationFeatures;

        VkDebugUtilsMessengerCreateInfoEXT debugUtilsMessengerCreateInfo = vxInit;
        debugUtilsMessengerCreateInfo.sType
            = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        debugUtilsMessengerCreateInfo.pNext = &validationFeatures;
        debugUtilsMessengerCreateInfo.messageSeverity
            = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT
            | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT
            | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
            | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        debugUtilsMessengerCreateInfo.messageType
            = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT
            | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT
            | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT
            | VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT;
        debugUtilsMessengerCreateInfo.pfnUserCallback = 
            vxDebugUtilsMessengerCallback;

        const char* enabledLayerNames[] = {
            "VK_LAYER_KHRONOS_validation",
        };

        const char* enabledExtensionNames[] = {
            VK_KHR_SURFACE_EXTENSION_NAME,
            /* Attempting to enable extension VK_EXT_debug_utils, but this
             * extension is intended to support use by applications when
             * debugging and it is strongly recommended that it be otherwise
             * avoided.
             */
            // VK_EXT_DEBUG_UTILS_EXTENSION_NAME,

            #ifdef VK_USE_PLATFORM_WIN32_KHR
                VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
            #endif

            #ifdef VK_USE_PLATFORM_MACOS_MVK
                VK_MVK_MACOS_SURFACE_EXTENSION_NAME,
            #endif

            #ifdef VK_USE_PLATFORM_XLIB_KHR
                VK_KHR_XLIB_SURFACE_EXTENSION_NAME,
            #endif
        };

        VkInstanceCreateInfo createInfo = {
            VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        };
        createInfo.pNext = &debugUtilsMessengerCreateInfo;
        createInfo.pApplicationInfo = &applicationInfo;
        createInfo.enabledLayerCount = vxLengthOf(enabledLayerNames);
        createInfo.ppEnabledLayerNames = enabledLayerNames;
        createInfo.enabledExtensionCount = vxLengthOf(enabledExtensionNames);
        createInfo.ppEnabledExtensionNames = enabledExtensionNames;

        vxExpectSuccessOrReturn(
            vkCreateInstance(
                &createInfo,
                pContext->pAllocator, &pContext->instance
            ),{}
        );
    }

    vxAssert(pContext->instance);

    #ifdef VX_USE_VOLK
        volkLoadInstanceOnly(pContext->instance);
    #endif

    { // select physical device
        VxNativeWindow nativeWindow;
        vxCreateNativeWindow(&nativeWindow);

        VkSurfaceKHR surface;
        vxCreateNativeSurface(pContext, &nativeWindow, &surface);

        vxExpectSuccessOrReturn(
            vxSelectPhysicalDevice(
                pContext,
                surface,
                requiredApiVersion,
                preferredDeviceType
            ),{
                vxDestroyNativeSurface(pContext, surface);
                vxDestroyNativeWindow(&nativeWindow);
                vkDestroyInstance(pContext->instance, pContext->pAllocator);
            }
        );

        vkGetPhysicalDeviceMemoryProperties(
            pContext->physicalDevice,
            &pContext->physicalDeviceMemoryProperties
        );

        VkSurfaceCapabilitiesKHR surfaceCapabilities;
        vxExpectSuccessOrReturn(
            vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
                pContext->physicalDevice,
                surface,
                &surfaceCapabilities
            ),{}
        );

        VxContextSurfaceCapabilities* vxSurfaceCapabilities
            = &pContext->surfaceCapabilities;
        #define vxCopySurfaceCapability(field) \
                vxSurfaceCapabilities->field = surfaceCapabilities.field
                vxCopySurfaceCapability(minImageCount);
                vxCopySurfaceCapability(maxImageCount);
                vxCopySurfaceCapability(maxImageArrayLayers);
                vxCopySurfaceCapability(supportedTransforms);
                vxCopySurfaceCapability(supportedCompositeAlpha);
                vxCopySurfaceCapability(supportedUsageFlags);
        #undef  vxCopySurfaceCapability

        pContext->surfaceFormatCount = vxLengthOf(pContext->surfaceFormats);
        vxExpectNonErrorOrReturn(
            vkGetPhysicalDeviceSurfaceFormatsKHR(
                pContext->physicalDevice,
                surface,
                &pContext->surfaceFormatCount,
                pContext->surfaceFormats
            ),{
                vxDestroyNativeSurface(pContext, surface);
                vxDestroyNativeWindow(&nativeWindow);
                vkDestroyInstance(pContext->instance, pContext->pAllocator);
            }
        );

        vxDestroyNativeSurface(pContext, surface);
        vxDestroyNativeWindow(&nativeWindow);
    }

    if (pCreateInfo && pCreateInfo->pDeviceCreateInfo) {
        vxExpectSuccessOrReturn(
            vkCreateDevice(
                pContext->physicalDevice,
                pCreateInfo->pDeviceCreateInfo,
                pContext->pAllocator,
                &pContext->device
            ),{
                vkDestroyInstance(pContext->instance, pContext->pAllocator);
            }
        );
    } else {
        float queuePriorities[] = { 1.f };

        VkDeviceQueueCreateInfo queueCreateInfo[] = {
            { VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO },
            { VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO },
        };

        // compute
        queueCreateInfo[0].queueFamilyIndex = pContext->computeQueueFamilyIndex;
        queueCreateInfo[0].queueCount = 1;
        queueCreateInfo[0].pQueuePriorities = queuePriorities;

        // graphics
        queueCreateInfo[1].queueFamilyIndex = pContext->graphicsQueueFamilyIndex;
        queueCreateInfo[1].queueCount = 1;
        queueCreateInfo[1].pQueuePriorities = queuePriorities;

        const uint32_t queueCreateInfoCount =
            pContext->computeQueueFamilyIndex ==
            pContext->graphicsQueueFamilyIndex
            ? 1
            : 2;

        const char* extensions[] = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME,
        };

        VkPhysicalDeviceVulkan13Features vk13features = {
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES,
        };
        vk13features.synchronization2 = true;
        vk13features.dynamicRendering = true;
        vk13features.maintenance4     = true;

        VkPhysicalDeviceVulkan12Features vk12features = {
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES,
        };
        vk12features.pNext = &vk13features;
        vk12features.drawIndirectCount = true;
        vk12features.storageBuffer8BitAccess = true;
        vk12features.uniformAndStorageBuffer8BitAccess = true;
        vk12features.shaderFloat16 = true;
        vk12features.shaderInt8 = true;
        vk12features.samplerFilterMinmax = true;
        vk12features.scalarBlockLayout = true;

        VkPhysicalDeviceVulkan11Features vk11features = {
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES,
        };
        vk11features.pNext = &vk12features;
        vk11features.storageBuffer16BitAccess = true;
        vk11features.shaderDrawParameters = true;

        VkPhysicalDeviceFeatures2 features2 = {
            VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2,
        };
        features2.pNext = &vk11features;
        features2.features.multiDrawIndirect = true;
        features2.features.samplerAnisotropy = true;
        features2.features.pipelineStatisticsQuery = true;
        features2.features.shaderInt64 = true;
        features2.features.shaderInt16 = true;

        VkDeviceCreateInfo deviceCreateInfo = {
            VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
        };
        deviceCreateInfo.pNext = &features2;
        deviceCreateInfo.queueCreateInfoCount = queueCreateInfoCount;
        deviceCreateInfo.pQueueCreateInfos = queueCreateInfo;
        deviceCreateInfo.enabledExtensionCount = vxLengthOf(extensions);
        deviceCreateInfo.ppEnabledExtensionNames = extensions;

        vxAssert(pContext->physicalDevice);

        vxExpectSuccessOrReturn(
            vkCreateDevice(
                pContext->physicalDevice,
                &deviceCreateInfo,
                pContext->pAllocator,
                &pContext->device
            ),{
                vxDestroyContext(pContext);
            }
        );
    }

    #ifdef VX_USE_VOLK
        volkLoadDevice(pContext->device);
    #endif

    vkGetDeviceQueue(
        pContext->device,
        pContext->computeQueueFamilyIndex, 0,
        &pContext->computeQueue
    );

    vkGetDeviceQueue(
        pContext->device,
        pContext->graphicsQueueFamilyIndex, 0,
        &pContext->graphicsQueue
    );

    { // command pool
        VkCommandPoolCreateInfo commandPoolCreateInfo = {
            VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
        };
        commandPoolCreateInfo.pNext
            = (pCreateInfo && pCreateInfo->pCommandPoolCreateInfo)
            ? (pCreateInfo->pCommandPoolCreateInfo->pNext)
            : nullptr;
        commandPoolCreateInfo.flags
            = (pCreateInfo && pCreateInfo->pCommandPoolCreateInfo)
            ? (pCreateInfo->pCommandPoolCreateInfo->flags)
            | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT
            : VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        commandPoolCreateInfo.queueFamilyIndex
            = pContext->graphicsQueueFamilyIndex;

        vxExpectSuccessOrReturn(
            vkCreateCommandPool(
                pContext->device,
                &commandPoolCreateInfo,
                pContext->pAllocator,
                &pContext->commandPool
            ),{
                vxDestroyContext(pContext);
            }
        );

        VkCommandBufferAllocateInfo commandBufferAllocateInfo = {
            VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        };
        commandBufferAllocateInfo.commandPool = pContext->commandPool;
        commandBufferAllocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        commandBufferAllocateInfo.commandBufferCount = 1;

        vxExpectSuccessOrReturn(
            vkAllocateCommandBuffers(
                pContext->device,
                &commandBufferAllocateInfo,
                &pContext->commandBuffer
            ),{
                vxDestroyContext(pContext);
            }
        );
    }

    { // pipeline cache
        VkPipelineCacheCreateInfo pipelineCacheCreateInfo = {
            VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO,
        };
        vxExpectSuccessOrReturn(
            vkCreatePipelineCache(
                pContext->device,
                &pipelineCacheCreateInfo,
                pContext->pAllocator,
                &pContext->pipelineCache
            ),{
                vxDestroyContext(pContext);
            }
        );
    }

    return VK_SUCCESS;
}

void
vxDestroyContext(VxContext* pContext) {
    if (pContext->device) {
        vxAssertSuccess(vkDeviceWaitIdle(pContext->device));
        if (pContext->pipelineCache) {
            vkDestroyPipelineCache(
                pContext->device,
                pContext->pipelineCache,
                pContext->pAllocator
            );
            pContext->pipelineCache = VK_NULL_HANDLE;
        }
        if (pContext->commandBuffer) {
            vkFreeCommandBuffers(
                pContext->device,
                pContext->commandPool,
                1,
                &pContext->commandBuffer
            );
            pContext->commandBuffer = VK_NULL_HANDLE;
        }
        if (pContext->commandPool) {
            vkDestroyCommandPool(
                pContext->device,
                pContext->commandPool,
                pContext->pAllocator
            );
            pContext->commandPool = VK_NULL_HANDLE;
        }
        vkDestroyDevice(pContext->device, pContext->pAllocator);
        pContext->device = VK_NULL_HANDLE;
    }

    if (pContext->instance) {
        vkDestroyInstance(pContext->instance, pContext->pAllocator);
        pContext->instance = VK_NULL_HANDLE;
    }

    *pContext = (VxContext)vxInit;
}

//------------------------------------------------------------------------------

VkResult
vxCreateBindGroup(
    const VxContext*             pContext,
    const VxBindGroupCreateInfo* pCreateInfo,
    VxBindGroup*                 pBindGroup
) {
    *pBindGroup = (VxBindGroup)vxInit;

    { // descriptorPool
        VkDescriptorPoolSize poolSizes[VX_MAX_BIND_GROUP_BINDING_COUNT];
        for (uint32_t i = 0; i < pCreateInfo->bindingCount; ++i) {
            poolSizes[i] = (VkDescriptorPoolSize)vxInit;
            poolSizes[i].type = pCreateInfo->bindings[i].type;
            poolSizes[i].descriptorCount = 1;
        }

        VkDescriptorPoolCreateInfo poolCreateInfo = {
            VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
        };
        poolCreateInfo.maxSets = 1;
        poolCreateInfo.poolSizeCount = pCreateInfo->bindingCount;
        poolCreateInfo.pPoolSizes = poolSizes;

        vxExpectSuccessOrReturn(
            vkCreateDescriptorPool(
                pContext->device,
                &poolCreateInfo,
                pContext->pAllocator,
                &pBindGroup->descriptorPool
            ),{
                vxDestroyBindGroup(pContext, pBindGroup);
            }
        );
    }

    { // layout
        VkDescriptorSetLayoutBinding bindings[VX_MAX_BIND_GROUP_BINDING_COUNT];
        for (uint32_t i = 0; i < pCreateInfo->bindingCount; ++i) {
            bindings[i] = (VkDescriptorSetLayoutBinding)vxInit;
            bindings[i].binding = i;
            bindings[i].descriptorType = pCreateInfo->bindings[i].type;
            bindings[i].descriptorCount = 1;
            bindings[i].stageFlags = pCreateInfo->stageFlags;
        }

        VkDescriptorSetLayoutCreateInfo layoutCreateInfo = {
            VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
        };
        layoutCreateInfo.bindingCount = pCreateInfo->bindingCount;
        layoutCreateInfo.pBindings = bindings;

        vxExpectSuccessOrReturn(
            vkCreateDescriptorSetLayout(
                pContext->device,
                &layoutCreateInfo,
                pContext->pAllocator,
                &pBindGroup->descriptorSetLayout
            ),{
                vxDestroyBindGroup(pContext, pBindGroup);
            }
        );
    }

    { // descriptorSet
        VkDescriptorSetAllocateInfo setAllocateInfo = {
            VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
        };
        setAllocateInfo.descriptorPool = pBindGroup->descriptorPool;
        setAllocateInfo.descriptorSetCount = 1;
        setAllocateInfo.pSetLayouts = &pBindGroup->descriptorSetLayout;

        vxExpectSuccessOrReturn(
            vkAllocateDescriptorSets(
                pContext->device,
                &setAllocateInfo,
                &pBindGroup->descriptorSet
            ),{
                vxDestroyBindGroup(pContext, pBindGroup);
            }
        );
    }

    VkWriteDescriptorSet descriptorWrites[VX_MAX_BIND_GROUP_BINDING_COUNT];
    VkDescriptorImageInfo       imageInfo[VX_MAX_BIND_GROUP_BINDING_COUNT];
    VkDescriptorBufferInfo     bufferInfo[VX_MAX_BIND_GROUP_BINDING_COUNT];
    for (uint32_t i = 0; i < pCreateInfo->bindingCount; ++i) {
        descriptorWrites[i] = (VkWriteDescriptorSet)vxInit;
        descriptorWrites[i].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[i].dstSet = pBindGroup->descriptorSet;
        descriptorWrites[i].dstBinding = i;
        descriptorWrites[i].dstArrayElement = 0;
        descriptorWrites[i].descriptorCount = 1;
        descriptorWrites[i].descriptorType = pCreateInfo->bindings[i].type;
        switch (descriptorWrites[i].descriptorType) {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
                imageInfo[i] = (VkDescriptorImageInfo)vxInit;
                imageInfo[i].sampler     = pCreateInfo->bindings[i].sampler;
                descriptorWrites[i].pImageInfo = &imageInfo[i];
                break;
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                imageInfo[i] = (VkDescriptorImageInfo)vxInit;
                imageInfo[i].sampler     = pCreateInfo->bindings[i].sampler;
                imageInfo[i].imageView   = pCreateInfo->bindings[i].imageView;
                imageInfo[i].imageLayout = pCreateInfo->bindings[i].imageLayout;
                descriptorWrites[i].pImageInfo = &imageInfo[i];
                break;
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                imageInfo[i] = (VkDescriptorImageInfo)vxInit;
                imageInfo[i].imageView   = pCreateInfo->bindings[i].imageView;
                imageInfo[i].imageLayout = pCreateInfo->bindings[i].imageLayout;
                descriptorWrites[i].pImageInfo = &imageInfo[i];
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                vxErrorf("not implemented");
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                bufferInfo[i] = (VkDescriptorBufferInfo)vxInit;
                bufferInfo[i].buffer = pCreateInfo->bindings[i].buffer;
                bufferInfo[i].offset = pCreateInfo->bindings[i].bufferOffset;
                bufferInfo[i].range  = pCreateInfo->bindings[i].bufferRange;
                descriptorWrites[i].pBufferInfo = &bufferInfo[i];
                break;
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            default:
                vxErrorf("not implemented");
        }
    }

    vkUpdateDescriptorSets(
        pContext->device,
        pCreateInfo->bindingCount,
        descriptorWrites,
        0, NULL
    );

    return VK_SUCCESS;
}

void
vxDestroyBindGroup(
    const VxContext* pContext,
    VxBindGroup*     pBindGroup
) {
    if (pBindGroup->descriptorSetLayout) {
        vkDestroyDescriptorSetLayout(
            pContext->device,
            pBindGroup->descriptorSetLayout,
            pContext->pAllocator
        );
        pBindGroup->descriptorSetLayout = VK_NULL_HANDLE;
    }
    if (pBindGroup->descriptorPool) {
        vkDestroyDescriptorPool(
            pContext->device,
            pBindGroup->descriptorPool,
            pContext->pAllocator
        );
        pBindGroup->descriptorPool = VK_NULL_HANDLE;
    }

    *pBindGroup = (VxBindGroup)vxInit;
}

//------------------------------------------------------------------------------

VkResult
vxCreateCanvas(
    const VxContext*          pContext,
    const VxCanvasCreateInfo* pCreateInfo,
    VxCanvas*                 pCanvas
) {
    *pCanvas = (VxCanvas)vxInit;

    pCanvas->renderPass = pCreateInfo->renderPass;

    const VxContextSurfaceCapabilities* vxSurfaceCapabilities
        = &pContext->surfaceCapabilities;

    pCanvas->swapchainImageCount = pCreateInfo->swapchainImageCount;
    if (pCanvas->swapchainImageCount < vxSurfaceCapabilities->minImageCount)
        pCanvas->swapchainImageCount = vxSurfaceCapabilities->minImageCount;
    if (pCanvas->swapchainImageCount > vxSurfaceCapabilities->maxImageCount)
        pCanvas->swapchainImageCount = vxSurfaceCapabilities->maxImageCount;
    if (pCanvas->swapchainImageCount < VX_MIN_CANVAS_FRAME_COUNT)
        pCanvas->swapchainImageCount = VX_MIN_CANVAS_FRAME_COUNT;
    if (pCanvas->swapchainImageCount > VX_MAX_CANVAS_FRAME_COUNT)
        pCanvas->swapchainImageCount = VX_MAX_CANVAS_FRAME_COUNT;

    const VxWindowHandleType windowHandleType
        = pCreateInfo->windowHandleType
        ? pCreateInfo->windowHandleType
        : (
            #if defined(VK_USE_PLATFORM_WIN32_KHR)
                VX_WINDOW_HANDLE_TYPE_HWND
            #elif defined(VK_USE_PLATFORM_MACOS_MVK)
                VX_WINDOW_HANDLE_TYPE_NSWINDOW
            #elif defined(VK_USE_PLATFORM_XLIB_KHR)
                VX_WINDOW_HANDLE_TYPE_XLIB
            #elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
                VX_WINDOW_HANDLE_TYPE_WAYLAND
            #else
                #error "unsupported platform"
            #endif
        );

    // create pCanvas->surface
    switch (windowHandleType) {
        case VX_WINDOW_HANDLE_TYPE_HWND: {
            #if defined(VK_USE_PLATFORM_WIN32_KHR)

                extern size_t GetWindowLongPtrA(
                    HWND hWnd,
                    int  nIndex
                );

                HWND hwnd = (HWND)pCreateInfo->windowHandle;
                HINSTANCE hinstance = (HINSTANCE)GetWindowLongPtrA(hwnd, -6);

                VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = vxInit;
                surfaceCreateInfo.sType
                    = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
                surfaceCreateInfo.hinstance = hinstance;
                surfaceCreateInfo.hwnd      = hwnd;

                vxExpectSuccessOrReturn(
                    vkCreateWin32SurfaceKHR(
                        pContext->instance,
                        &surfaceCreateInfo,
                        pContext->pAllocator,
                        &pCanvas->surface
                    ),{}
                );
                break;

            #else // !defined(VK_USE_PLATFORM_WIN32_KHR)

                vxDiagnosticf("VX_WINDOW_HANDLE_TYPE_HWND unavailable");
                return VK_ERROR_FEATURE_NOT_PRESENT;

            #endif
        }
        case VX_WINDOW_HANDLE_TYPE_NSWINDOW: {
            vxDiagnosticf("VX_WINDOW_HANDLE_TYPE_NSWINDOW not implemented");
            return VK_ERROR_FEATURE_NOT_PRESENT;
        }
        case VX_WINDOW_HANDLE_TYPE_XLIB: {
            vxDiagnosticf("VX_WINDOW_HANDLE_TYPE_XLIB not implemented");
            return VK_ERROR_FEATURE_NOT_PRESENT;
        }
        case VX_WINDOW_HANDLE_TYPE_WAYLAND: {
            vxDiagnosticf("VX_WINDOW_HANDLE_TYPE_WAYLAND not implemented");
            return VK_ERROR_FEATURE_NOT_PRESENT;
        }
        case VX_WINDOW_HANDLE_TYPE_GLFW: {
            #if defined(VX_USE_GLFW3)

                vxExpectSuccessOrReturn(
                    glfwCreateWindowSurface(
                        pContext->instance,
                        (GLFWwindow*)pCreateInfo->windowHandle,
                        pContext->pAllocator,
                        &pCanvas->surface
                    ),{}
                );
                break;

            #else

                vxDiagnosticf("VX_WINDOW_HANDLE_TYPE_GLFW unavailable");
                return VK_ERROR_FEATURE_NOT_PRESENT;

            #endif
        }
        case VX_WINDOW_HANDLE_TYPE_SDL: {
            vxDiagnosticf("VX_WINDOW_HANDLE_TYPE_SDL not implemented");
            return VK_ERROR_FEATURE_NOT_PRESENT;
        }
        default: {
            vxDiagnosticf(
                "((VxSwapchainWindowHandleType)%u) unsupported",
                windowHandleType
            );
        }
    }

    { // validate pCanvasCreateInfo->surfaceFormat
        VkSurfaceFormatKHR surfaceFormats[VX_MAX_SURFACE_FORMAT_COUNT];
        uint32_t surfaceFormatCount = vxLengthOf(surfaceFormats);
        vxExpectNonErrorOrReturn(
            vkGetPhysicalDeviceSurfaceFormatsKHR(
                pContext->physicalDevice,
                pCanvas->surface,
                &surfaceFormatCount,
                surfaceFormats
            ),{
                vxDestroyCanvas(pContext, pCanvas);
            }
        );

        if (!surfaceFormatCount) {
            vxDestroyCanvas(pContext, pCanvas);
            return VK_ERROR_FORMAT_NOT_SUPPORTED;
        }

        bool hasExpectedSurfaceFormat = false;
        const VkSurfaceFormatKHR expected = pCreateInfo->surfaceFormat;
        for (uint32_t i = 0; i < surfaceFormatCount; ++i) {
            const VkSurfaceFormatKHR surfaceFormat = surfaceFormats[i];
            if (surfaceFormat.format     == expected.format &&
                surfaceFormat.colorSpace == expected.colorSpace) {
                hasExpectedSurfaceFormat = true;
                break;
            }
        }

        if (!hasExpectedSurfaceFormat) {
            vxDestroyCanvas(pContext, pCanvas);
            return VK_ERROR_FORMAT_NOT_SUPPORTED;
        }

        pCanvas->surfaceFormat = pCreateInfo->surfaceFormat;
    }

    { // select pCanvas->presentMode
        VkPresentModeKHR surfacePresentModes[VX_MAX_CANVAS_PRESENT_MODE_COUNT];
        uint32_t surfacePresentModeCount = vxLengthOf(surfacePresentModes);
        vxExpectNonErrorOrReturn(
            vkGetPhysicalDeviceSurfacePresentModesKHR(
                pContext->physicalDevice,
                pCanvas->surface,
                &surfacePresentModeCount,
                surfacePresentModes
            ),{
                vxDestroyCanvas(pContext, pCanvas);
            }
        );

        if (!surfacePresentModeCount) {
            vxDestroyCanvas(pContext, pCanvas);
            return VK_ERROR_FEATURE_NOT_PRESENT;
        }

        pCanvas->presentMode = VK_PRESENT_MODE_IMMEDIATE_KHR;

        const VkPresentModeKHR defaultPreferredPresentModes[] = {
            VK_PRESENT_MODE_MAILBOX_KHR,
            VK_PRESENT_MODE_FIFO_KHR,
        };

        const uint32_t preferredPresentModeCount
            = pCreateInfo->preferredPresentModeCount
            ? pCreateInfo->preferredPresentModeCount
            : vxLengthOf(defaultPreferredPresentModes);

        const VkPresentModeKHR* preferredPresentModes
            = pCreateInfo->preferredPresentModeCount
            ? pCreateInfo->preferredPresentModes
            : defaultPreferredPresentModes;

        for (uint32_t p = 0; p < preferredPresentModeCount; ++p)
        for (uint32_t s = 0; s < surfacePresentModeCount; ++s) {
            if (surfacePresentModes[s] == preferredPresentModes[p]) {
                pCanvas->presentMode = surfacePresentModes[s];
                goto selected_preferred_present_mode;
            }
        }

        selected_preferred_present_mode: ((void)0);
    }

    vxExpectSuccessOrReturn(
        vxResizeCanvas(pContext, pCanvas),{
            vxDestroyCanvas(pContext, pCanvas);
        }
    );
    return VK_SUCCESS;
}

VkResult
vxCreateCanvasFrames(const VxContext* pContext, VxCanvas* pCanvas) {
    VkImage swapchainImages[VX_MAX_CANVAS_FRAME_COUNT] = vxInit;
    uint32_t frameCount = vxLengthOf(swapchainImages);
    vxExpectSuccessOrReturn(
        vkGetSwapchainImagesKHR(
            pContext->device,
            pCanvas->swapchain,
            &frameCount, swapchainImages
        ),{}
    );

    if (!vxExpect(frameCount >= VX_MIN_CANVAS_FRAME_COUNT))
        return VK_ERROR_INITIALIZATION_FAILED;

    if (!vxExpect(frameCount <= VX_MAX_CANVAS_FRAME_COUNT))
        return VK_ERROR_INITIALIZATION_FAILED;

    pCanvas->frameCount = frameCount;

    VkImageViewCreateInfo swapchainImageViewCreateInfo = {
        VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
    };
    swapchainImageViewCreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
    swapchainImageViewCreateInfo.format   = pCanvas->surfaceFormat.format;
    swapchainImageViewCreateInfo.subresourceRange.aspectMask
        = VK_IMAGE_ASPECT_COLOR_BIT;
    swapchainImageViewCreateInfo.subresourceRange.baseMipLevel   = 0;
    swapchainImageViewCreateInfo.subresourceRange.levelCount     = 1;
    swapchainImageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
    swapchainImageViewCreateInfo.subresourceRange.layerCount     = 1;

    VkFramebufferCreateInfo framebufferCreateInfo = {
        VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
    };
    framebufferCreateInfo.renderPass      = pCanvas->renderPass;
    framebufferCreateInfo.attachmentCount = 1;
    framebufferCreateInfo.width           = pCanvas->extent.width;
    framebufferCreateInfo.height          = pCanvas->extent.height;
    framebufferCreateInfo.layers          = 1;

    VkFenceCreateInfo acquireFrameFenceCreateInfo = {
        VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
    };
    acquireFrameFenceCreateInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    VkSemaphoreCreateInfo semaphoreCreateInfo = {
        VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,
    };

    VkCommandBufferAllocateInfo commandBufferAllocateInfo = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
    };
    commandBufferAllocateInfo.commandPool = pContext->commandPool;
    commandBufferAllocateInfo.level       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    commandBufferAllocateInfo.commandBufferCount = pCanvas->frameCount;
    VkCommandBuffer commandBuffers[VX_MAX_CANVAS_FRAME_COUNT];
    vxExpectSuccessOrReturn(
        vkAllocateCommandBuffers(
            pContext->device,
            &commandBufferAllocateInfo,
            commandBuffers
        ),{}
    );

    for (uint32_t i = 0; i < VX_MAX_CANVAS_FRAME_COUNT; ++i) {
        pCanvas->frames[i].frameIndex = i;
    }

    for (uint32_t i = 0; i < pCanvas->frameCount; ++i) {
        VxCanvasFrame* pFrame = &pCanvas->frames[i];

        vxAssert(!pFrame->swapchainImage); {
            pFrame->swapchainImage = swapchainImages[i];
        }

        vxAssert(!pFrame->swapchainImageView); {
            swapchainImageViewCreateInfo.image = swapchainImages[i];
            vxExpectSuccessOrReturn(
                vkCreateImageView(
                    pContext->device,
                    &swapchainImageViewCreateInfo,
                    pContext->pAllocator,
                    &pFrame->swapchainImageView
                ),{}
            );
        }

        vxAssert(!pFrame->framebuffer); {
            framebufferCreateInfo.pAttachments = pFrame->attachmentImageViews;
            vxExpectSuccessOrReturn(
                vkCreateFramebuffer(
                    pContext->device,
                    &framebufferCreateInfo,
                    pContext->pAllocator,
                    &pFrame->framebuffer
                ),{}
            );
        }

        vxAssert(!pFrame->attachmentCount); {
            pFrame->attachmentCount = 1;
        }

        vxAssert(!pFrame->acquireWaitFence); {
            vxExpectSuccessOrReturn(
                vkCreateFence(
                    pContext->device,
                    &acquireFrameFenceCreateInfo,
                    pContext->pAllocator,
                    &pFrame->acquireWaitFence
                ),{}
            );
        }

        vxAssert(!pFrame->acquireSignalSemaphore); {
            vxExpectSuccessOrReturn(
                vkCreateSemaphore(
                    pContext->device,
                    &semaphoreCreateInfo,
                    pContext->pAllocator,
                    &pFrame->acquireSignalSemaphore
                ),{}
            );
        }

        vxAssert(!pFrame->submitSignalSemaphore); {
            vxExpectSuccessOrReturn(
                vkCreateSemaphore(
                    pContext->device,
                    &semaphoreCreateInfo,
                    pContext->pAllocator,
                    &pFrame->submitSignalSemaphore
                ),{}
            );
        }

        vxAssert(!pFrame->commandBuffer); {
            pFrame->commandBuffer = commandBuffers[i];
        }
    }

    return VK_SUCCESS;
}

void
vxDestroyCanvasFrames(const VxContext* pContext, VxCanvas* pCanvas) {
    VkCommandBuffer commandBuffers[VX_MAX_CANVAS_FRAME_COUNT];

    for (uint32_t i = 0; i < pCanvas->frameCount; ++i) {
        VxCanvasFrame* pFrame = &pCanvas->frames[i];

        vxAssert(pFrame->swapchainImage); {
            pFrame->swapchainImage = VK_NULL_HANDLE;
        }

        vxAssert(pFrame->swapchainImageView); {
            vkDestroyImageView(
                pContext->device,
                pFrame->swapchainImageView,
                pContext->pAllocator
            );
            pFrame->swapchainImageView = VK_NULL_HANDLE;
        }

        vxAssert(pFrame->framebuffer); {
            vkDestroyFramebuffer(
                pContext->device,
                pFrame->framebuffer,
                pContext->pAllocator
            );
            pFrame->framebuffer = VK_NULL_HANDLE;
        }

        vxAssert(pFrame->attachmentCount == 1); {
            pFrame->attachmentCount = 0;
        }

        vxAssert(pFrame->acquireWaitFence); {
            vkDestroyFence(
                pContext->device,
                pFrame->acquireWaitFence,
                pContext->pAllocator
            );
            pFrame->acquireWaitFence = VK_NULL_HANDLE;
        }

        vxAssert(pFrame->acquireSignalSemaphore); {
            vkDestroySemaphore(
                pContext->device,
                pFrame->acquireSignalSemaphore,
                pContext->pAllocator
            );
            pFrame->acquireSignalSemaphore = VK_NULL_HANDLE;
        }

        vxAssert(pFrame->submitSignalSemaphore); {
            vkDestroySemaphore(
                pContext->device,
                pFrame->submitSignalSemaphore,
                pContext->pAllocator
            );
            pFrame->submitSignalSemaphore = VK_NULL_HANDLE;
        }

        vxAssert(pFrame->commandBuffer); {
            commandBuffers[i] = pFrame->commandBuffer;
            pFrame->commandBuffer = VK_NULL_HANDLE;
        }
    }

    vkFreeCommandBuffers(
        pContext->device,
        pContext->commandPool,
        pCanvas->frameCount, 
        commandBuffers
    );

    pCanvas->frameCount = 0;
}

void
vxDestroyCanvas(const VxContext* pContext, VxCanvas* pCanvas) {
    vxAssertSuccess(vkDeviceWaitIdle(pContext->device));

    vxDestroyCanvasFrames(pContext, pCanvas);

    if (pCanvas->swapchain) {
        vkDestroySwapchainKHR(
            pContext->device,
            pCanvas->swapchain,
            pContext->pAllocator
        );
        pCanvas->swapchain = VK_NULL_HANDLE;
    }

    if (pCanvas->surface) {
        vkDestroySurfaceKHR(
            pContext->instance,
            pCanvas->surface,
            pContext->pAllocator
        );
        pCanvas->surface = VK_NULL_HANDLE;
    }

    *pCanvas = (VxCanvas)vxInit;
}

VkResult
vxResizeCanvas(const VxContext* pContext, VxCanvas* pCanvas) {
    vxAssert(pCanvas->surface);
    vxAssert(pCanvas->surfaceFormat.format);

    VkSurfaceCapabilitiesKHR capabilities;
    vxExpectSuccessOrReturn(
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
            pContext->physicalDevice,
            pCanvas->surface,
            &capabilities
        ),{}
    );

    if (0 == capabilities.currentExtent.width ||
        0 == capabilities.currentExtent.height)
        return VK_SUCCESS;

    if (pCanvas->extent.width  == capabilities.currentExtent.width &&
        pCanvas->extent.height == capabilities.currentExtent.height)
        return VK_SUCCESS;

    if (!vxExpect(capabilities.minImageCount <= VX_MAX_CANVAS_FRAME_COUNT))
        return VK_ERROR_INITIALIZATION_FAILED;

    if (!vxExpect(capabilities.maxImageCount >= VX_MIN_CANVAS_FRAME_COUNT))
        return VK_ERROR_INITIALIZATION_FAILED;

    VkSwapchainCreateInfoKHR swapchainCreateInfo = {
        VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
    };
    swapchainCreateInfo.surface = pCanvas->surface;
    swapchainCreateInfo.minImageCount = pCanvas->swapchainImageCount;
    swapchainCreateInfo.imageFormat = pCanvas->surfaceFormat.format;
    swapchainCreateInfo.imageColorSpace = pCanvas->surfaceFormat.colorSpace;
    swapchainCreateInfo.imageExtent = capabilities.currentExtent;
    swapchainCreateInfo.imageArrayLayers = 1;
    swapchainCreateInfo.imageUsage
        = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT
        | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    swapchainCreateInfo.queueFamilyIndexCount = 1;
    swapchainCreateInfo.pQueueFamilyIndices
        = &pContext->graphicsQueueFamilyIndex;
    swapchainCreateInfo.preTransform = capabilities.currentTransform;
    swapchainCreateInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    swapchainCreateInfo.presentMode = pCanvas->presentMode;
    swapchainCreateInfo.clipped = VK_TRUE;
    swapchainCreateInfo.oldSwapchain = pCanvas->swapchain;

    vxExpectSuccessOrReturn(
        vkCreateSwapchainKHR(
            pContext->device,
            &swapchainCreateInfo,
            pContext->pAllocator,
            &pCanvas->swapchain
        ),{}
    );

    // destroy old swapchain & frames
    if (swapchainCreateInfo.oldSwapchain) {
        // optimization: queue these resources for future destruction
        vxAssertSuccess(vkDeviceWaitIdle(pContext->device));
        vxDestroyCanvasFrames(pContext, pCanvas);
        vkDestroySwapchainKHR(
            pContext->device,
            swapchainCreateInfo.oldSwapchain,
            pContext->pAllocator
        );
    }

    // create new frames
    pCanvas->extent = capabilities.currentExtent;
    vxExpectSuccessOrReturn(
        vxCreateCanvasFrames(pContext, pCanvas),{}
    );

    vxInfof(
        "vxResizeCanvas: {%u, %u}\n",
        pCanvas->extent.width,
        pCanvas->extent.height
    );

    pCanvas->swapchainImageIndex = ~(uint32_t)0;

    return VK_SUCCESS;
}

VkResult
vxAcquireNextFrame(
    const VxContext* pContext,
    VxCanvas*        pCanvas,
    VxCanvasFrame**  ppFrame
) {
    if (ppFrame) *ppFrame = nullptr;

    vxExpectSuccessOrReturn(vxResizeCanvas(pContext, pCanvas),{});

    const uint32_t nextFrameIndex
        = (pCanvas->swapchainImageIndex + 1)
        % (pCanvas->swapchainImageCount);

    VxCanvasFrame* pNextFrame = &pCanvas->frames[nextFrameIndex];

    const VkBool32 waitAll = VK_TRUE;

    const uint64_t timeout = ~(uint64_t)0u;

    vxExpectSuccessOrReturn(
        vkWaitForFences(
            pContext->device,
            1, &pNextFrame->acquireWaitFence,
            waitAll,
            timeout
        ),{}
    );

    vxExpectSuccessOrReturn(
        vkResetFences(
            pContext->device,
            1, &pNextFrame->acquireWaitFence
        ),{}
    );

    vxExpectSuccessOrReturn(
        vkAcquireNextImageKHR(
            pContext->device,
            pCanvas->swapchain,
            timeout,
            pNextFrame->acquireSignalSemaphore,
            VK_NULL_HANDLE,
            &pCanvas->swapchainImageIndex
        ),{}
    );

    vxAssert(nextFrameIndex == pCanvas->swapchainImageIndex);

    if (ppFrame) *ppFrame = pNextFrame;

    return VK_SUCCESS;
}

VxCanvasFrame*
vxBeginFrame(
    const VxContext* pContext,
    VxCanvas*        pCanvas
) {
    VxCanvasFrame* pFrame = nullptr;

    vxAssertSuccess(
        vxAcquireNextFrame(
            pContext,
            pCanvas,
            &pFrame
        )
    );

    const VkCommandBufferResetFlags commandBufferResetFlags = 0;

    vxAssertSuccess(
        vkResetCommandBuffer(
            pFrame->commandBuffer,
            commandBufferResetFlags
        )
    );

    VkCommandBufferBeginInfo commandBufferBeginInfo = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
    };

    vxAssertSuccess(
        vkBeginCommandBuffer(
            pFrame->commandBuffer,
            &commandBufferBeginInfo
        )
    );

    return pFrame;
}

VkCommandBuffer
vxCmdBeginFrameRenderPass(
    const VxCanvas*      pCanvas,
    const VxCanvasFrame* pFrame,
    uint32_t             clearValueCount,
    const VkClearValue*  pClearValues
) {
    VkRenderPassBeginInfo renderPassInfo = {
        VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
    };
    renderPassInfo.renderPass        = pCanvas->renderPass;
    renderPassInfo.framebuffer       = pFrame->framebuffer;
    renderPassInfo.renderArea.extent = pCanvas->extent;
    renderPassInfo.clearValueCount   = clearValueCount;
    renderPassInfo.pClearValues      = pClearValues;

    vkCmdBeginRenderPass(
        pFrame->commandBuffer,
        &renderPassInfo,
        VK_SUBPASS_CONTENTS_INLINE
    );

    return pFrame->commandBuffer;
}

VkResult
vxSubmitFrame(
    const VxContext* pContext,
    VxCanvas*        pCanvas,
    VxCanvasFrame*   pFrame
) {
    vxAssert(pFrame->frameIndex == pCanvas->swapchainImageIndex);
    vxAssert(pFrame == &pCanvas->frames[pFrame->frameIndex]);

    vxExpectSuccessOrReturn(vkEndCommandBuffer(pFrame->commandBuffer),{});

    VkPipelineStageFlags waitDstStageMask = VK_PIPELINE_STAGE_TRANSFER_BIT;

    const uint32_t submitCount = 1;
    VkSubmitInfo submitInfo = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submitInfo.waitSemaphoreCount   = 1;
    submitInfo.pWaitSemaphores      = &pFrame->submitWaitSemaphore;
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores    = &pFrame->submitSignalSemaphore;
    submitInfo.pWaitDstStageMask    = &waitDstStageMask;
    submitInfo.commandBufferCount   = 1;
    submitInfo.pCommandBuffers      = &pFrame->commandBuffer;

    vxExpectSuccessOrReturn(
        vkQueueSubmit(
            pContext->graphicsQueue,
            submitCount,
            &submitInfo,
            pFrame->submitSignalFence
        ),{}
    );

    return VK_SUCCESS;
}

VkResult
vxPresentFrame(
    const VxContext* pContext,
    VxCanvas*        pCanvas,
    VxCanvasFrame*   pFrame
) {
    vxAssert(pFrame->frameIndex == pCanvas->swapchainImageIndex);
    vxAssert(pFrame == &pCanvas->frames[pFrame->frameIndex]);

    VkPresentInfoKHR presentInfo = {
        VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
    };
    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores    = &pFrame->presentWaitSemaphore;
    presentInfo.swapchainCount     = 1;
    presentInfo.pSwapchains        = &pCanvas->swapchain;
    presentInfo.pImageIndices      = &pFrame->frameIndex;

    vxExpectSuccessOrReturn(
        vkQueuePresentKHR(
            pContext->graphicsQueue,
            &presentInfo
        ),{}
    );

    return VK_SUCCESS;
}

//------------------------------------------------------------------------------

static inline bool vxHasAllBits(uint64_t expected, uint64_t actual) {
    return (expected & actual) == (expected);
}

static inline bool vxHasAnyBits(uint64_t expected, uint64_t actual) {
    return (expected & actual) != 0;
}

VkResult
vxAllocateMemory(
    const VxContext* pContext,
    const VkMemoryRequirements* pMemoryRequirements,
    const VkMemoryPropertyFlags memoryPropertyFlags,
    VkDeviceMemory* pDeviceMemory
) {
    VkResult result = VK_ERROR_UNKNOWN;
    const VkPhysicalDeviceMemoryProperties* pMemoryProperties
        = &pContext->physicalDeviceMemoryProperties;

    VkMemoryAllocateInfo allocateInfo = {
        VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
    };
    allocateInfo.allocationSize = pMemoryRequirements->size;

    for (uint32_t i = 0; i < pMemoryProperties->memoryTypeCount; ++i) {
        if (!vxHasAnyBits(pMemoryRequirements->memoryTypeBits, 1 << i)) {
            // vxWarningf("memoryType[%i] does not match memoryTypeBits\n", i);
            continue;
        }

        const VkMemoryPropertyFlags propertyFlags
            = pMemoryProperties->memoryTypes[i].propertyFlags;

        if (!vxHasAllBits(memoryPropertyFlags, propertyFlags)) {
            // vxWarningf("memoryType[%i] does not match memoryPropertyFlags\n", i);
            continue;
        }

        allocateInfo.memoryTypeIndex = i;
        result = vxExpectSuccess(
            vkAllocateMemory(
                pContext->device,
                &allocateInfo,
                pContext->pAllocator,
                pDeviceMemory
            )
        );
        if (result == VK_SUCCESS) {
            return VK_SUCCESS;
        }
    }
    return result;
}

VkResult
vxAllocateBufferMemory(
    const VxContext* pContext,
    const VkBuffer buffer,
    const VkMemoryPropertyFlags memoryPropertyFlags,
    VkDeviceMemory* pDeviceMemory
) {
    VkMemoryRequirements memoryRequirements;
    vkGetBufferMemoryRequirements(
        pContext->device, buffer,
        &memoryRequirements
    );
    return vxAllocateMemory(
        pContext,
        &memoryRequirements,
        memoryPropertyFlags,
        pDeviceMemory
    );
}

VkResult
vxAllocateImageMemory(
    const VxContext* pContext,
    const VkImage image,
    const VkMemoryPropertyFlags memoryPropertyFlags,
    VkDeviceMemory* pDeviceMemory
) {
    VkMemoryRequirements memoryRequirements;
    vkGetImageMemoryRequirements(
        pContext->device, image,
        &memoryRequirements
    );
    return vxAllocateMemory(
        pContext,
        &memoryRequirements,
        memoryPropertyFlags,
        pDeviceMemory
    );
}

//------------------------------------------------------------------------------

VkResult
vxCreateBufferAllocation(
    const VxContext*              pContext,
    const VxBufferAllocationInfo* pAllocationInfo,
    VxBufferAllocation*           pAllocation
) {
    *pAllocation = (VxBufferAllocation)vxInit;

    vxExpectSuccessOrReturn(
        vkCreateBuffer(
            pContext->device,
            &pAllocationInfo->buffer,
            pContext->pAllocator,
            &pAllocation->buffer
        ),{
            vxDestroyBufferAllocation(pContext, pAllocation);
        }
    );

    vxExpectSuccessOrReturn(
        vxAllocateBufferMemory(
            pContext,
            pAllocation->buffer,
            pAllocationInfo->memory,
            &pAllocation->memory
        ),{
            vxDestroyBufferAllocation(pContext, pAllocation);
        }
    );

    const VkDeviceSize memoryOffset = 0;

    vxExpectSuccessOrReturn(
        vkBindBufferMemory(
            pContext->device,
            pAllocation->buffer,
            pAllocation->memory,
            memoryOffset
        ),{
            vxDestroyBufferAllocation(pContext, pAllocation);
        }
    );

    pAllocation->size = pAllocationInfo->buffer.size;

    return VK_SUCCESS;
}

void
vxDestroyBufferAllocation(
    const VxContext* pContext,
    VxBufferAllocation* pAllocation
) {
    if (pAllocation->buffer) {
        vkDestroyBuffer(
            pContext->device,
            pAllocation->buffer,
            pContext->pAllocator
        );
        pAllocation->buffer = VK_NULL_HANDLE;
    }
    if (pAllocation->memory) {
        vkFreeMemory(
            pContext->device,
            pAllocation->memory,
            pContext->pAllocator
        );
        pAllocation->memory = VK_NULL_HANDLE;
    }
    *pAllocation = (VxBufferAllocation)vxInit;
}

VkResult
vxCopyToBufferAllocation(
    const VxContext*          pContext,
    const VxBufferAllocation* dstAllocation,
    VkDeviceSize              dstOffset,
    VkDeviceSize              size,
    const void*               srcData
) {
    const VkMemoryMapFlags flags = 0;

    void* dstData = nullptr;

    vxExpectSuccessOrReturn(
        vkMapMemory(
            pContext->device,
            dstAllocation->memory,
            dstOffset, size, flags,
            &dstData
        ),{}
    );

    memcpy(dstData, srcData, (size_t)size);

    vkUnmapMemory(pContext->device, dstAllocation->memory);

    return VK_SUCCESS;
}

//------------------------------------------------------------------------------

VkResult
vxCreateImageAllocation(
    const VxContext*             pContext,
    const VxImageAllocationInfo* pAllocationInfo,
    VxImageAllocation*           pAllocation
) {
    *pAllocation = (VxImageAllocation)vxInit;

    vxExpectSuccessOrReturn(
        vkCreateImage(
            pContext->device,
            &pAllocationInfo->image,
            pContext->pAllocator,
            &pAllocation->image
        ),{
            vxDestroyImageAllocation(pContext, pAllocation);
        }
    );

    vxExpectSuccessOrReturn(
        vxAllocateImageMemory(
            pContext,
            pAllocation->image,
            pAllocationInfo->memory,
            &pAllocation->memory
        ),{
            vxDestroyImageAllocation(pContext, pAllocation);
        }
    );

    const VkDeviceSize memoryOffset = 0;

    vxExpectSuccessOrReturn(
        vkBindImageMemory(
            pContext->device,
            pAllocation->image,
            pAllocation->memory,
            memoryOffset
        ),{
            vxDestroyImageAllocation(pContext, pAllocation);
        }
    );

    VkImageSubresourceRange subresourceRange = vxInit;
    subresourceRange.aspectMask = pAllocationInfo->imageAspectMask;
    subresourceRange.baseMipLevel = 0;
    subresourceRange.levelCount = pAllocationInfo->image.mipLevels;
    subresourceRange.baseArrayLayer = 0;
    subresourceRange.layerCount = pAllocationInfo->image.arrayLayers;

    VkImageViewCreateInfo imageViewCreateInfo = {
        VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
    };
    imageViewCreateInfo.image = pAllocation->image;
    imageViewCreateInfo.viewType = pAllocationInfo->imageViewType;
    imageViewCreateInfo.format = pAllocationInfo->image.format;
    imageViewCreateInfo.subresourceRange = subresourceRange;

    vxExpectSuccessOrReturn(
        vkCreateImageView(
            pContext->device,
            &imageViewCreateInfo,
            pContext->pAllocator,
            &pAllocation->imageView
        ),{
            vxDestroyImageAllocation(pContext, pAllocation);
        }
    );

    pAllocation->imageType   = pAllocationInfo->image.imageType;
    pAllocation->format      = pAllocationInfo->image.format;
    pAllocation->extent      = pAllocationInfo->image.extent;
    pAllocation->mipLevels   = pAllocationInfo->image.mipLevels;
    pAllocation->arrayLayers = pAllocationInfo->image.arrayLayers;

    return VK_SUCCESS;
}

void
vxDestroyImageAllocation(
    const VxContext*   pContext,
    VxImageAllocation* pAllocation
) {
    if (pAllocation->imageView) {
        vkDestroyImageView(
            pContext->device,
            pAllocation->imageView,
            pContext->pAllocator
        );
    }
    if (pAllocation->image) {
        vkDestroyImage(
            pContext->device,
            pAllocation->image,
            pContext->pAllocator
        );
        pAllocation->image = VK_NULL_HANDLE;
    }
    if (pAllocation->memory) {
        vkFreeMemory(
            pContext->device,
            pAllocation->memory,
            pContext->pAllocator
        );
        pAllocation->memory = VK_NULL_HANDLE;
    }
    *pAllocation = (VxImageAllocation)vxInit;
}

//------------------------------------------------------------------------------

VkResult
vxCreateShaderModule(
    const VxContext* pContext,
    const size_t     codeSize,
    const uint32_t*  pCode,
    VkShaderModule*  pShaderModule
) {
    VkShaderModuleCreateInfo shaderModuleCreateInfo = {
        VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
    };
    shaderModuleCreateInfo.codeSize = codeSize;
    shaderModuleCreateInfo.pCode    = pCode;
    return vkCreateShaderModule(
        pContext->device,
        &shaderModuleCreateInfo,
        pContext->pAllocator,
        pShaderModule
    );
}

//------------------------------------------------------------------------------

#ifdef __cplusplus
} // extern "C"
#endif
/* clang-format on */
