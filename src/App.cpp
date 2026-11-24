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
    auto mask = estimator_->estimate(frame);
    render_->render(frame, mask);
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}
