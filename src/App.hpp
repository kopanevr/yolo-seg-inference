#pragma once

//

#include <memory>

//

#include "FrameRender.hpp"
#include "FrameDepthEstimator.hpp"
#include "FrameSource.hpp"

//

/// @brief
class App final {
public:
  App(std::unique_ptr<IFrameSource> frameSource,
      std::unique_ptr<IFrameDepthEstimator> estimator,
      std::unique_ptr<IFrameRender> render)
      : frameSource_(std::move(frameSource)),
        estimator_(std::move(estimator)),
        render_(std::move(render)) {}
  ~App() = default;

  App(const App &) = delete;
  App &operator=(const App &) = delete;

  int exec();

private:
  std::unique_ptr<IFrameSource> frameSource_;
  std::unique_ptr<IFrameDepthEstimator> estimator_;
  std::unique_ptr<IFrameRender> render_;
};
