#pragma once

//

#include <memory>

//

#include "FrameRender.hpp"
#include "FrameSegmenter.hpp"
#include "FrameSource.hpp"

//

/// @brief
class App final {
public:
  explicit App(std::unique_ptr<IFrameSource> frameSource,
               std::unique_ptr<IFrameSegmenter> segmenter,
               std::unique_ptr<IFrameRender> render)
      : frameSource_(std::move(frameSource)),
        segmenter_(std::move(segmenter)),
        render_(std::move(render)) {}
  ~App() = default;

  App(const App &) = delete;
  App &operator=(const App &) = delete;

  int exec();

private:
  std::unique_ptr<IFrameSource> frameSource_;
  std::unique_ptr<IFrameSegmenter> segmenter_;
  std::unique_ptr<IFrameRender> render_;
};
