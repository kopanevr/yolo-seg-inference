#pragma once

//

#include <memory>

//

#include "FrameSource.hpp"
#include "FrameSegmenter.hpp"

//

/// @brief
class App final {
public:
  explicit App(std::unique_ptr<IFrameSource> frameSource,
               std::unique_ptr<IFrameSegmenter> segmenter)
      : frameSource_(std::move(frameSource)),
        segmenter_(std::move(segmenter)) {}
  ~App() = default;

  App(const App &) = delete;
  App &operator=(const App &) = delete;

  int exec();

private:
  std::unique_ptr<IFrameSource> frameSource_;
  std::unique_ptr<IFrameSegmenter> segmenter_;
};
