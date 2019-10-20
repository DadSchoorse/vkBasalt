# vkBasalt

A vulkan post processing layer. Currently the only effect is Contrast Adaptiv Sharpening.

# Disclaimer

This one of my first projects ever. Look at the code at your own risk.

# Build
You need the vulkan sdk to build this and glslangValidator to compile the shader.

Simply use
```
make
```
# Install

```
make install
```
# Usage

Enable the Layer with the environment varaible:
Check if your game is 32bit or or 64bit

For 64bit
```
ENABLE_VKBASALT=1 yourgame
```

For 32bit
```
ENABLE_VKBASALT32=1 yourgame
```

with steam edit your launch options, e.g. :

```
ENABLE_VKBASALT=1 %command% 
```

