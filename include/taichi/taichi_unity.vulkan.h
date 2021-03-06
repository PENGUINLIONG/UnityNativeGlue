#pragma once
#include <map>
#include <memory>
#include <queue>
#include "taichi/taichi_unity.h"
#define VK_NO_PROTOTYPES
#include "Unity/IUnityGraphicsVulkan.h"

static_assert(SUPPORT_VULKAN);

struct PluginInstanceVulkan : public PluginInstance {
  IUnityGraphicsVulkan* unity_vulkan;
  std::queue<TiRuntime> submit_args;

  PluginInstanceVulkan(IUnityGraphicsVulkan* unity_vulkan);
  virtual ~PluginInstanceVulkan() override final;

  virtual TiRuntime import_native_runtime() const override final;
  virtual TiMemory import_native_memory(TiRuntime runtime, void* native_buffer_ptr) const override final;
};
