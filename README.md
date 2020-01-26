# vkBasalt
vkBasalt is a Vulkan post processing layer to enhance the visual graphics of games.

Currently, the only effects are:
- Contrast Adaptive Sharpening 
- Fast Approximate Anti-Aliasing
- Enhanced Subpixel Morphological Anti-Aliasing
- Deband/Dithering
- 3D color LookUp Table

## Disclaimer
This is one of my first projects ever, so expect it to have bugs. Use it at your own risk.

## Install
**There are binaries attached to each release, so manually building from source is not required**

Once you have the binearies, either by downloading and unpacking them or by following the build instructions below, execute:
```
make install
```
**Note: do not run this with `sudo`. vkBasalt gets installed for the current user only.**

## Prerequisites
Before building, you will need:
- Vulkan SDK
- glslangValidator - To compile the shader
- GCC >=7

See below on how to install them.

### Arch-based distributions
For Arch-based distributions, execute:
```
pacman -Syu glslang vulkan-headers vulkan-tools vulkan-validation-layers
```
### Fedora
For Fedora, execute:
```
sudo dnf install vulkan-headers vulkan-tools vulkan-validation-layers vulkan-validation-layers-devel glslang glibc-devel.i686 libstdc++-devel.i686 spirv-tools
```
### Gentoo-based distributions
For Gentoo-based distributions, execute:
```
sudo emerge -v dev-util/glslang dev-util/vulkan-headers dev-util/vulkan-tools media-libs/vulkan-layers media-libs/vulkan-loader dev-util/spirv-tools
```
## Build
To build and install the program, execute:
```
git clone https://github.com/DadSchoorse/vkBasalt.git ~/vkBasalt
cd ~/vkBasalt
make
```
##### TIP: Use the `-jX` (where X=number of cpu threads) option to accelerate the building process.

## Usage
Enable the layer with the environment variable (see below). Since vkBasalt 0.2.0 there is one unified variable for 64-bit and 32-bit games.

### Standard
When using the terminal or an application (.desktop) file, execute:
```
ENABLE_VKBASALT=1 yourgame
```

### Lutris
With Lutris, follow these steps below:
1. Right click on a game, and press `configure`.
2. Go to the `System options` tab and scroll down to `Environment variables`.
3. Press on `Add`, and add `ENABLE_VKBASALT` under `Key`, and add `1` under `Value`.

### Steam
With Steam, edit your launch options and add:
```
ENABLE_VKBASALT=1 %command% 
```

## Configure

Settings like the CAS sharpening strength can be changed in the config file.
The config file will be searched for in the following locations:
* a file set with the environment variable`VKBASALT_CONFIG_FILE=/path/to/vkBasalt.conf`
* `vkBasalt.conf` in the working directory of the game
* `$XDG_CONFIG_HOME/vkBasalt/vkBasalt.conf` or `~/.config/vkBasalt/vkBasalt.conf` if `XDG_CONFIG_HOME` is not set
* `$XDG_DATA_HOME/vkBasalt/vkBasalt.conf` or `~/.local/share/vkBasalt/vkBasalt.conf` if `XDG_DATA_HOME` is not set
* `/usr/share/vkBasalt/vkBasalt.conf`
* `/usr/local/share/vkBasalt/vkBasalt.conf`

If you want to make changes for one game only, you can create a file named `vkBasalt.conf` in the working directory of the game and change the values there.

## Previews
[YouTube](https://www.youtube.com/watch?v=hSlaGkbTRi8)
