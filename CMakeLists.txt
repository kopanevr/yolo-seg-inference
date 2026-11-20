cmake_minimum_required(VERSION 3.10)
project(DepthEstimation_App VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(
  GLOB_RECURSE
  SRC_FILES
  ${CMAKE_SOURCE_DIR}/src/*.cpp
)

file(
  GLOB
  ROOT_FILES
  ${CMAKE_SOURCE_DIR}/*.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${ROOT_FILES})

set(ONNXRUNTIME_ROOT "${CMAKE_SOURCE_DIR}/thirdParty/onnxruntime-linux-x64-1.30.0")

target_include_directories(
  ${PROJECT_NAME} PRIVATE
  "${CMAKE_SOURCE_DIR}"
  "${CMAKE_SOURCE_DIR}/src"
  "${CMAKE_SOURCE_DIR}/src/Logger/include"

  "${ONNXRUNTIME_ROOT}/include"
)

target_link_directories(${PROJECT_NAME} PRIVATE "${ONNXRUNTIME_ROOT}/lib")

target_link_libraries(${PROJECT_NAME} PRIVATE onnxruntime)
