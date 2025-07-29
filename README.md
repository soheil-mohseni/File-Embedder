# ✨ embeded

> ⚡ Easily convert files to C string literals or Assembly `db` directives for embedding in your code! ⚡

---

## 📦 What is embeded?

**embeded** is a command-line utility to convert any file (binary or text) into a format that can be directly pasted into your C or Assembly source code.  
No more messing with file I/O at runtime — embed your data right in the source!

---

## 🎯 Features

- 🔥 Convert any file to a C string literal or Assembly data table
- 📝 Supports custom variable/label naming
- 💡 Simple command-line interface
- 📁 Portable, standard C

---

## 🚀 Quick Start

### ⏳ Build

```sh
make

This creates the **embeded** executable in your folder.

### 🧰 Usage

sh
./embeded [OPTIONS] <identifier> < inputfile

#### 📚 Options

- `-h`, `--help` Show usage information
- `-a`       Output as Assembly (`db`) (default is C)

#### ⚡ Example 1: Embed file as C string

sh
./embeded my_data < picture.png > resource.c
_Produces:_
c
C program identifier: my_data
"\x89\x50\x4E\x47..."

#### ⚡ Example 2: Embed file as Assembly (`db`)

sh
./embeded -a firmware_blob < firmware.bin > data.asm
_Produces:_

Assembly program identifier: firmware_blob
db0x89,0x50,0x4E,0x47,...

---

## 🧩 Project Structure

text
├── embeded.c         # Main source file
├── embeded.h         # Main header
├── helperutils.c     # Helper function implementations
├── helperutils.h     # Helper function declarations
├── Makefile          # Build instructions
└── README.md         # This documentation

---

## 🧹 Cleaning up

Remove build artifacts:

sh
make clean

---

## 🛠️ Why use embeded?

- 📦 Bundle resources directly in a single program image
- 🔒 Avoid file corruption issues and runtime file loading
- 🗜️ Simplify distribution and deployment

---

## ⚖️ License

_Free to use, modify, or distribute as you wish!_

---

<p align="center"><sub>Made with 💙 for embedded and systems programmers</sub></p>

---

Feel free to further customize the description, examples, or add badges if hosting on GitHub!