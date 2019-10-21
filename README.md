# vkBasalt
A Vulkan post processing layer. Currently, the only effect is Contrast Adaptive Sharpening.

# Disclaimer
This one of my first projects ever. Look at the code at your own risk.

# Build
You need the Vulkan SDK to build this, and glslangValidator to compile the shader.

On Arch-based distributions, they can be installed with:
```
pacman -Sy glslang vulkan-headers vulkan-tools vulkan-validation-layers
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
Enable the layer with the environment variable. First, check if the game is 64-bit or 32-bit.

For 64-bit:
```
ENABLE_VKBASALT=1 yourgame
```

For 32-bit:
```
ENABLE_VKBASALT32=1 yourgame
```

with Steam, edit your launch options, e.g. :

```
ENABLE_VKBASALT=1 %command% 
```

