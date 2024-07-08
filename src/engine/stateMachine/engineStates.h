#ifndef IDLE_H
#define IDLE_H

#include "engine/stateMachine/state.h"

namespace Engine {

    class Idle : public State {

        public:
            void execute(Wheel* rightWheel, Wheel* leftWheel) override;
            static State* getInstance() {
                static Idle* instance = new Idle();
                return instance;
            }

        private:
            Idle() = default;
            ~Idle() = default;
    };

    class Gas : public State {

        public:
            void execute(Wheel* rightWheel, Wheel* leftWheel) override;
            static State* getInstance() {
                static Gas* instance = new Gas();
                return instance;
            }

        private:
            Gas() = default;
            ~Gas() = default;

    };

    class Breaking : public State {

        public:
            void execute(Wheel* rightWheel, Wheel* leftWheel) override;
            static State* getInstance() {
                static Breaking* instance = new Breaking();
                return instance;
            }

        private:
            Breaking() = default;
            ~Breaking() = default;
    };

    class TurnRightGasing : public State {

        public:
            void execute(Wheel* rightWheel, Wheel* leftWheel) override;
            static State* getInstance() {
                static TurnRightGasing* instance = new TurnRightGasing();
                return instance;
            }

        private:
            TurnRightGasing() = default;
            ~TurnRightGasing() = default;
    };

    class TurnLeftGasing : public State {

        public:
            void execute(Wheel* rightWheel, Wheel* leftWheel) override;
            static State* getInstance() {
                static TurnLeftGasing* instance = new TurnLeftGasing();
                return instance;
            }

        private:
            TurnLeftGasing() = default;
            ~TurnLeftGasing() = default;
    };

    class TurnRightBreaking : public State {

        public:
            void execute(Wheel* rightWheel, Wheel* leftWheel) override;
            static State* getInstance() {
                static TurnRightBreaking* instance = new TurnRightBreaking();
                return instance;
            }

        private:
            TurnRightBreaking() = default;
            ~TurnRightBreaking() = default;
    };

    class TurnLeftBreaking : public State {

        public:
            void execute(Wheel* rightWheel, Wheel* leftWheel) override;
            static State* getInstance() {
                static TurnLeftBreaking* instance = new TurnLeftBreaking();
                return instance;
            }
        
        private:
            TurnLeftBreaking() = default;
            ~TurnLeftBreaking() = default;
    };

    class Reverse : public State {

        public:
            void execute(Wheel* rightWheel, Wheel* leftWheel) override;
            static State* getInstance() {
                static Reverse* instance = new Reverse();
                return instance;
            }

        private:
            Reverse() = default;
            ~Reverse() = default;
    };
}

#endif