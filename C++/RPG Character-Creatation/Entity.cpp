#include "Entity.h"

using namespace std;

//EXTRA
string MakeLower(string word) {
    string newWord;
    for(int i =0; i < static_cast<int>(word.size()); ++i) {
        if (not isspace(word[i])) {
            newWord = newWord + static_cast<char>(tolower(word[i]));
        }
    }
    return newWord;
}
RACE_TYPE StringToRace(string word) {
    RACE_TYPE race (RACE_TYPE::RACE);
    do {
        word = MakeLower(word);
        if (word == "altmer") {
            race = RACE_TYPE::ALTMER; 
        } else if (word == "argorian") {
            race = RACE_TYPE::ARGORIAN;  
        } else if (word =="brenton") {
            race = RACE_TYPE::BRENTON;
        } else if (word == "dunmer") {
            race = RACE_TYPE::DUNMER;  
        } else if (word =="imperial") {
            race = RACE_TYPE::IMPERIAL;
        } else if (word == "khajiit") {
            race = RACE_TYPE::KHAJIIT;  
        } else if (word =="nord") {
            race = RACE_TYPE::NORD;
        } else if (word == "orsimer") {
            race = RACE_TYPE::ORSIMER;  
        } else if (word =="redguard") {
            race = RACE_TYPE::REDGUARD;
        } else {
            cout << "Invalid race, try again : ";
            cin >> word;
            cout << endl;
        } 
    } while (race == RACE_TYPE::RACE);
    return race;
}
string RaceToString(const RACE_TYPE r){
    string word = MakeLower(word);
    if (r == RACE_TYPE::ALTMER) {
        word = "Altmer"; 
    } else if (r == RACE_TYPE::ARGORIAN) {
        word = "Argorian";  
    } else if (r == RACE_TYPE::BRENTON) {
        word = "Brenton";
    } else if (r == RACE_TYPE::DUNMER) {
        word = "Dunmer";  
    } else if (r == RACE_TYPE::IMPERIAL) {
        word = "Imperial";
    } else if (r == RACE_TYPE::KHAJIIT) {
        word = "Khajiit";  
    } else if (r == RACE_TYPE::NORD) {
        word = "Nord";
    } else if (r == RACE_TYPE::ORSIMER) {
        word = "Orsimer";  
    } else if (r ==RACE_TYPE::REDGUARD) {
        word = "Redguard";
    } else {
        word = "Race";
    }
    return word;
}

//Entity-parent class
EntityT::EntityT() : type(Entity_TYPE::Entity), name("") {}

EntityT::EntityT(string n, Entity_TYPE e) : type(e), name(n) {}

void EntityT::SetEntity_TYPE(string word){
    do{
        word = MakeLower(word);
        if (word == "player") {
            type = Entity_TYPE::PLAYER; 
        } else if (word == "npc") {
            type = Entity_TYPE::NPC;  
        } else if (word =="creature") {
            type = Entity_TYPE::CREATURE;
        } else {
            cout << "Invalid Entity type, try again : ";
            cin >> word;
            cout << endl;
        }
    } while (type == Entity_TYPE::Entity);
}

// CharacterTT-child of Entity
CharacterT::CharacterT(string initName, RACE_TYPE r) :
    EntityT(initName, Entity_TYPE::PLAYER) {race = r;};

CharacterT::CharacterT(string initName, string r) : 
    EntityT(initName, Entity_TYPE::PLAYER) {race = StringToRace(r);}

void CharacterT::SetRace(std::string w) {race = StringToRace(w);};

string CharacterT::GetRace() const {return RaceToString(race);}
// PlayerT-child of Player_Entity
PlayerT::PlayerT (string initName, string r) : CharacterT(initName, r){};

void PlayerT::IncrementPlayerLvl() {
    IncrementLvl();
    IncrementHealth_Stamina();
    skillTree_Points++;
};
// NPC-child of Player_Entity
NPCT::NPCT (string initName, string r) : CharacterT(initName, r){};
// CreatureT-child of Entity
CreatureT::CreatureT(string initName,string initCreatureType) :
    EntityT(initName, Entity_TYPE::CREATURE) {creatureType = initCreatureType;}
/*
Overall Feedback
Handling the friendly attribute is tricky. Are there classes that are/are not friendly to each other, or is it a literal case-by-case decision?  (The first is straightforward.) Establishing a unique ID for each entity could be useful. (A standard approach is to use a static data member, which keeps track of a current ID number.)

You should separate your entity building routines into functions; as it stands, your main() is long and hard to follow. You could return a (new) PlayerT, NPCT, etc., and you could store the result in an EntityT* (or smart pointer).
*/