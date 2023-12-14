#include <pybind11/pybind11.h>
#include <opencv2/opencv.hpp>

namespace py = pybind11;

void process_video(cv::VideoCapture& cap) {
    // Perform operations on the video capture frames
}

PYBIND11_MODULE(example, m) {
    // First try
    //
    // Python method expects a cv::VideoCapture
    // Upon receiving a cv2.VideoCapture, it gives the following error:
    //
    // TypeError: process_video(): incompatible function arguments. The following argument types are supported:
    // 1. (arg0: cv::VideoCapture) -> None
    //
    // Invoked with: < cv2.VideoCapture 0x7ff14164fc90>
    //m.def("process_video", &process_video);

    // Second try
    //
    // Python method expects a py::object, it receives a cv2.VideoCapture
    // We need to convert it to a C++ cv::VideoCapture
    m.def("process_video", [](py::object cap_python) {
                cv::VideoCapture cap_cpp = reinterpret_cast<cv::VideoCapture&>(cap_python); // segfault!
                return process_video(cap_cpp);
    });
}
