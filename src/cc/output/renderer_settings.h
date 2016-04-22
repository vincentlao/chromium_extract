// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_OUTPUT_RENDERER_SETTINGS_H_
#define CC_OUTPUT_RENDERER_SETTINGS_H_

#include <stddef.h>

#include "cc/base/cc_export.h"

namespace cc {

namespace proto {
class RendererSettings;
}  // namespace proto

class CC_EXPORT RendererSettings {
 public:
  RendererSettings();
  ~RendererSettings();

  bool allow_antialiasing;
  bool force_antialiasing;
  bool force_blending_with_shaders;
  bool partial_swap_enabled;
  bool finish_rendering_on_resize;
  bool should_clear_root_render_pass;
  bool disable_display_vsync;
  bool release_overlay_resources_on_swap_complete;
  double refresh_rate;
  int highp_threshold_min;
  bool use_rgba_4444_textures;
  size_t texture_id_allocation_chunk_size;
  bool use_gpu_memory_buffer_resources;

  void ToProtobuf(proto::RendererSettings* proto) const;
  void FromProtobuf(const proto::RendererSettings& proto);

  bool operator==(const RendererSettings& other) const;
};

}  // namespace cc

#endif  // CC_OUTPUT_RENDERER_SETTINGS_H_
