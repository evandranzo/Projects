#include "Entity.h"
#include <vector>

using namespace std;

void BuildPlayer(string n, string t);
void BuildNPC(string n, string t);
void BuildCreature(string n, string t);

int main() {
    EntityT Entity;
    string name, tmp;

    cout << "Creating an Entity..." << endl
         << "What sort of Entity?" << endl
         << "Player, NPC, or Creature?: ";
    cin >> tmp;

    Entity.SetEntity_TYPE(tmp);
    cin.ignore(256,'\n');
    if (Entity.GetType() == Entity_TYPE::PLAYER){//could just use if t == 
        BuildPlayer(name, tmp);
    } else if (Entity.GetType() == Entity_TYPE::NPC){
        BuildNPC(name,tmp);
    } else if (Entity.GetType() == Entity_TYPE::CREATURE){
        BuildCreature(name,tmp);
    } else {
        cout << "Please enter a valid Entity type";
    }
    vector<double> numberVec {1.2, 2.3, 3.1};
    auto value numberVec.begin();
    std::cout << type_name<decltype(value)>() << '\n';
    return 0;


}
void BuildPlayer(string n, string t){
                                                //"player", but this logically 
                                            //sounds better
    cout << "What is the players name?: ";
    getline(cin,n);
    cout << "What is " << n << "'s race?" << endl 
            << "You can choose Altmer, Argorian, Brenton, Dunmer, Imperial, "
            << "Khajiit, Nord, Orsimer, Redguard?: ";
    cin >> t;
    cout << t;
    //creating a player
    PlayerT player(n, t);
    cout << "A player has been made with the name " << player.GetName() 
            << " and is an " << player.GetRace() << ":" << endl << endl;

    cout << "You start out at level " << player.GetLvl() << endl 
            <<"Which has " << player.GetHealth() << " health points, " 
            << player.GetStamina() << " stamina points, and " 
            << player.GetSkillTree_Points() << " skilltree points" << endl
            << "every level you get an additional 5 health/stamina points, "
            << "and you get a skilltree point" << endl << endl;
    cout << "Press 1, then hit Enter to level up : ";
    cin >> t;
    cout << endl;
    while (t == "1"){
        player.IncrementPlayerLvl();
        cout << "You are now level " << player.GetLvl() << endl 
                <<"Which has " << player.GetHealth() << " health points, "
                << player.GetStamina() << " stamina points, and " 
                << player.GetSkillTree_Points()  << " skilltree points." << endl;
        cout << "Press 1, then hit Enter to level up, anything else "
                << "will end the program : ";
        cin >> t;
        cout << endl << endl;
    }
    EntityT* EntityPrt = &player; 
    cout << "Entity Prts to players name is : " << EntityPrt->GetName();
}
void BuildNPC(string n, string t){
    cout << "What is the NPC's name? ";
    getline(cin,n);
    cout << "What is " << n << "'s race?" << endl 
            << "You can choose Altmer, Argorian, Brenton, Dunmer, Imperial, "
            << "Khajiit, Nord, Orsimer, Redguard?: ";
    cin >> t;
    cout << endl;
    NPCT npc(n, t);
    cout << "A npc has been made with the name " << npc.GetName()
            << " and is an " << npc.GetRace() << ":" << endl << endl;

    cout << "This NPC start out at level " << npc.GetLvl() << endl;
    cout << "Press 1, then hit Enter to level up : ";
    cin >> t;
    cout << endl;

    while (t == "1"){
        npc.IncrementLvl();
        cout << "The NPC is now level " << npc.GetLvl() << endl;
        cout << "Press 1, then hit Enter to level up, anything else "
                << "will end the program : ";
        cin >> t;
        cout << endl << endl;
    }
}
void BuildCreature(string n, string t){
    cout << "What is the Creatures name?: ";
    getline(cin,n);
    cout << "What type of creature?: ";
    cin >> t;
    cout << endl;
    CreatureT creature(n, t);
    cout << "A creature has been made with the name " << creature.GetName()
            << " and is an " << creature.GetCreatureType() << ":" << endl
            << endl;

    cout << "It starts out at level " << creature.GetLvl() << endl 
            << "Press 1, then hit Enter to level up : ";
    cin >> t;
    cout << endl;
    while (t == "1"){
        creature.IncrementLvl();
        cout << "The creature is now level " << creature.GetLvl() << endl;
        cout << "Press 1, then hit Enter to level up, anything else "
                << "will end the program : ";
        cin >> t;
        cout << endl << endl;
    }
}