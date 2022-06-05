#!/usr/bin/bash
mkdir ~/tmp
cd ~/tmp
mkdir -p ~/.local/lib ~/.config/vkBasalt ~/.local/share/vulkan/implicit_layer.d
curl https://cf-builds.garudalinux.org/repos/chaotic-aur/x86_64/vkbasalt-0.3.2.5-3-x86_64.pkg.tar.zst --output vkbasalt.tar.zst
tar -xf vkbasalt.tar.zst
cp opt/vkBasalt/lib/libvkbasalt.so ~/.local/lib/
cp usr/share/vkBasalt/vkBasalt.conf.example ~/.config/vkBasalt/vkBasalt.conf
cp usr/share/vulkan/implicit_layer.d/vkBasalt.json ~/.local/share/vulkan/implicit_layer.d/
sed -i 's|/opt/vkBasalt|'"${HOME}"'/.local|g' ~/.local/share/vulkan/implicit_layer.d/vkBasalt.json
