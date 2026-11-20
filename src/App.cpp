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
  if (!frameSource_ || !segmenter_ || !render_) {
    return EXIT_FAILURE;
  }
  cv::Mat frame{};
  if (frameSource_->getFrame(frame)) {
    segmenter_->segment(frame);

    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}
