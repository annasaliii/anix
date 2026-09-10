# anix - short for annas unix

# How to run
## Prerequisites: qemu, clang, llvm(lld)

first:
    make TOOLCHAIN={compiler you are using}

    for example:
        make TOOLCHAIN=x86_64-elf
    
second:
    source ./create-image.sh

lastly:
    qemu-system-x86_64 -cdrom image.iso -serial mon:stdio