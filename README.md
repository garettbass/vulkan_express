# Vulkan Express

Vulkan Express is intended to simplify some of the common and tedious code required to get started with the Vulkan API.  Vulkan Express can be included as a header-only library, or compiled as a separate source file.  Though the implementation is C (possibly requiring some C11 features), the library should compile cleanly as either C or C++ (possibly requiring some C++11 features).

Vulkan Express provides types (prefixed Vx), and functions (prefixed vx), following a declaration style similar to Vulkan.  The main simplifications currently implemented are:

* VxContext - combines a Vulkan allocator, instance, device, physical device, list of supported surface formats, a compute queue, a graphics queue, and a command pool

* VxCanvas - combines a Vulkan surface and swapchain with a configurable number of per-frame resources, including:
  * Vulkan command buffer, framebuffer, attachment images and image views, and fences and semaphores required to synchronize calls to acquire, submit, and present a frame

All of the Vulkan resources managed by Vulkan Express are directly exposed to the calling code.  Vulkan Express only attempts to automate common groups of Vulkan API calls in order to support simple use cases.  It is always possible to fall back on Vulkan API calls wherever Vulkan Express API calls do not support your use case.