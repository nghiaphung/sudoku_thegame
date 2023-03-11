#pragma once

class GameBase {
    public:
        enum Difficulty {
            Easy,
            Medium,
            Hard,
        };

        Difficulty difficulty;

        // virtual void init(void) = 0;
        // virtual void run(void) = 0;
};