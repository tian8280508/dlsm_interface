## Guide
Two repos are required: dlsm and this one.

# how to use this
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && make dlsm_interface
./dlsm_interface

# connection.conf 中第一行的值无所谓，主要是有几个，但第二行需要是真实ip