🖥️ Retra-OS

Retra-OS is an experimental operating system project built from scratch for learning and exploring low-level programming and OS development.

The goal of this project is to understand how operating systems work internally by implementing core components manually.

🚀 Features
🔧 Custom kernel
🧠 Basic memory handling
🖥️ Text output (VGA / framebuffer)
⚙️ Low-level programming (C & x86 Assembly)
📀 Bootloader-based startup

⚠️ This project is a work in progress and not intended for production use

🛠️ Technologies
C — core logic
x86 Assembly — low-level and boot code
GNU Toolchain (gcc, ld, nasm)
QEMU / Bochs — emulation and testing
📦 Installation & Build
1. Clone the repository
git clone https://github.com/Sergored/Retra-Os.git
cd Retra-Os
2. Install dependencies

Example for Linux:

sudo apt install build-essential nasm qemu-system-x86
3. Build the project
make
▶️ Run
make run

Or manually with QEMU:

qemu-system-x86_64 -drive format=raw,file=build/os-image.bin
📂 Project Structure
Retra-Os/
│── boot/        # bootloader
│── kernel/      # kernel source
│── drivers/     # hardware interaction
│── lib/         # utility functions
│── build/       # compiled output
│── Makefile
📖 Purpose

This project is created for educational purposes and experimentation. It follows the idea of building an operating system from scratch to better understand:

how kernels work
memory management basics
hardware interaction
system boot process
🤝 Contributing

Contributions are welcome!

Fork the repository
Create a branch (feature/your-feature)
Commit your changes
Open a Pull Request
📄 License

GPL-3.0

📬 Contact
Telegram: @Fergerdeter

⭐ Notes

Retra-OS is a great project for learning:

OS internals
low-level programming
system architecture
