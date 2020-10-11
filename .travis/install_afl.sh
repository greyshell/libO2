wget https://lcamtuf.coredump.cx/afl/releases/afl-latest.tgz && tar xvf afl-latest.tgz
cd afl*/ && make && sudo make install
echo "core" | sudo tee /proc/sys/kernel/core_pattern