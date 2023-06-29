# vkBasalt
vkBasalt is a Vulkan post-processing layer for improving the visuals of games. Expect bugs from it as it is one of my first projects. Use it at your own risk.

Currently, the built-in effects are:
- 3D color lookup table
- Contrast Adaptive Sharpening
- Denoised Luma Sharpening
- Enhanced Subpixel Morphological Anti-Aliasing
- Fast Approximate Anti-Aliasing

It is also possible to use ReShade FX shaders.

## Downloading
### [Debian](https://tracker.debian.org/pkg/vkbasalt)
```
sudo apt install vkbasalt
```

### [Fedora](https://src.fedoraproject.org/rpms/vkBasalt)
```
sudo dnf install vkBasalt
```

### [Void Linux](https://github.com/void-linux/void-packages/blob/master/srcpkgs/vkBasalt/template)
```
sudo xbps-install vkBasalt
```

## Usage
You can enable the layer with an environment variable.

### Lutris
Follow these steps with Lutris:
1. Right-click a game and click `Configure`.
2. Go to the `System options` tab and scroll down to `Environment variables`.
3. Click `Add` and add `ENABLE_VKBASALT` under `Key` and `1` under `Value`.

### Standard
When using the terminal or an application (.desktop) file, run:
```ini
ENABLE_VKBASALT=1 yourgame
```

### Steam
With Steam, edit your launch options and add:
```ini
ENABLE_VKBASALT=1 %command% 
```

## Settings
Settings, like the CAS sharpness amount, can be changed in the config file.

The config file will be searched for in the locations:
* `$XDG_CONFIG_HOME/vkBasalt/vkBasalt.conf` or `~/.config/vkBasalt/vkBasalt.conf` if `XDG_CONFIG_HOME` is not set
* `$XDG_DATA_HOME/vkBasalt/vkBasalt.conf` or `~/.local/share/vkBasalt/vkBasalt.conf` if `XDG_DATA_HOME` is not set
* `/etc/vkBasalt.conf`
* `/etc/vkBasalt/vkBasalt.conf`
* `/usr/share/vkBasalt/vkBasalt.conf`
* A file set with the environment variable `VKBASALT_CONFIG_FILE=/path/to/vkBasalt.conf`
* `vkBasalt.conf` in the game's working directory

You can create a file named `vkBasalt.conf` in the game's working directory and change the values there if you want to make changes for only one game.

### ReShade FX shaders
You must set `reshadeTexturePath` and `reshadeIncludePath` to the matching directories from the repository to run ReShade FX shaders, like shaders from the [ReShade repository](https://github.com/crosire/reshade-shaders). You must set a custom effect name to the shader path then add that effect name to `effects` like every other effect to use a specific shader.
```ini
effects = colorfulness:denoise

colorfulness = /home/user/reshade-shaders/Shaders/Colourfulness.fx
denoise = /home/user/reshade-shaders/Shaders/Denoise.fx
reshadeTexturePath = /home/user/reshade-shaders/Textures
reshadeIncludePath = /home/user/reshade-shaders/Shaders
```

### Ingame input
The [Home key](https://en.wikipedia.org/wiki/Home_key) can be used to toggle the applied effects. The key can also be changed in the config file. It will not work on pure Wayland as it is based on X11, but **should** not crash without X11.

### Debug output
The amount of debug output can be set with the `VKBASALT_LOG_LEVEL` environment variable, like `VKBASALT_LOG_LEVEL=debug`. Valid values are: `trace, debug, info, warn, error, none`.

The logger outputs to stderr by default. A file as output location can be set with the `VKBASALT_LOG_FILE` environment variable, like `VKBASALT_LOG_FILE="vkBasalt.log"`.

## Building from source

### Dependencies
Before building, you will need:
- GCC ≥ 9
- glslang
- SPIR-V headers
- Vulkan headers
- X11 development files

### Building
These instructions use `--prefix=/usr`, that is not recommended in general as vkBasalt will be installed in directories that are meant for the package manager. An alternative is not setting the prefix, so it will be installed in `/usr/local`. But you must ensure the `ld` finds the library; /usr/local is probably not in the default path.

Prefer to use distro-provided packages in general.
```
git clone https://github.com/DadSchoorse/vkBasalt.git
cd vkBasalt
```

#### 32-bit
Ensure the `PKG_CONFIG_PATH=/usr/lib32/pkgconfig` and `--libdir=lib32` are right for your distro and change them if needed. E.g., you must replace `lib32` by `lib/i386-linux-gnu` on Debian-based distros.
```
ASFLAGS=--32 CFLAGS=-m32 CXXFLAGS=-m32 PKG_CONFIG_PATH=/usr/lib32/pkgconfig meson setup --prefix=/usr --buildtype=release --libdir=lib32 -Dwith_json=false builddir.32
ninja -C builddir.32 install
```

#### 64-bit
```
meson setup --buildtype=release --prefix=/usr builddir
ninja -C builddir install
```

## FAQ
### Why is it called vkBasalt?
It is a joke: Vulkan post-processing → after vulcan → basalt.

### Does vkBasalt work with DXVK and VKD3D?
Yes.

### Will vkBasalt get me banned?
Maybe. It has not happened yet to my knowledge, but do not blame me if your frog dies.

### Will there be an OpenGL version?
No. I do not know anything about OpenGL and I do not want to either. Also, OpenGL has no layer system like Vulkan.

### Will there be a GUI in the future?
Maybe, but not soon.

### So, is vkBasalt just a Linux port of ReShade?
Not really. The code was mostly written from scratch. vkBasalt directly uses ReShade source code for the shader compiler (thanks [@crosire](https://github.com/crosire)), but that is about it.

### Does every ReShade shader work?
No. Depth buffer access is not ready yet, shaders that need many techniques do not work and there might still be issues with blending and stencil.

### You said that "depth buffer access is not ready yet". What do you mean?
There is a WIP version you can enable with `depthCapture = on`. It will cause many issues especially on non-Nvidia hardware. Also, the chosen depth buffer is not always the one wanted.

### Is there a way to change settings for ReShade shaders?
There is some support for it [#46](https://github.com/DadSchoorse/vkBasalt/pull/46). An easy way to do it is to simply edit the shader file.
