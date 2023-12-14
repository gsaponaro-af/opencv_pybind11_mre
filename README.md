This repository contains a minimum reproducible example of [this StackOverflow question](https://stackoverflow.com/questions/77661986).

Instructions on Ubuntu:

1. Create Conda environment: `conda env create --name opencv_pybind11_mre --file=environment.yml`
2. Activate Conda environment: `conda activate opencv_pybind11_mre`
3. Create and enter build directory: `mkdir build && cd build`
4. Run CMake configuration step: `cmake ..`
5. Build: `make`
6. Make Python module library available: `export PYTHONPATH=$PYTHONPATH:$(pwd)`
7. Go to the location of the Python usage script: `python example_python_usage.py`
