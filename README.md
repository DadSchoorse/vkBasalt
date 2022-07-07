# vkBasalt
vkBasalt is a Vulkan post-processing layer to enhance games' visual graphics.

The built-in effects currently are:
- contrast adaptive sharpening
- denoised luma sharpening
- fast approximate anti-aliasing
- 3D color lookup table
- enhanced subpixel morphological antialiasing

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
**These instructions use `--prefix=/usr`, which is generally not recommended, since vkBasalt will be installed in directories that are meant for the package manager. The alternative is not setting the prefix, it will then be installed in `/usr/local`. But you need to make sure that `ld` finds the library, since /usr/local is very likely not in the default path.** 

Prefer using distro provided packages generally.
```
git clone https://github.com/DadSchoorse/vkBasalt.git
cd vkBasalt
```
#### 64bit
```
meson --buildtype=release --prefix=/usr builddir
ninja -C builddir install
```
#### 32bit
Make sure that `PKG_CONFIG_PATH=/usr/lib32/pkgconfig` and `--libdir=lib32` are correct for your distro and change them if needed. On Debian based distros you need to replace `lib32` with `lib/i386-linux-gnu`, for example.
```
ASFLAGS=--32 CFLAGS=-m32 CXXFLAGS=-m32 PKG_CONFIG_PATH=/usr/lib32/pkgconfig meson --prefix=/usr --buildtype=release --libdir=lib32 -Dwith_json=false builddir.32
ninja -C builddir.32 install
```
### Packaging status
[Debian](https://tracker.debian.org/pkg/vkbasalt) `sudo apt install vkbasalt`

[Fedora](https://src.fedoraproject.org/rpms/vkBasalt) `sudo dnf install vkBasalt`

[Void Linux](https://github.com/void-linux/void-packages/blob/master/srcpkgs/vkBasalt/template) `sudo xbps-install vkBasalt`
## Usage
Enable the layer with the environment variable.
### Standard
When using the terminal or an application (.desktop) file, execute:
```ini
ENABLE_VKBASALT=1 yourgame
```
### Lutris
Follow these steps below with Lutris:
1. Right click on a game and press `Configure`.
2. Go to the `System options` tab and scroll down to `Environment variables`.
3. Click on `Add` and add `ENABLE_VKBASALT` under `Key` and `1` under `Value`.
### Steam
Edit your launch options with Steam and add:
```ini
ENABLE_VKBASALT=1 %command% 
```
## Configure
Settings like the CAS sharpening strength can be changed in the config file.
The config file will be searched for in the following locations:
* a file set with the environment variable`VKBASALT_CONFIG_FILE=/path/to/vkBasalt.conf`
* `vkBasalt.conf` in the game's working directory
* `$XDG_CONFIG_HOME/vkBasalt/vkBasalt.conf` or `~/.config/vkBasalt/vkBasalt.conf` if `XDG_CONFIG_HOME` is not set
* `$XDG_DATA_HOME/vkBasalt/vkBasalt.conf` or `~/.local/share/vkBasalt/vkBasalt.conf` if `XDG_DATA_HOME` is not set
* `/etc/vkBasalt.conf`
* `/etc/vkBasalt/vkBasalt.conf`
* `/usr/share/vkBasalt/vkBasalt.conf`

You can create a file named `vkBasalt.conf` in the game's working directory and change the values there if you want to make changes for one game only.
### Reshade Fx shaders
To run ReShade FX shaders, e.g. shaders from the [ReShade repository](https://github.com/crosire/reshade-shaders), you have to set `reshadeTexturePath` and `reshadeIncludePath` to the matching dirctories from the repo. To then use a specific shader you need to set a custom effect name to the shader path and then add that effect name to `effects` like every other effect.
```ini
effects = colorfulness:denoise

colorfulness = /home/user/reshade-shaders/Shaders/Colourfulness.fx
denoise = /home/user/reshade-shaders/Shaders/Denoise.fx
reshadeTexturePath = /home/user/reshade-shaders/Textures
reshadeIncludePath = /home/user/reshade-shaders/Shaders
```
### Ingame Input
The [HOME key](https://en.wikipedia.org/wiki/Home_key) can be used to disable and re-enable the applied effects. The key can also be changed in the config file. This is based on X11, so it will not work on pure Wayland. It **should**, however, at least not crash without X11.
### Debug Output
The amount of debug output can be set with the `VKBASALT_LOG_LEVEL` env var, e.g. `VKBASALT_LOG_LEVEL=debug`. Valid values are: `trace, debug, info, warn, error, none`.

The logger outputs to stderr by default. A file as output location can be set with the `VKBASALT_LOG_FILE` env var, e.g. `VKBASALT_LOG_FILE="vkBasalt.log"`.
## FAQ
### Why is it called vkBasalt?
It is a joke: Vulkan post-processing &#8594; after vulcan &#8594; basalt.
### Does vkBasalt work with dxvk and vkd3d?
Yes.
### Will vkBasalt get me banned?
Maybe. This has not happened yet to my knowledge, but do not blame me if your frog dies.
### Will there be a OpenGL version?
No. I do not know anything about OpenGL and I do not want to either. Also, OpenGL has no layer system like Vulkan.
### Will there be a GUI in the future?
Maybe, but not soon.
### So, is vkBasalt just a Linux port of ReShade?
Not really. The code was mostly written from scratch. vkBasalt directly uses ReShade source code for the shader compiler (thanks [@crosire](https://github.com/crosire)), but that is about it.
### Does every ReShade shader work?
No. Shaders that need many techniques do not work, there might still be issues with stencil and blending and depth buffer access is not ready yet.
### You said that "depth buffer access is not ready yet". What does this mean?
There is a WIP version that you can enable with `depthCapture = on`. It will lead to many problems especially on non Nvidia hardware. Also, the chosen depth buffer is not always the one wanted.
### Is there a way to change settings for ReShade shaders?
There is some support for it [#46](https://github.com/DadSchoorse/vkBasalt/pull/46). An easy way is to simply edit the shader file.
