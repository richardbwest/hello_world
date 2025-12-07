# Pebble Hello World Tutorial

**This is a tutorial project** - A simple "Hello, World!" Pebble watchface application designed to teach the basics of Pebble app development. This project demonstrates creating a window, displaying text with custom fonts, and basic UI layout.

## Pebble Watchface Setup Instructions

### Step 1 - Install Dependencies

```bash
sudo apt update
sudo apt install python3-pip python3-venv nodejs npm libsdl1.2debian libfdt1 ninja-build libglib2.0-dev flex gcc-arm-none-eabi
```

### Step 2 - Install UV Package Manager (Non-Ubuntu)

Use the official installer script:

```bash
curl -LsSf https://astral.sh/uv/install.sh | sh
```

### Step 3 - Install the Pebble SDK

Follow the instructions at: [Pebble SDK](https://developer.pebble.com/sdk/)

```bash
uv tool install pebble-tool
```

### Step 4 - Download & Unzip Example Repository

Example repo: [pebble_hello_world](https://github.com/richardbwest/pebble_hello_world)

### Step 5 - Build the App

```bash
pebble build
```

### Step 6 - Run the Watchface on the EMU

Run from inside the main project folder

To install on the emulator (requires QEMU):

```bash
pebble install --emulator diorite
```

### Step 7 - Enable Developer Connection on Your Pebble Watch

1. Open the Pebble app on your phone.
2. Navigate to **Settings → Developer → Enable Developer Connection**.
3. Note the IP address displayed under the developer connection settings. This is needed to install apps directly to your watch.

### Step 8 - Install the app on your watch via your phone

To install on your watch via the phone:

```bash
pebble install --phone 192.168.1.100
```

Replace `192.168.1.100` with the IP address shown in your Pebble app's developer settings.

## Tutorial Features

This tutorial demonstrates:

- Creating a Pebble window
- Adding a text layer to display content
- Setting custom fonts (Gothic 28 Bold)
- Centering text alignment
- Multi-line text display
- Window lifecycle management (load/unload handlers)
- Memory management (proper cleanup)

## Project Structure

```
pebble_hello_world/
├── src/
│   └── c/
│       └── main.c          # Main application code with tutorial comments
├── package.json            # Project configuration
├── wscript                 # Build configuration
└── README.md               # This file
```

## Code Comments

The `main.c` file includes detailed YouTube tutorial-style comments explaining each line of code, making it perfect for learning Pebble development basics.

