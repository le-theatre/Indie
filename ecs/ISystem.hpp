#pragma once

class ISystem {
    public:
        virtual ~ISystem() = default;

        virtual void run() = 0;

    protected:
    private:
};
