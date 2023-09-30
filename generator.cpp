#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;



struct charecter{
    char gender;
    string race;
    string clas;
};
class generate{
    public:
        charecter generator(charecter item){
            srand ( time(NULL) );
            string race[15]= {"Dragonborn","Dwarf","Elf","Gnome","Half-Elf","Half-Orc","Halfling","Human","Tiefling","Kobold","Satyr","Aarakocra","Lizardfolk","Yuan-Ti","Owlin"};
            string clas[13]= {"Artificer","Barbarian","Bard","Cleric","Druid","Fighter","Monk","Paladin","Ranger","Rogue","Sorcerer","Warlock","Wizard"};
            if (rand()%2==0){
                item.gender='M';
            }
            else{
                item.gender='F';
            }
            item.race=race[rand()%15];
            item.clas=clas[rand()%13];
            return item;
    }
};

int main(){
    char select;
    charecter item;
    generate gen;
    do{
        cout<<"generating a charecter...";
        item=gen.generator(item);
        cout<<item.gender<<"\n"<<item.race<<"\n"<<item.clas<<"\n";
        cout<<"Generate again? Y N\n";
        cin>>select;
    }
    while(select!='N');

    cout<<"Please enter output file.\n";
    string name;
    cin>>name;
    ofstream file(name);
    file<<item.gender<<"\n"<<item.race<<"\n"<<item.clas<<"\n";
    file.close();
    return 0;
}