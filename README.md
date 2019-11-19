# vkBasalt
A Vulkan post processing layer. Currently, the only effects are:
- Contrast Adaptive Sharpening 
- Fast Approximate Anti-Aliasing
- Enhanced Subpixel Morphological Anti-Aliasing

# Disclaimer
This one of my first projects ever. Look at the code at your own risk.

# Build
You need the Vulkan SDK to build this, and glslangValidator to compile the shader.

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

Settings like the CAS sharpening strength can be changed in `~/.local/share/vkBasalt/vkBasalt.conf` for all games.
If you want to make changes for one game only, you can create a file named `vkBasalt.conf` in the working directory of the game and change the value there.

