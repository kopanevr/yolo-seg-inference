#include "App.hpp"

//

#include <stdlib.h>

//

#include "Logger.hpp"

//

#include "opencv4/opencv2/opencv.hpp"

//

/// @brief
int App::exec() {
  if (!frameSource_ || !estimator_ || !render_) {
    return EXIT_FAILURE;
  }
  cv::Mat frame{};
  if (frameSource_->getFrame(frame)) {
    auto depth = estimator_->estimate(frame);
    render_->drawDepth(frame, depth);
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}
