#pragma once
#include <iostream>

enum class Entity_TYPE {Entity, PLAYER, NPC, CREATURE};
enum class RACE_TYPE {RACE, ALTMER, ARGORIAN,BRENTON,DUNMER,IMPERIAL,KHAJIIT,
                      NORD,ORSIMER,REDGUARD};
const int NUMBER_OF_ENITIES(10);

class EntityT {
    Entity_TYPE type;
    std::string name;
    bool friendly[NUMBER_OF_ENITIES]{1};//I suppose with this you could give 
                            // NPC's ID's and have them friendly with certian
                            // ones, maybe a better way
                            // with 10 being the number of enities
                            // maybe this could be used with vectors
    int id;//not sure how to implement this, with inheritence//maybe in main
           //but proably a better way
           //but starts at 0, every new Entity
           //gets the next id like a serial number
    int lvl{1};
    float health{100};
    float stamina{100};
    public:
        EntityT();
        EntityT(std::string, Entity_TYPE);

        std::string GetName() const {return name;};
        void SetName(std::string newName){name = newName;};

        void SetEntity_TYPE(Entity_TYPE t) {type=t;}
        void SetEntity_TYPE(std::string);
        Entity_TYPE GetType() const {return type;};

        void SetLvl(int l){lvl=l;};
        void IncrementLvl() {lvl++;};
        int GetLvl(){return lvl;};

        void SetHealth(float h) {health = h;};
        void SetStamina(float s) {stamina = s;};
        void IncrementHealth_Stamina() {stamina = stamina + 5; health = health + 5;};
        float GetHealth() const {return health;};
        float GetStamina() const {return stamina;};

        void setFriendly(const bool f, const int i) {friendly[i] = f;};
            // says what Entity ID's are enemies, or friends to this Entity I
        bool IsFriendly(const int i) {return friendly[i];};
            // is Entity of i friendly to the current Entity?
};

class CharacterT : public EntityT {
    RACE_TYPE race;

    public:
        CharacterT(std::string initName, RACE_TYPE r);
        CharacterT(std::string, std::string);

        void SetRace(RACE_TYPE r) {race = r;}
        void SetRace(std::string);
        std::string GetRace() const;
};

class PlayerT : public CharacterT {
    int skillTree_Points{1};

    public:
        PlayerT(std::string, std::string);
        void IncrementPlayerLvl();

        int GetSkillTree_Points() {return skillTree_Points;};
};

class NPCT : public CharacterT {
    public:
        NPCT(std::string, std::string);
};

class CreatureT : public EntityT {
    std::string creatureType;

    public:
        CreatureT(std::string, std::string);

        void SetCreatureType(std::string c) {creatureType = c;}
        std::string GetCreatureType() const {return creatureType;};
};