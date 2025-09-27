#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

constexpr std::string_view LEVEL_CREATOR = "tricipital";
constexpr std::string_view LEVEL_NAME = "Labyrinth";

constexpr auto ACHIEVEMENTS = std::to_array<std::string_view>({
    "beginnings", "big spender", "quick death", "cursed", "thievery", "upgrade", "min max", "ispy", "boom", "invigorated", "flying", "spicy",
    "freezing", "zap", "shutdown", "mystery", "prepared", "shortcut", "sneaky deals", "secret box", "game time", "casino blitz", "collector",
    "speedrunner1", "speedrunner2", "speedrunner3", "speedrunner4", "it lives", "it rests", "sneaky sneaky", "droppy", "good ending", "escapee",
    "adventurer1", "adventurer2", "adventurer3", "adventurer4", "how to adventure", "speed of light", "blank", "blank", "blank"
});

static const std::unordered_set<int> PLAYTESTER_IDS = {
    6061424, 4712395, 11826816, 63047, 106255, 4569963, 1788352, 1292925, 2156992, 1327813, 8328899, 2358957, 201646, 5375030, 104497,
    42681, 1696128, 15875490, 1521580, 7060819, 3578384, 13842489, 2671693, 1249399, 8002621, 21476843, 4103842, 6192122, 10905351,
    16750360, 13935562, 19542150, 18298730, 20063614, 25373869, 11167197, 3822295, 7882688, 571210, 7346996, 9471312, 20550026, 8921237, 24813127
};

static const std::unordered_set<int> CONTRIBUTOR_IDS = {
    6061424, 7882688, 63047, 34602, 13903094, 11167197, 11826816, 3166813, 16610096, 8851103, 20371964, 1696128, 6225348, 7709071,
    8328899, 20550026, 13842489, 2671693, 16494507, 8002621, 14277495, 54944, 19864272, 21113321, 21476843, 19691441, 7060384,
    20581650, 21679473, 5454096, 7346996
};

static const std::unordered_set<int> CONTEST_IDS = { 6061424 };
static const std::unordered_set<int> CHATTER_IDS = { 6061424, 25373869, 19542150, 28154640, 21476843, 31384585, 2671693, 13842489, 27995263, 63047, 16546314, 4422848 };

struct ItemMapping {
    std::string_view name;
    int id;
    int defaultValue = 0;
};

constexpr auto ITEM_MAPPINGS = std::to_array<ItemMapping>({
    {"souls", 64},             // Souls
    {"has_gotten_soul", 65},   // Has gotten a soul before
    {"language", 58},          // Language
    {"idle_lookdown", 99, 2},  // Idle Lookdown
    {"upgrade1", 113},         // Bounce Staff Upgrades
    {"upgrade2", 114},         // Teleporter Upgrades
    {"upgrade3", 115},         // Jetpack Upgrades
    {"upgrade4", 116},         // Ice Boots Upgrades
    {"blacksmith", 126},       // Blacksmith Freed
    {"furthest", 122},         // Furthest Reached
    // {"visitor", 127},       // New NPC
    {"times_stolen", 123},     // Times Stolen
    {"entered1", 128},         // Entered Stage 1?
    {"loot_goblin", 177},      // Loot Goblin
    {"shortcut", 180},         // Shortcut progress
    {"trail", 119},            // Trail selected
    {"equipedpos", 8998},      // Perk equiped
    {"charismaperk", 8996},    // Charisma Perk
    {"ispyperk", 8995},        // Eye Spy Perk
    {"blastperk", 8994},       // Blast Process Perk
    {"gamblerperk", 8993},     // Gambler Perk
    {"shopcompassperk", 8992}, // Shopping Addict Perk
    {"lavaperk", 8991},        // Obsidian Skin Perk
    {"stealperk", 8990},       // Shoplifter Perk
    {"speedperk", 8989},       // Speedballing Perk
    {"bigmanperk", 8988},      // Big Man Perk
    {"compassperk", 8987},     // Navigator Perk
    {"greedperk", 8986},       // Curse of Greed Perk
    {"rootedstepperk", 8985},  // Rooted Step Perk
    {"interestperk", 8984},    // Interest Perk
    {"richperk", 8983},        // Rich Perk
    {"clearanceperk", 8982},   // Clearance Perk
    {"surplusperk", 8981},     // Surplus Perk
    {"bombperk", 8980},        // Demolitions Expert Perk
    {"soulfulperk", 8979},     // Soulful Perk
    {"key1", 8974},            // Perk key 1
    {"key2", 8973},            // Perk key 2
    {"key3", 8972},            // Perk key 3
    {"key1total", 8975},       // Perk key 1 total
    {"key2total", 8976},       // Perk key 2 total
    {"key3total", 8977},       // Perk key 3 total
    {"perkwitch", 438},        // Perk witch progress
    {"stage1cutscene", 439},   // How many times stage 1 has been entered for cutscene
    {"trailghost", 441},       // trail ghost
    {"deatheffect", 419},      // Death effect disable
    {"speedruntimer", 358},    // Speedrun timer setting
    {"combo1", 278},           // Secret Combination 1
    {"combo2", 279},           // Secret Combination 2
    {"combo3", 280},           // Secret Combination 3
    {"combo4", 281},           // Secret Combination 4
});

class $modify(MyPlayerLayer, PlayLayer) {
    bool checkIfLabyrinth() {
        std::string_view levelName = m_level->m_levelName;
        return levelName.starts_with(LEVEL_NAME)
               && m_level->m_creatorName == LEVEL_CREATOR
               && Mod::get()->hasSavedValue("souls");
    }

    void setCounter(int id, int value) {
        m_effectManager->updateCountForItem(id, value);
        this->updateCounters(id, value);
    }

    void specialPrivs() {
        // User has Labyrinth+ enabled
        m_effectManager->updateCountForItem(233, 1);
        this->updateCounters(233, 1);

        auto userAccountID = GJAccountManager::sharedState()->m_accountID;

        // Checking for if the user is a playtester
        if (PLAYTESTER_IDS.contains(userAccountID)) {
            this->setCounter(432, 1);
        }

        // Checking for if the user is a contributor
        if (CONTRIBUTOR_IDS.contains(userAccountID)) {
            this->setCounter(433, 1);
        }

        // Checking for if the user is a contest winner
        if (CONTEST_IDS.contains(userAccountID)) {
            this->setCounter(434, 1);
        }

        // Checking for if the user is a chatter
        if (CHATTER_IDS.contains(userAccountID)) {
            this->setCounter(435, 1);
        }
    }

    void saveState() {
        for (auto [name, id, defaultValue] : ITEM_MAPPINGS) {
            Mod::get()->setSavedValue<int>(name, m_effectManager->countForItem(id));
        }

        for (int i = 0; i < ACHIEVEMENTS.size(); i++) {
            Mod::get()->setSavedValue<int>(ACHIEVEMENTS[i], m_effectManager->countForItem(i + 1000));
        }
    }

    void setupHasCompleted() {
        PlayLayer::setupHasCompleted();

        if (this->checkIfLabyrinth()) {
            // Checking for IRL day or night
            auto localTime = fmt::localtime(time(nullptr));
            int currentHour = localTime.tm_hour;
            if (currentHour >= 19 || currentHour <= 6){
                this->setCounter(431, 1);
            }

            // User has Labyrinth+ enabled
            this->setCounter(233, 1);

            // Loading saved items
            for (auto [name, id, defaultValue] : ITEM_MAPPINGS) {
                this->setCounter(id, Mod::get()->getSavedValue(name, defaultValue));
            }

            for (int i = 0; i < ACHIEVEMENTS.size(); i++) {
                this->setCounter(i + 1000, Mod::get()->getSavedValue(ACHIEVEMENTS[i], 0));
            }

            this->specialPrivs();
        }
    }

    void onExit() override {
        PlayLayer::onExit();
        if (this->checkIfLabyrinth()) {
            this->saveState();
        }
    }

    void startGameDelayed() {
        PlayLayer::startGameDelayed();
        if (this->checkIfLabyrinth()) {
            this->saveState();
            this->specialPrivs();
        }
    }
};