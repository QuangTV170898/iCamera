# openssl
```
1. download from https://ftp.openssl.org/source/old/1.0.0/openssl-1.0.0f.tar.gz
2. start build
./Configure no-asm no-async no-egd shared --prefix=${PWD}/_build_mips --cross-compile-prefix=mips-linux-uclibc- linux-generic32
make clean
make -j2
```
