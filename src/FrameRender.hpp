#pragma once

//

class IFrameRender {
public:
  virtual ~IFrameRender() = default;
};

/// @brief
class FrameRender final : public IFrameRender {};