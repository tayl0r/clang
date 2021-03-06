// RUN: touch %t.o
//
// RUN: %clang -target x86_64-unknown-linux -### %t.o -flto 2>&1 \
// RUN:     -Wl,-plugin-opt=foo -O3 \
// RUN:     | FileCheck %s --check-prefix=CHECK-X86-64-BASIC
// CHECK-X86-64-BASIC: "-plugin" "{{.*}}{{[/\\]}}LLVMgold.{{dll|dylib|so}}"
// CHECK-X86-64-BASIC: "-plugin-opt=O3"
// CHECK-X86-64-BASIC: "-plugin-opt=foo"
//
// RUN: %clang -target x86_64-unknown-linux -### %t.o -flto 2>&1 \
// RUN:     -march=corei7 -Wl,-plugin-opt=foo -Ofast \
// RUN:     | FileCheck %s --check-prefix=CHECK-X86-64-COREI7
// CHECK-X86-64-COREI7: "-plugin" "{{.*}}{{[/\\]}}LLVMgold.{{dll|dylib|so}}"
// CHECK-X86-64-COREI7: "-plugin-opt=mcpu=corei7"
// CHECK-X86-64-COREI7: "-plugin-opt=O3"
// CHECK-X86-64-COREI7: "-plugin-opt=foo"
//
// RUN: %clang -target arm-unknown-linux -### %t.o -flto 2>&1 \
// RUN:     -march=armv7a -Wl,-plugin-opt=foo -O0 \
// RUN:     | FileCheck %s --check-prefix=CHECK-ARM-V7A
// CHECK-ARM-V7A: "-plugin" "{{.*}}{{[/\\]}}LLVMgold.{{dll|dylib|so}}"
// CHECK-ARM-V7A: "-plugin-opt=mcpu=generic"
// CHECK-ARM-V7A: "-plugin-opt=O0"
// CHECK-ARM-V7A: "-plugin-opt=foo"
//
// RUN: %clang -target i686-linux-android -### %t.o -flto 2>&1 \
// RUN:     | FileCheck %s --check-prefix=CHECK-X86-ANDROID
// CHECK-X86-ANDROID: "-plugin" "{{.*}}{{[/\\]}}LLVMgold.{{dll|dylib|so}}"
//
// RUN: %clang -target riscv64-unknown-elf -### %t.o -flto 2>&1 \
// RUN:     -march=rv64imf -mabi=lp64f \
// RUN:     | FileCheck %s --check-prefix=CHECK-RISCV-BAREMETAL
// CHECK-RISCV-BAREMETAL: "-plugin" "{{.*}}{{[/\\]}}LLVMgold.{{dll|dylib|so}}"
// CHECK-RISCV-BAREMETAL: "-plugin-opt=-mattr=+m"
// CHECK-RISCV-BAREMETAL: "-plugin-opt=-mattr=+f"
// CHECK-RISCV-BAREMETAL: "-plugin-opt=-mattr=+relax"
// CHECK-RISCV-BAREMETAL: "-plugin-opt=-target-abi=lp64f"
//
// RUN: %clang -target riscv64-unknown-linux-gnu -### %t.o -flto 2>&1 \
// RUN:     -march=rv64imf -mabi=lp64f \
// RUN:     | FileCheck %s --check-prefix=CHECK-RISCV-LINUX
// CHECK-RISCV-LINUX: "-plugin" "{{.*}}{{[/\\]}}LLVMgold.{{dll|dylib|so}}"
// CHECK-RISCV-LINUX: "-plugin-opt=-mattr=+m"
// CHECK-RISCV-LINUX: "-plugin-opt=-mattr=+f"
// CHECK-RISCV-LINUX: "-plugin-opt=-mattr=+relax"
// CHECK-RISCV-LINUX: "-plugin-opt=-target-abi=lp64f"
