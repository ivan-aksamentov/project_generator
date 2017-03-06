#Generated by VisualGDB (http://visualgdb.com)
#DO NOT EDIT THIS FILE MANUALLY UNLESS YOU ABSOLUTELY NEED TO
#USE VISUALGDB PROJECT PROPERTIES DIALOG INSTEAD

BINARYDIR := Release

#Toolchain
CC := gcc
CXX := g++
LD := $(CXX)
AR := ar
OBJCOPY := objcopy

#Additional flags
PREPROCESSOR_MACROS := NDEBUG=1 _ISOC99_SOURCE _POSIX_C_SOURCE=200809L "UNUSED(x)=(void)(x)"
INCLUDE_DIRS := 
LIBRARY_DIRS := 
LIBRARY_NAMES := pthread
ADDITIONAL_LINKER_INPUTS := 
MACOS_FRAMEWORKS := 
LINUX_PACKAGES := 

CFLAGS := -std=c99 -pedantic -O3 -fdata-sections -ffunction-sections -fno-math-errno -fno-strict-aliasing -ftrapv -fvisibility=hidden -pipe -Waggregate-return -Wall -Warray-bounds -Wcast-align -Wcast-qual -Wconversion -Wdeprecated-declarations -Wempty-body -Werror-implicit-function-declaration -Werror=int-conversion -Wextra -Wfloat-equal -Wformat-extra-args -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wformat-zero-length -Wformat=2 -Wignored-qualifiers -Winit-self -Wmaybe-uninitialized -Wno-format-nonliteral -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-compare -Wstrict-overflow=5 -Wstrict-prototypes -Wswitch-default -Wswitch-enum -Wtype-limits -Wundef -Wunreachable-code -Wwrite-strings 
CXXFLAGS := -ggdb -ffunction-sections -O3
ASFLAGS := 
LDFLAGS := -Wl,-gc-sections
COMMONFLAGS := 
LINKER_SCRIPT := 

START_GROUP := -Wl,--start-group
END_GROUP := -Wl,--end-group

#Additional options detected from testing the toolchain
IS_LINUX_PROJECT := 1
