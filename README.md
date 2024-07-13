## Guide
Two repos are required: dlsm and this one.

# how to use this
mkdir build
cd build
cmake -DWITH_GFLAGS=1 -DCMAKE_BUILD_TYPE=Release .. && make dlsm_interface
./dlsm_interface