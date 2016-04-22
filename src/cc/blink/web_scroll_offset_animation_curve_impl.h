// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_BLINK_WEB_SCROLL_OFFSET_ANIMATION_CURVE_IMPL_H_
#define CC_BLINK_WEB_SCROLL_OFFSET_ANIMATION_CURVE_IMPL_H_

#include "base/macros.h"
#include "base/memory/scoped_ptr.h"
#include "cc/blink/cc_blink_export.h"
#include "third_party/WebKit/public/platform/WebScrollOffsetAnimationCurve.h"

namespace cc {
class AnimationCurve;
class ScrollOffsetAnimationCurve;
}

namespace cc_blink {

class WebScrollOffsetAnimationCurveImpl
    : public blink::WebScrollOffsetAnimationCurve {
 public:
  CC_BLINK_EXPORT WebScrollOffsetAnimationCurveImpl(
      blink::WebFloatPoint target_value,
      TimingFunctionType timing_function,
      ScrollDurationBehavior duration_behavior);
  ~WebScrollOffsetAnimationCurveImpl() override;

  // blink::WebCompositorAnimationCurve implementation.
  AnimationCurveType type() const override;

  // blink::WebScrollOffsetAnimationCurve implementation.
  void setInitialValue(blink::WebFloatPoint initial_value) override;
  blink::WebFloatPoint getValue(double time) const override;
  double duration() const override;

  blink::WebFloatPoint targetValue() const override;
  void updateTarget(double time, blink::WebFloatPoint new_target) override;

  scoped_ptr<cc::AnimationCurve> CloneToAnimationCurve() const;

 private:
  scoped_ptr<cc::ScrollOffsetAnimationCurve> curve_;

  DISALLOW_COPY_AND_ASSIGN(WebScrollOffsetAnimationCurveImpl);
};

}  // namespace cc_blink

#endif  // CC_BLINK_WEB_SCROLL_OFFSET_ANIMATION_CURVE_IMPL_H_
