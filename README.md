# Resource Monitor

A terminal-based Resource Monitor designed for Linux systems. Displays the average CPU usage over all cores, memory usage, and GPU usage. Also available in a graphical version [here](https://github.com/MichaelCreel/Linux-Resource-Monitor-GUI)

## Dependencies

- GPU:
  - nvidia-smi (for NVIDIA cards)
  - amdgpu_top (for AMD cards)
  - intel_gpu_top (for Intel cards)

## Installation

1. Open a terminal (```Ctrl + Alt + T```)
2. Clone the repository
   ```bash
   git clone https://github.com/MichaelCreel/Linux-Resource-Monitor
3. Open app directory
   ```bash
   cd Linux-Resource-Monitor
4. (Optional) Install system-wide
   ```bash
   sudo cp resource-monitor /usr/local/bin/
5. Run app in terminal

  - System-wide:
    ```bash
    resource-monitor
    ```

  - Not System-wide:
    ```bash
    cd ~/Linux-Resource-Monitor/
    ./resource-monitor
    ```

## Notes

- If GPU tools are not found, your GPU usage will remain undetected
- Designed for Debian
- Root access required for intel_gpu_top
- Tested with an NVIDIA graphics card

## License

MIT License
