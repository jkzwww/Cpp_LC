#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

struct AreaRecord
{
    int level;
    std::string species;
    std::vector<std::string> bosses;
};

// template specialisation for hashing
// if ur not using int/string as key but custom struct
namespace std {

    template<>
    struct hash<AreaRecord>
    {
        size_t operator()(const AreaRecord& key)
        {
            return hash<int>()(key.level);
        }
    };
}

int main()
{
    std::unordered_map<std::string,AreaRecord> gameMap;

    // inserting pairs
    gameMap.emplace("Frost Forest",AreaRecord{10,"misties",{"Noel"}});
    gameMap.emplace("Dark Abyss",AreaRecord{35,"shades",{"Knight","Headless"}});
    gameMap.emplace("Cloud Bay",AreaRecord{50,"fluffies",{"Lune","Mirage"}});
    gameMap.emplace("Choco Lava",AreaRecord{80,"churros",{"Marshmallow King"}});
    
    // accessing
    std::cout << "Level required to unlock 1st area: " << gameMap["Frost Forest"].level << std::endl;

    // find key exists
    std::string target_area = "Choco Lava";
    // std::cout << "Enter target area name: ";
    // std::cin >> target_area;
    std::cout << "Searching for " << target_area << "...\n";
    if(gameMap.find(target_area) != gameMap.end()){
        std::cout << target_area << " recorded in map.\n";
    } else{
        std::cout << target_area << " does not exist in map.\n";
    }

    // erasing data pair
    gameMap.erase("Choco Lava");
    std::cout << target_area << " removed from map.\n";

    // iterate through map
    std::cout << "\n\n~~~~~Current Map~~~~~ \n";
    for(auto& AreaRec:gameMap){
        std::cout << AreaRec.first << std::endl;
        std::cout << "Level : " << AreaRec.second.level << std::endl;
        std::cout << "NPCs : " << AreaRec.second.species << "\n\n";
    }

    return 0;


}
