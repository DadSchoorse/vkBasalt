# vkBasalt
A Vulkan post processing layer. Currently, the only effects are:
- Contrast Adaptive Sharpening 
- Fast Approximate Anti-Aliasing
- Enhanced Subpixel Morphological Anti-Aliasing
- Deband/Dithering
- 3D color LookUp Table

# Disclaimer
This one of my first projects ever. Look at the code at your own risk.

# Build
You need the Vulkan SDK to build this, and glslangValidator to compile the shader. GCC version 7 or higher is required.

On Arch-based distributions, they can be installed with:
```
pacman -Syu glslang vulkan-headers vulkan-tools vulkan-validation-layers
```

On Fedora, they can be installed with:
```
sudo yum install vulkan-headers vulkan-tools vulkan-validation-layers
```

On Solus, they can be installed with:
```
sudo eopkg it vulkan-headers vulkan-tools vulkan-validation-layers
```
On Gentoo, they can be installed with:
```
sudo emerge -v dev-util/glslang dev-util/vulkan-headers dev-util/vulkan-tools media-libs/vulkan-layers media-libs/vulkan-loader
```


Simply use
```
make
```
# Install
```
make install
```

# Usage
Enable the layer with the environment variable. Since vkBasalt 0.2.0 there is one unified variable for 64-bit and 32-bit games.

```
ENABLE_VKBASALT=1 yourgame
```

with Steam, edit your launch options, e.g.:
```
ENABLE_VKBASALT=1 %command% 
```

# Configure

Settings like the CAS sharpening strength can be changed in the config file.
The config file will be searched for in the following locations:
* a file set with the environment variable`VKBASALT_CONFIG_FILE=/path/to/vkBasalt.conf`
* `vkBasalt.conf` in the working directory of the game
* `$XDG_DATA_HOME/vkBasalt/vkBasalt.conf` or `~/.local/share/vkBasalt/vkBasalt.conf` if `XDG_DATA_HOME` is not set
* `/usr/share/vkBasalt/vkBasalt.conf`
* `/usr/local/share/vkBasalt/vkBasalt.conf`

If you want to make changes for one game only, you can create a file named `vkBasalt.conf` in the working directory of the game and change the values there.

