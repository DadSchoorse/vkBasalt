FROM archlinux:base-devel

RUN echo -e " \n\
[multilib] \n\
Include = /etc/pacman.d/mirrorlist \n\
" >> /etc/pacman.conf

RUN pacman -Syu --noconfirm
RUN pacman -S --noconfirm meson glslang libx11 spirv-headers vulkan-headers lib32-libx11 lib32-glibc lib32-gcc-libs

WORKDIR /workdir
ADD . /workdir

ENTRYPOINT [ "/docker/build" ]