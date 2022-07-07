# vkBasalt
vkBasalt is a Vulkan post-processing layer to enhance games' visual graphics.

The built-in effects currently are:
- 3D color lookup table
- Contrast adaptive sharpening
- Denoised luma sharpening
- Enhanced subpixel morphological antialiasing
- Fast approximate anti-aliasing

It is also possible to use ReShade FX shaders.
## Disclaimer
This is one of my first projects ever, so expect it to have bugs. Use it at your own risk.
## Building from source
### Dependencies
Before building, you will need:
- GCC 9≥
- X11 development files
- glslang
- SPIR-V headers
- Vulkan headers
### Building
**These instructions use `--prefix=/usr`, which is generally not recommended, as vkBasalt will be installed in directories that are meant for the package manager. The alternative is not setting the prefix, so it will be installed in `/usr/local`. But you need to make sure the `ld` finds the library, as /usr/local is probably not in the default path.** 

Prefer using distro-provided packages generally.
```
git clone https://github.com/DadSchoorse/vkBasalt.git
cd vkBasalt
```
#### 32-bit
Make sure the `PKG_CONFIG_PATH=/usr/lib32/pkgconfig` & `--libdir=lib32` are right for your distro & change them if needed, e.g. You need to replace `lib32` by `lib/i386-linux-gnu` on Debian-based distros.
```
ASFLAGS=--32 CFLAGS=-m32 CXXFLAGS=-m32 PKG_CONFIG_PATH=/usr/lib32/pkgconfig meson --prefix=/usr --buildtype=release --libdir=lib32 -Dwith_json=false builddir.32
ninja -C builddir.32 install
```
#### 64-bit
```
meson --buildtype=release --prefix=/usr builddir
ninja -C builddir install
```
### Packaging status
[Debian](https://tracker.debian.org/pkg/vkbasalt) `sudo apt install vkbasalt`

[Fedora](https://src.fedoraproject.org/rpms/vkBasalt) `sudo dnf install vkBasalt`

[Void Linux](https://github.com/void-linux/void-packages/blob/master/srcpkgs/vkBasalt/template) `sudo xbps-install vkBasalt`
## Usage
Enable the layer with the environment variable.
### Lutris
Follow these steps with Lutris:
1. Right-click on a game & click on `Configure`.
2. Go to the `System options` tab & scroll down to `Environment variables`.
3. Click on `Add` & add `ENABLE_VKBASALT` under `Key` & `1` under `Value`.
### Standard
When using the terminal or an application (.desktop) file, run:
```ini
ENABLE_VKBASALT=1 yourgame
```
### Steam
Edit your launch options with Steam & add:
```ini
ENABLE_VKBASALT=1 %command% 
```
## Configure
Settings like the CAS sharpness amount can be changed in the config file.
The config file will be searched for in the locations:
* A file set with the environment variable`VKBASALT_CONFIG_FILE=/path/to/vkBasalt.conf`
* `vkBasalt.conf` in the game's working directory
* `$XDG_CONFIG_HOME/vkBasalt/vkBasalt.conf` or `~/.config/vkBasalt/vkBasalt.conf` if `XDG_CONFIG_HOME` is not set
* `$XDG_DATA_HOME/vkBasalt/vkBasalt.conf` or `~/.local/share/vkBasalt/vkBasalt.conf` if `XDG_DATA_HOME` is not set
* `/etc/vkBasalt.conf`
* `/etc/vkBasalt/vkBasalt.conf`
* `/usr/share/vkBasalt/vkBasalt.conf`

You can create a file named `vkBasalt.conf` in the game's working directory & change the values there if you want to make changes for one game only.
### ReShade FX shaders
You need to set `reshadeTexturePath` & `reshadeIncludePath` to the matching directories from the repository to run ReShade FX shaders, e.g. shaders from the [ReShade repository](https://github.com/crosire/reshade-shaders). You need to set a custom effect name to the shader path then add that effect name to `effects` like every other effect to use a specific shader.
```ini
effects = colorfulness:denoise

colorfulness = /home/user/reshade-shaders/Shaders/Colourfulness.fx
denoise = /home/user/reshade-shaders/Shaders/Denoise.fx
reshadeTexturePath = /home/user/reshade-shaders/Textures
reshadeIncludePath = /home/user/reshade-shaders/Shaders
```
### Ingame input
The [Home key](https://en.wikipedia.org/wiki/Home_key) can be used to disable & re-enable the applied effects. The key can also be changed in the config file. It will not work on pure Wayland, as it is based on X11. It **should**, however, not crash without X11.
### Debug output
The amount of debug output can be set with the `VKBASALT_LOG_LEVEL` env var, e.g. `VKBASALT_LOG_LEVEL=debug`. Valid values are: `trace, debug, info, warn, error, none`.

The logger outputs to stderr by default. A file as output location can be set with the `VKBASALT_LOG_FILE` env var, e.g. `VKBASALT_LOG_FILE="vkBasalt.log"`.
## FAQ
### Why is it called vkBasalt?
It is a joke: Vulkan post-processing &#8594; after vulcan &#8594; basalt.
### Does vkBasalt work with dxvk & vkd3d?
Yes.
### Will vkBasalt get me banned?
Maybe. It has not happened yet to my knowledge, but do not blame me if your frog dies.
### Will there be an OpenGL version?
No. I do not know anything about OpenGL & I do not want to either. Also, OpenGL has no layer system like Vulkan.
### Will there be a GUI in the future?
Maybe, but not soon.
### So, is vkBasalt just a Linux port of ReShade?
Not really. The code was mostly written from scratch. vkBasalt directly uses ReShade source code for the shader compiler (thanks [@crosire](https://github.com/crosire)), but that is about it.
### Does every ReShade shader work?
No. Shaders that need many techniques do not work, there might still be issues with stencil & blending & depth buffer access is not ready yet.
### You said that "depth buffer access is not ready yet". What do you mean?
There is a WIP version that you can enable with `depthCapture = on`. It will cause many issues especially on non-Nvidia hardware. Also, the chosen depth buffer is not always the one wanted.
### Is there a way to change settings for ReShade shaders?
There is some support for it [#46](https://github.com/DadSchoorse/vkBasalt/pull/46). An easy way is to simply edit the shader file.
