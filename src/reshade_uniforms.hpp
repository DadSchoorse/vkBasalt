#ifndef RESHADE_UNIFORMS_HPP_INCLUDED
#define RESHADE_UNIFORMS_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <memory>

#include "vulkan_include.hpp"

#include "reshade/effect_module.hpp"

namespace vkBasalt
{
    void enumerateReshadeUniforms(reshadefx::module module);

    class ReshadeUniform
    {
    public:
        void virtual update(void* mapedBuffer) = 0;
        virtual ~ReshadeUniform(){};

    protected:
        uint32_t offset;
        uint32_t size;
    };

    std::vector<std::shared_ptr<ReshadeUniform>> createReshadeUniforms(reshadefx::module module);

    class FrameTimeUniform : public ReshadeUniform
    {
    public:
        FrameTimeUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~FrameTimeUniform();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> lastFrame;
    };

    class FrameCountUniform : public ReshadeUniform
    {
    public:
        FrameCountUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~FrameCountUniform();

    private:
        int32_t count = 0;
    };

    class DateUniform : public ReshadeUniform
    {
    public:
        DateUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~DateUniform();
    };

    class TimerUniform : public ReshadeUniform
    {
    public:
        TimerUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~TimerUniform();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
    };

    class PingPongUniform : public ReshadeUniform
    {
    public:
        PingPongUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~PingPongUniform();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> lastFrame;

        float min             = 0.0f;
        float max             = 0.0f;
        float stepMin         = 0.0f;
        float stepMax         = 0.0f;
        float smoothing       = 0.0f;
        float currentValue[2] = {0.0f, 1.0f};
    };

    class RandomUniform : public ReshadeUniform
    {
    public:
        RandomUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~RandomUniform();

    private:
        int max = 0;
        int min = 0;
    };

    class KeyUniform : public ReshadeUniform
    {
    public:
        KeyUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~KeyUniform();
    };

    class MouseButtonUniform : public ReshadeUniform
    {
    public:
        MouseButtonUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~MouseButtonUniform();
    };

    class MousePointUniform : public ReshadeUniform
    {
    public:
        MousePointUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~MousePointUniform();
    };

    class MouseDeltaUniform : public ReshadeUniform
    {
    public:
        MouseDeltaUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~MouseDeltaUniform();
    };

    class DepthUniform : public ReshadeUniform
    {
    public:
        DepthUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~DepthUniform();
    };

    class RuntimeUniform : public ReshadeUniform
    {
    public:
        RuntimeUniform(reshadefx::uniform_info uniformInfo);
        void virtual update(void* mapedBuffer) override;
        virtual ~RuntimeUniform();

    private:
        float defaultValue;
        char* pathname;
        int projId;
        key_t shmKey;
    };
} // namespace vkBasalt

#endif // RESHADE_UNIFORMS_HPP_INCLUDED
