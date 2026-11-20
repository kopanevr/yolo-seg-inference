#pragma once

//

#include <memory>

//

#include "ImageSegmenter.hpp"

//

/// @brief
class App final {
public:
  explicit App(std::unique_ptr<IImageSegmenter> segmenter)
      : segmenter_(std::move(segmenter)) {}
  ~App() = default;

  App(const App &) = delete;
  App &operator=(const App &) = delete;

  int exec();

private:
  std::unique_ptr<IImageSegmenter> segmenter_;
};
